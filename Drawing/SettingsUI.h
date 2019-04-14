#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	Circle buttonG;
	Circle buttonB;
	Circle buttonR;
	Circle circButton;
	Square squButton;
	Square panel;
	SettingsMgr *mgr;
public:

	// Parametric Constructor
	SettingsUI(SettingsMgr *mgr) 
	{
		this->mgr = mgr;
		panel.setCurColor(Color::White);
		panel.setCurShape(SQUARE);
		panel.setPosition(Vector2f(0, 0));
		panel.setSize(Vector2f(200,600));

		circButton.setCurColor(Color::Black);
		circButton.setCurShape(CIRCLE);
		circButton.setPosition(Vector2f(50,200));
		circButton.setSize(20);

		squButton.setCurColor(Color::Black);
		squButton.setCurShape(SQUARE);
		squButton.setPosition(Vector2f(110, 200));
		squButton.setSize(Vector2f(40, 40));

		buttonG.setCurColor(Color::Green);
		buttonG.setCurShape(CIRCLE);
		buttonG.setPosition(Vector2f(80, 350));
		buttonG.setSize(20);

		buttonB.setCurColor(Color::	Blue);
		buttonB.setCurShape(CIRCLE);
		buttonB.setPosition(Vector2f(80, 425));
		buttonB.setSize(20);

		buttonR.setCurColor(Color::Red);
		buttonR.setCurShape(CIRCLE);
		buttonR.setPosition(Vector2f(80, 500));
		buttonR.setSize(20);
	}

	// Checks if mouse clicks interacted with UI
	void handleMouseUp(Vector2f mouse)
	{
		// Check if the mouse clicked a settings button
		// Activate that setting and update the UI if they do
		if (buttonR.getGlobalBounds().contains(mouse)) {
			mgr->setCurColor(Color::Red);
		}
		else if (buttonG.getGlobalBounds().contains(mouse)) {
			mgr->setCurColor(Color::Green);
		}
		else if (buttonB.getGlobalBounds().contains(mouse)) {
			mgr->setCurColor(Color::Blue);
		}
		else if (squButton.getGlobalBounds().contains(mouse)) {
			mgr->setCurShape(SQUARE);
		}
		else if (circButton.getGlobalBounds().contains(mouse)) {
			mgr->setCurShape(CIRCLE);
		}
	}

	// Draws all the shapes and text for the UI
	void draw(RenderWindow& win)
	{
		buttonG.setFillColor(Color::Transparent);
		buttonR.setFillColor(Color::Transparent);
		buttonB.setFillColor(Color::Transparent);
		squButton.setFillColor(Color::Transparent);
		circButton.setFillColor(Color::Transparent);
		//settings size x200 y600
		if (mgr->getCurColor() == Color::Green)
		{
			buttonG.setFillColor(Color::Green);
		}
		else if (mgr->getCurColor() == Color::Red)
		{
			buttonR.setFillColor(Color::Red);
		}
		else if (mgr->getCurColor() == Color::Blue)
		{
			buttonB.setFillColor(Color::Blue);
		}
		if (mgr->getCurShape() == SQUARE)
		{
			squButton.setFillColor(Color::Black);
		}
		else if (mgr->getCurShape() == CIRCLE)
		{
			circButton.setFillColor(Color::Black);
		}

		// Get the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			die("Couldn't load font");
		}

		panel.Draw(win);
		circButton.Draw(win);
		squButton.Draw(win);
		buttonG.Draw(win);
		buttonB.Draw(win);
		buttonR.Draw(win);


		// Draw the brush selector
		Text shapeText("Drawing Shape", font, 25);
		shapeText.setFillColor(Color::Black);
		shapeText.setPosition(20, 150);
		win.draw(shapeText);
		
		// Draw the color selector
		Text colorText("Drawing Color", font, 25);
		colorText.setFillColor(Color::Black);
		colorText.setPosition(20, 300);
		win.draw(colorText);
	}

	void die(string msg) {
		// Exits if the program fails
		cout << msg << endl;
		exit(-1);
	}
};
