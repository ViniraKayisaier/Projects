

#include <iostream>
#include <string>

class Polygon {

public:
	Polygon(double dWidth, double dHeight);
	virtual ~Polygon();
	virtual double area() = 0; // Pure virtual member function - no implementation in base class
	virtual void displayProperties();

protected:
	double m_dWidth;
	double m_dHeight;
	std::string m_strType;
};

Polygon::Polygon(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Polygon")
{

}

Polygon::~Polygon()
{
	std::cout << "Polygon Destructor called" << std::endl;
}

void Polygon::displayProperties()
{
	std::cout << "Polygon Type: " << this->m_strType << ", Width: " << this->m_dWidth << ", Height: " << this->m_dHeight << std::endl;
	return;
}


class Rectangle : public Polygon
{
public:
	Rectangle(double dWidth, double dHeight);
	~Rectangle();
	double area();
};

Rectangle::Rectangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle Destructor called" << std::endl;
}

double Rectangle::area()
{
	return (this->m_dHeight * this->m_dWidth);
}


{
public:
	Triangle(double dWidth,double dHeight);
	~Triangle();
	double area();
};


Triangle::Triangle(double dWidth,double dHeight):Polygon(dWidth,dHeight)
{
	this->m_strType ="Triangle";
}


Triangle::~Triangle()
{
	std::cout << "Triangle Destructor called" << std::endl;
}


double Triangle::area()
{
	return (0.5 * this->m_dHeight * this->m_dWidth);
}

int main()
{
	Polygon* p_polygonRectangle = new Rectangle(2.0, 4.0);
	Polygon*p_polygonTriangle = new Triangle(3.0,6.0);
	Polygon* p_polygon[2]; 

	p_polygon[0] = p_polygonRectangle;
	
	p_polygon[1] = p_polygonTriangle;
	
	for (int i = 0; i < 2; i++)
	{
		// Polymorphic invocation
		p_polygon[i]->displayProperties(); // take advantage of reuse; use base class function
		double dArea = p_polygon[i]->area();
		std::cout << "Area: " << dArea << std::endl;
	}

	delete p_polygonRectangle;
	delete p_polygonTriangle;
	return 0;
}
