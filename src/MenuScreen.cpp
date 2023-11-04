#include "MenuScreen.h"
#include "Presenter.h"
#include "TextureManager.h"
#include "World.h"
#include "Button.h"

extern World world;

MenuScreen::MenuScreen() {}

MenuScreen::~MenuScreen() {}

void MenuScreen::init() {
	gridWidth = GRID_WIDTH;
	gridHeight = GRID_HEIGHT;

	playButton.init(TextureManager::play_button_texture, { 532, 900, 256, 128 }, &playClicked);
	quitButton.init(TextureManager::quit_button_texture, { 1132, 900, 256, 128 }, &quitClicked);
	rowSlider.init({ 825, 335 }, 200, 4, 100, gridHeight);
	colSlider.init({ rowSlider.rect.x, rowSlider.rect.y + 90 }, 200, 4, 100, gridWidth);
}

void MenuScreen::update() {
	playButton.update();
	quitButton.update();

	rowSlider.update();
	gridHeight = rowSlider.val;
	colSlider.update();
	gridWidth = colSlider.val;
}

void MenuScreen::draw() {
	drawObject(TextureManager::background_texture);
	drawObject(TextureManager::menuBackground_overlay_texture);

	drawObject(winnerBanner);

	playButton.draw();
	quitButton.draw();
	rowSlider.draw();
	colSlider.draw();
}

void MenuScreen::destruct() {
	playButton.destruct();
	quitButton.destruct();
	rowSlider.destruct();
	colSlider.destruct();
}
