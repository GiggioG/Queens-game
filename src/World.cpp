#include "World.h"
#include "defines.h"

extern World world;

World::World(){ m_isRunning = true; }

World::~World() {}

void World::init(){
	m_gameState = MENU;
	m_presenter.init();
	m_textureManager.init();
	m_numberDrawer.init();

	m_menuScreen.init();
}

void World::run(){
	m_inputManager.handleInput();

	if (m_gameState == MENU) {
		m_menuScreen.update();
		m_menuScreen.draw();
		if (m_menuScreen.playClicked) {
			startGame();
		} else if (m_menuScreen.quitClicked) {
			quit();
		}
	} else if (m_gameState == PLAYING) {
		m_grid.update();
		m_grid.draw();
		if (m_grid.hasWinner()) {
			m_gameState = WINSCREEN;
			m_winScreen.destruct();
			m_winScreen.init(m_grid.winner);
			m_grid.destruct();
		} else if (m_grid.quitClicked) {
			m_gameState = MENU;
		}
	} else if (m_gameState == WINSCREEN) {
		m_winScreen.update();
		m_winScreen.draw();
		if (m_winScreen.playAgainClicked) {
			m_gameState = MENU;
		} else if (m_winScreen.quitClicked) {
			quit();
		}
	}

	m_presenter.draw();
}

// call destroy for all classes to prevent memory leak
void World::destroy(){
	m_textureManager.destruct();
	m_numberDrawer.destruct();

	m_grid.destruct();
	m_winScreen.destruct();

	SDL_DestroyRenderer(m_presenter.m_main_renderer);
	SDL_DestroyWindow(m_presenter.m_main_window);
}

bool World::isRunning(){
	return m_isRunning;
}

void World::startGame() {
	m_gameState = PLAYING;
	m_grid.init(m_menuScreen.gridWidth, m_menuScreen.gridHeight);
}

void World::quit() {
	m_isRunning = false;
	std::cout << "Game quit!\n";
	exit(0);
}