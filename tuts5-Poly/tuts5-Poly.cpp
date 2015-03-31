// tuts5-Poly.cpp : Defines the entry point for the console application.
//

//211543957
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
	float *dimensions;
	string name;
	int no_of_sides;
	void setName(string n)
	{
		name = n;
	}
public:
	static const float PI;
	void Shape::printName() const
	{
		cout << "This shape is a " << name << endl;
	}
	void setDims(float *sizes)
	{
		dimensions = sizes;
		no_of_sides = sizeof(sizes) / sizeof(float);
	}
	virtual float getArea() const
	{
		cout << "Area is the region enclosed by the shape." << endl;
		return -1;
	}
	Shape()
	{
		name = "general shape";
		no_of_sides = 0;
	}
};

const float Shape::PI = atan(1) * 4;

class Triangle : public Shape
{
public:
	Triangle()
	{
		setName("triangle");
	}
	Triangle(float *sizes)
	{
		setName("triangle");
		Shape::setDims(sizes);
	}
	virtual float getArea() const
	{
		//utilise Heron's formula
		float a = *(dimensions),
			b = *(dimensions + 1),
			c = *(dimensions + 2),
			s = (a + b + c) / 2;

		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
};

class Circle : public Shape
{
public:
	Circle()
	{
		setName("circle");
	}
	Circle(float *radius)
	{
		setName("circle");
		Shape::setDims(radius);
	}
	virtual float getArea() const
	{
		return Shape::PI * pow((*dimensions), 2);
	}
};

class Rectangle : public Shape
{
public:
	Rectangle()
	{
		setName("rectangle");
	}
	Rectangle(float *sizes)
	{
		setName("rectangle");
		Shape::setDims(sizes);
	}
	virtual float getArea() const
	{
		return (*dimensions) * (*(dimensions + 1));
	}
};

main()
{
	float triangleDims[] = { 10, 7, 8 }, //3 sides define triangle
		rectangleDims[] = { 9, 6 }, //due to equality of opposite sides, 2 sides define rectangle
		circleRadius = 1;//circle defined by length of radius

	Triangle t;
	t.setDims(triangleDims);//to illustrate public setDims() method

	Rectangle r(rectangleDims);

	Circle c(&circleRadius);

	cout << "Shape 1: " << endl;
	t.printName();
	cout << endl << "Shape 2: " << endl;
	r.printName();
	cout << endl << "Shape 3: " << endl;
	c.printName();

	Shape *myShapes[] = { &t, &r, &c },
		**shapePtr = myShapes;

	cout << endl << "The areas of the shapes are: " << endl;

	for (int i = 0; i<3; ++i)
	{
		cout << "The area of Shape " << 1 + i << " is: " << (*(shapePtr + i))->getArea() << endl;
	}
	system("pause");
}
