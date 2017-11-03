#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

// 点、points[i], points[i+1]を結んだグラフのxでのy値を返す関数を返す
// pointsは左から(xが小さい順に)並べたものを入力する
std::function<float(float)> MakeFuncFromPoints(const std::vector<std::pair<float, float>>& points)
{
	return [&](float x) {
		int count = std::lower_bound(points.begin(), points.end(), std::make_pair(x, 0.0f)) - points.begin();
		if (count == 0) return points[0].second;
		if (count == points.size()) return points.back().second;
		float x1 = points[count - 1].first;
		float y1 = points[count - 1].second;
		float x2 = points[count].first;
		float y2 = points[count].second;

		return (y2 - y1) / (x2 - x1) * (x - x1) + y1;
	};
}




int main()
{

	std::vector<std::pair<float, float>> vec;
	vec.emplace_back(std::make_pair<float, float>(0.0f, 0.0f));
	vec.emplace_back(std::make_pair<float, float>(0.25f, 1.0f));
	vec.emplace_back(std::make_pair<float, float>(0.5f, 1.0f));
	vec.emplace_back(std::make_pair<float, float>(0.75f, 0.0f));
	vec.emplace_back(std::make_pair<float, float>(1.0f, 1.0f));

	auto f = MakeFuncFromPoints(vec);

	for (float x = 0.0f; x <= 1.0f + 1e-04; x += 0.05f) {
		printf("%f %f\n", x, f(x));
	}

	return 0;
}