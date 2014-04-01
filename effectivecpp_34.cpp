/*************************************************
File: explicit.cpp
Copyright: C.L.Wang
Author: C.L.Wang
Date: 2014-04-01
Description: explicit
Email: morndragon@126.com
**************************************************/

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

using namespace std;

class Shape {
public:
	virtual void draw() const;
	virtual void error (const std::string& msg) {std::cout << msg << std::endl;};
	int objectID() const { return 1;};
};

void Shape::draw() const {
	std::cout << "Shape Draw!" << std::endl;
}

class Rectangle: public Shape {
public:
	void draw() const {std::cout << "Rect Draw!" << std::endl;};
};
class Ellipse: public Shape {
public:
	void draw() const {std::cout << "Elli Draw!" << std::endl;};
};

int main () {
	Shape* ps1 = new Rectangle;
	Shape* ps2 = new Ellipse;
	ps1->draw();
	ps2->draw();
	std::cout << "Attention: " << std::endl;
	ps1->Shape::draw();
	ps2->Shape::draw();
	return 0;
}





