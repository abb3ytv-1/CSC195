#include "Circle.h"

using namespace std;

Circle::Circle(float r) : m_radius(r) {}

float Circle::Area() {
	return 3.14f * m_radius * m_radius;
}

void Circle::SetRadius(float r)
{
	m_radius = r;
}

float Circle::GetRadius() {
	return m_radius;
}

