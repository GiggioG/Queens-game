#pragma once

#include "Presenter.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "NumberDrawer.h"

#include "MenuScreen.h"
#include "Grid.h"
#include "WinScreen.h"

class World {
public:
	World();
	~World();

	GameState m_gameState = NONE;

	Presenter m_presenter;
	InputManager m_inputManager;
	TextureManager m_textureManager;
	NumberDrawer m_numberDrawer;

	MenuScreen m_menuScreen;
	Grid m_grid;
	WinScreen m_winScreen;

	void init();
	void run();
	void destroy();

	bool isRunning();

	void startGame();

	void playAgain();
	void quit();
private:
	bool m_isRunning;
};