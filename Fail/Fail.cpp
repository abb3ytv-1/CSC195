#include <iostream>
#include <vector>

using namespace std;


class Shape {
public:
	Shape() {}
	~Shape() {}
	float Area();
};


class Circle : public Shape {
public:
	Circle(float r) { m_radius = r }
	~Circle() {}
	float Area() override {
		return 3.14f * m_radius * m_radius;
	}
	void SetRadius(float radius) const { radius = radius; }
	float GetRadius() { return m_radius; }
private:
	float m_radius;
};

class Rectangle : public Shape {
public:
	Rectangle(float w, float h) {
		m_width = w;
		m_height = h;
	}
	float Areas() override {
		return m_width * m_height;
	}
private:
	float m_width;
	float m_height;
};


int main() {
	vector<Shape*> shapes;
	Circle c = new Circle(1.0f);
	c.SetRadius(3.0f);
	Rectangle* r = new Rectangle(4.0f, 5.0f)
		shapes.push_back(c);
	shapes.push_back(r);
	for (int i = 0; i <= shapes.size(); i++)
	{
		cout << "Area: " << shapes[i]->Area() << endl;
		// TODO: If shape is a circle, print radius
	}
	// FIXME: Getting memory leak! Delete all shapes.
	return 0;
}
