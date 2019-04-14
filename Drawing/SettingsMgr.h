#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color colour;
	ShapeEnum shape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		colour = startingColor;
		shape = startingShape;
	}

	Color getCurColor()
	{
		return colour; // just to make it compile 
	}

	void setCurColor(Color colour) {
		this->colour = colour;
	}

	ShapeEnum getCurShape()
	{
		return shape; // just to make it compile;
	}

	void setCurShape(ShapeEnum shape) {
		this->shape = shape;
	}

	void readSetting(fstream& file) {
		unsigned int tempColor;
		file.read(reinterpret_cast<char*>(&tempColor),sizeof(tempColor));
		file.read(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
		colour = Color(tempColor);
	}

	void writeSetting(fstream& file) {
		unsigned int tempColor = colour.toInteger();
		file.write(reinterpret_cast<char*>(&tempColor), sizeof(tempColor));
		file.write(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
	}
};
