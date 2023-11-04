#include "defines.h"
#include "World.h"
#include "Grid.h"
#include "TextureManager.h"
#include "Presenter.h"

#define CURR_PLAYER "[P" << turn << "]"

extern World world;

Grid::Grid() {}
Grid::~Grid() {}

void Grid::init(int in_width, int in_height){
	D(Presenter::m_SCREEN_WIDTH);
	D(Presenter::m_SCREEN_HEIGHT);


	turn = 1;
	winner = 0;

	cols = in_width;
	rows = in_height;

	const int availWidth = Presenter::m_SCREEN_WIDTH - GAMESCREEN_SIDEBAR_SIZE;
	const int availHeight = Presenter::m_SCREEN_HEIGHT;

	horizFit = availWidth / cols;
	vertFit = availHeight / rows;
	tileDim = min(horizFit, vertFit);

	horizEmptySpace = availWidth - cols * tileDim;
	vertEmptySpace = availHeight - rows * tileDim;

	tiles = new Tile* [rows];
	for (int r = 0; r < rows; r++) {
		tiles[r] = new Tile[cols];
		for (int c = 0; c < cols; c++) {
			SDL_Rect rect = {0};
			rect.x = horizEmptySpace / 2 + c * tileDim;
			rect.y = vertEmptySpace / 2 + r * tileDim;
			rect.w = tileDim;
			rect.h = tileDim;
			tiles[r][c].init(rect);
		}
	}

	screenRect.x = horizEmptySpace / 2;
	screenRect.y = vertEmptySpace / 2;
	screenRect.w = tileDim * cols;
	screenRect.h = tileDim * rows;

	turnDrawable.rect.x = Presenter::m_SCREEN_WIDTH - GAMESCREEN_SIDEBAR_SIZE;
	turnDrawable.rect.w = GAMESCREEN_SIDEBAR_SIZE;
	turnDrawable.rect.h = turnDrawable.rect.w;
	turnDrawable.rect.y = (Presenter::m_SCREEN_HEIGHT - turnDrawable.rect.h) / 2;

	int sideButtonWidth = (int)(GAMESCREEN_SIDEBAR_SIZE/(double)BUTTON_GROW_FACTOR);
	int sideButtonHeight = sideButtonWidth / 2;

	quitButton.init(TextureManager::quit_button_texture, { -1, -1, -1, -1 }, &quitClicked);
	quitButton.rect.w = sideButtonWidth;
	quitButton.rect.h = sideButtonHeight;
	quitButton.rect.x = Presenter::m_SCREEN_WIDTH - GAMESCREEN_SIDEBAR_SIZE + (GAMESCREEN_SIDEBAR_SIZE - quitButton.rect.w) / 2;
	quitButton.rect.y = (int)(Presenter::m_SCREEN_HEIGHT - quitButton.rect.h * (1+(double)(BUTTON_GROW_FACTOR-1)/2));

	resignButton.init(TextureManager::resign_button_texture, quitButton.rect, &resignClicked);
	resignButton.rect.y = (int)(resignButton.rect.h * ((double)(BUTTON_GROW_FACTOR - 1) / 2));

	std::cout << "****************\n";
	std::cout << "*              *\n";
	std::cout << "*   NEW GAME   *\n";
	std::cout << "*              *\n";
	std::cout << "****************\n";
	std::cout << "Grid is " << rows << " rows by " << cols << " cols.\n";
}

void Grid::addQueen(int row, int col) {
	tiles[row][col].hasQueen = true;
	// orthogonals
	for (int r = 0; r < rows; r++) { tiles[ r ][col].isBlocked = true; }
	for (int c = 0; c < cols; c++) { tiles[row][ c ].isBlocked = true; }
	// diagonals
	for (int r = row, c = col; r < rows && c < cols; r++, c++) { tiles[r][c].isBlocked = true; }
	for (int r = row, c = col; r < rows && c >= 0  ; r++, c--) { tiles[r][c].isBlocked = true; }
	for (int r = row, c = col; r >= 0   && c < cols; r--, c++) { tiles[r][c].isBlocked = true; }
	for (int r = row, c = col; r >= 0   && c >= 0  ; r--, c--) { tiles[r][c].isBlocked = true; }
}

void Grid::update() {
	int r = (world.m_inputManager.m_mouseCoor.y - vertEmptySpace / 2) / tileDim;
	int c = (world.m_inputManager.m_mouseCoor.x - horizEmptySpace / 2) / tileDim;

	if (world.m_inputManager.m_mouseOnClick && CoordInRect(world.m_inputManager.m_mouseCoor, screenRect)) {
		if (!tiles[r][c].isBlocked) {
			std::cout << CURR_PLAYER << " (" << r << ", " << c << ")\n";
			addQueen(r, c);
			if (!checkEmpty()) {
				// winner!
				std::cout << CURR_PLAYER << " WON!!!\n";
				winner = turn;
			}
			else {
				changeTurn();
			}
		}
	}

	resignButton.update();
	if (resignClicked) {
		changeTurn();
		winner = turn;
	}

	quitButton.update();
}

bool Grid::hasWinner() {
	return (winner != 0);
}

void Grid::draw() {
	drawObject(TextureManager::background_texture);
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			tiles[r][c].draw();
		}
	}

	// hover
	int r = (world.m_inputManager.m_mouseCoor.y - vertEmptySpace / 2) / tileDim;
	int c = (world.m_inputManager.m_mouseCoor.x - horizEmptySpace / 2) / tileDim;
	if (CoordInRect(world.m_inputManager.m_mouseCoor, screenRect)) {
		if (!tiles[r][c].isBlocked) {
			hover(r, c);
		}
	}

	///
	/// UI
	/// 

	// turn
	if (turn == 1) {
		turnDrawable.texture = TextureManager::player1_turn_texture;
	} else if (turn == 2) {
		turnDrawable.texture = TextureManager::player2_turn_texture;
	}
	drawObject(turnDrawable);
	
	resignButton.draw();
	quitButton.draw();
}

void Grid::changeTurn() {
	if (turn == 1) { turn = 2; }
	else if(turn == 2) { turn = 1; }
}

bool Grid::checkEmpty() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (!tiles[r][c].isBlocked) { return true; }
		}
	}
	return false;
}

void Grid::hover(int row, int col) {
	tiles[row][col].drawHover();
	for (int r = 0; r < rows; r++) { hoverBlockTileIfEmptyAndNotHovered(row, col, r, col); }
	for (int c = 0; c < cols; c++) { hoverBlockTileIfEmptyAndNotHovered(row, col, row, c); }
	// diagonals
	for (int r = row, c = col; r < rows && c < cols; r++, c++) { hoverBlockTileIfEmptyAndNotHovered(row, col, r, c); }
	for (int r = row, c = col; r < rows && c >= 0; r++, c--) { hoverBlockTileIfEmptyAndNotHovered(row, col, r, c); }
	for (int r = row, c = col; r >= 0 && c < cols; r--, c++) { hoverBlockTileIfEmptyAndNotHovered(row, col, r, c); }
	for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) { hoverBlockTileIfEmptyAndNotHovered(row, col, r, c); }
}

void Grid::hoverBlockTileIfEmptyAndNotHovered(int hovR, int hovC, int row, int col) {
	if (row == hovR && col == hovC) { return; }
	if (tiles[row][col].isBlocked == true) { return; }
	tiles[row][col].drawHoverBlock();
}

void Grid::destruct() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			tiles[r][c].destruct();
		}
		delete[] tiles[r];
	}
	delete[] tiles;
	quitButton.destruct();
}