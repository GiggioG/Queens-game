#pragma once

#include "Button.h"
#include "defines.h"

class WinScreen {
public:
	WinScreen();
	~WinScreen();

	int winner = 0;
	Drawable winnerBanner;
	Button playAgainButton, quitButton;
	bool playAgainClicked = false, quitClicked = false;

	void init(int winner);
	void update();
	void draw();
	void destruct();
};