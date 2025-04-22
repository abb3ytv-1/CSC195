#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
	explicit Circle(float r);
	float Area() override;
	void SetRadius(float r) ;
	float GetRadius();

private:
	float m_radius;
};