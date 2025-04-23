#pragma once
#include <iostream>

namespace math {

	template<typename T>
	class Point {
	public:
		Point() = default;
		Point(T x, T y) : x(x), y(y) {}

		Point<T> operator + (const Point<T>& other) const {
			return Point<T>(x + other.x, y + other.y);
		}

		Point<T> operator - (const Point<T>& other) const {
			return Point<T>(x - other.x, y - other.y);
		}

		Point<T> Add(const Point<T>& other) const {
			return Point<T>(x + other.x, y + other.y);
		}

		bool operator == (const Point<T>& other) const {
			return (this->x == other.x && this->y == other.y);
		}
		
		bool operator != (const Point<T>& other) const {
			return !(*this == other);
		}

		ostream& operator << (ostream& os, const Point<T>& p) {
			friend os << p.x << " " << p.y;
			return os;
		}

		T GetX() const { return x; }
		T GetY() const { return y; }

	private:
		T x = 0;
		T y = 0;
	};

	using ipoint_t = Point<int>;
	using fpoint_t = Point<float>;
}