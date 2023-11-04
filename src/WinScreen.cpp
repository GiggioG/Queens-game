#include "WinScreen.h"
#include "Presenter.h"
#include "TextureManager.h"
#include "World.h"
#include "Button.h"

extern World world;
extern void world_quit();
extern void world_startGame();

WinScreen::WinScreen() {}
WinScreen::~WinScreen() {}

void WinScreen::init(int in_winner) {
	winner = in_winner;
	winnerBanner.rect = { 704, 200, 512, 256 };
	if (winner == 1) {
		winnerBanner.texture = TextureManager::winscreen_player1won_texture;
	} else if (winner == 2) {
		winnerBanner.texture = TextureManager::winscreen_player2won_texture;
	}

	playAgainButton.init(TextureManager::playAgain_button_texture, { 532, 900, 256, 128 }, &playAgainClicked);
	quitButton.init(TextureManager::quit_button_texture, { 1132, 900, 256, 128 }, &quitClicked);
}

void WinScreen::update() {
	playAgainButton.update();
	quitButton.update();
}

void WinScreen::draw() {
	drawObject(TextureManager::background_texture);

	drawObject(winnerBanner);

	playAgainButton.draw();
	quitButton.draw();
}

void WinScreen::destruct() {
	playAgainButton.destruct();
	quitButton.destruct();
}
