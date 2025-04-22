#pragma once

class Shape {
public:
	Shape() {}
	virtual ~Shape() = default;
	virtual float Area() = 0;
};