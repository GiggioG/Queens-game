#pragma once

#include "Button.h"
#include "Slider.h"
#include "defines.h"

class MenuScreen {
public:
	MenuScreen();
	~MenuScreen();

	int gridWidth = -1, gridHeight = -1;
	Drawable winnerBanner;
	Button playButton, quitButton;
	Slider rowSlider, colSlider;
	bool playClicked = false, quitClicked = false;

	void init();
	void update();
	void draw();
	void destruct();
};