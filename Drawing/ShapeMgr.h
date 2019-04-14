#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle* c = new Circle(pos,whichShape,color);
			c->setSize(5.0f);
			shapes.push_back(c);
		}
		else {
			Square* s = new Square(pos, whichShape, color);
			shapes.push_back(s);
		}
	}

	void readShapes(fstream& file) {
		ShapeDetail temp;
		while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
			addShape(Vector2f(temp.x,temp.y),temp.shape,Color(temp.color));
		}
	}

	void writeShapes(fstream& file) {
		for (int i = 0; i < shapes.size(); i++) {
			file.write(reinterpret_cast<char*>(&shapes[i]->getShapeDetail()), sizeof(ShapeDetail));
		}
	}

	vector<DrawingShape*>* getshapes() {
		return &shapes;
	}
};
