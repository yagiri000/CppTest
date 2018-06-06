#include <iostream>

constexpr
int MyPow(int base, int exp) noexcept
{
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

class Point {
public:
	constexpr Point(double xVal = 0, double yVal = 0) noexcept
		: x(xVal), y(yVal)
	{}

	constexpr double xValue() const noexcept { return x; }
	constexpr double yValue() const noexcept { return y; }

	constexpr void setX(double newX) noexcept  // C++14
	{
		x = newX;
	}

	constexpr void setY(double newY) noexcept  // C++14
	{
		y = newY;
	}

private:
	double x, y;
};

constexpr Point
midpoint(const Point& p1, const Point& p2) noexcept
{
	return { (p1.xValue() + p2.xValue()) / 2,    // call constexpr
		(p1.yValue() + p2.yValue()) / 2 };  // member funcs
}

// return reflection of p with respect to the origin (C++14)
constexpr Point reflection(const Point& p) noexcept
{
	Point result;               // creat non-const Point

	result.setX(-p.xValue());   // set its x and y values
	result.setY(-p.yValue());

	return result;              // return copy of it
}



void main() {
	constexpr int hoge = MyPow(10, 5);
	int hoge[MyPow(10, 2)];

	constexpr Point p1(10.0, 20.0);
	constexpr Point p2(40.0, 50.0);
	constexpr double a = p1.xValue();
	constexpr Point p3 = midpoint(p1, p2);

}