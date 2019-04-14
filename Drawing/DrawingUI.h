#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:

public:
	DrawingUI(Vector2f p)
	{

	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*>* shapes = mgr->getshapes();
		for (int i = 0; i < shapes->size(); i++) {
			(*shapes)[i]->Draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool onCanv = true;
		if (mousePos.x > 800 || mousePos.x < 200 || mousePos.y > 600 || mousePos.y < 0)
		{
			onCanv = false;
		}
		return onCanv;
	}

};

