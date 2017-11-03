#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

// �_�Apoints[i], points[i+1]�����񂾃O���t��x�ł�y�l��Ԃ��֐���Ԃ�
// points�͍�����(x������������)���ׂ����̂���͂���
std::function<float(float)> MakeFuncFromPoints(const std::vector<std::pair<float, float>>& points)
{
	return [&](float x) {
		int count = 0;
		for (const auto& i : points) {
			if (x < i.first - 1e-04) {
				break;
			}
			count++;
		}
		count = std::min(count, (int)points.size()-1);
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