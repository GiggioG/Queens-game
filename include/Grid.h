#pragma once

#include "defines.h"
#include "Tile.h"
#include "Button.h"

class Grid {
public:
	Grid();
	~Grid();

	int cols = -1, rows = -1;
	int turn;
	int winner;
	bool quitClicked;

	void init(int in_width, int in_height);
	void update();
	bool hasWinner();
	void draw();
	void destruct();

private:
	Tile** tiles = nullptr;
	int horizFit, vertFit;
	int tileDim;
	int horizEmptySpace, vertEmptySpace;
	SDL_Rect screenRect;
	Drawable turnDrawable;
	bool resignClicked;
	Button quitButton, resignButton;

	void addQueen(int row, int col);
	void changeTurn();
	bool checkEmpty();
	void hoverBlockTileIfEmptyAndNotHovered(int hovR, int hovC, int row, int col);
	void hover(int row, int col);
};