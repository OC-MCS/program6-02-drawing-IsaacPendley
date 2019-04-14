#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct ShapeDetail {
	ShapeEnum shape;
	float x,y;
	unsigned int color;
};


// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape {
private:
	
public:
	DrawingShape() {
		//Theres a time and place for constructing Harbert but not now
	}
	
	virtual void Draw(RenderWindow &win) = 0;
	virtual ShapeDetail getShapeDetail() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle :public DrawingShape {
private:
	CircleShape circ;
	float size;
	Vector2f pos;
	Color color;
	ShapeEnum shape;
public:
	Circle() {
		//Theres a time and place for constructing Harbert but not now
	}
	Circle(Vector2f pos,ShapeEnum shape,Color color) :DrawingShape() {
		this->pos = pos;
		this->shape = shape;
		this->color = color;
		setFillColor(color);
	}
	virtual void Draw(RenderWindow& win) {
		circ.setPosition(pos);
		circ.setRadius(size);
		circ.setOutlineThickness(4);
		circ.setOutlineColor(color);
		win.draw(circ);
	}

	float getSize()
	{
		return size; // just to make it compile 
	}

	void setFillColor(Color c) {
		circ.setFillColor(c);
	}

	void setSize(float size) {
		this->size = size;
	}

	Vector2f getPosition()
	{
		return pos; // just to make it compile 
	}

	void setPosition(Vector2f pos) {
		this->pos = pos;
	}

	Color getCurColor()
	{
		return color; // just to make it compile 
	}

	void setCurColor(Color color) {
		this->color = color;
	}

	ShapeEnum getCurShape()
	{
		return shape; // just to make it compile 
	}

	void setCurShape(ShapeEnum shape) {
		this->shape = shape;
	}

	FloatRect getGlobalBounds() {
		return circ.getGlobalBounds();
	}

	ShapeDetail getShapeDetail() {
		return {CIRCLE, pos.x,pos.y,color.toInteger()};
	}
};

class Square :public DrawingShape {
private:
	RectangleShape rect;
	float size;
	Vector2f pos;
	Color color;
	ShapeEnum shape;
public:
	Square() {
		//Theres a time and place for constructing Harbert but not now
	}
	Square(Vector2f pos, ShapeEnum shape, Color color) {
		this->pos = pos;
		this->shape = shape;
		this->color = color;
		rect.setSize(Vector2f(12.0, 12.0));
		setFill();
	}
	virtual void Draw(RenderWindow& win) {
		rect.setPosition(pos);
		rect.setOutlineThickness(4);
		rect.setOutlineColor(color);
		win.draw(rect);
	}

	float getSize() {
		return size;
	}

	void setSize(Vector2f size) {
		rect.setSize(size);
	}

	void setFillColor(Color c) {
		rect.setFillColor(c);
	}

	Vector2f getPosition()
	{
		return pos; // just to make it compile 
	}

	void setPosition(Vector2f pos) {
		this->pos = pos;
	}

	void setFill() {
		rect.setFillColor(color);
	}

	void setEmpty() {
		rect.setFillColor(Color::Transparent);
	}

	Color getCurColor()
	{
		return color; // just to make it compile 
	}

	void setCurColor(Color color) {
		this->color = color;
	}

	ShapeEnum getCurShape()
	{
		return shape; // just to make it compile 
	}

	void setCurShape(ShapeEnum shape) {
		this->shape = shape;
	}

	FloatRect getGlobalBounds() {
		return rect.getGlobalBounds();
	}

	ShapeDetail getShapeDetail() {
		return { SQUARE, pos.x,pos.y,color.toInteger() };
	}
};


