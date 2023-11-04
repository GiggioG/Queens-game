#include "TextureManager.h"
#include "Presenter.h"

SDL_Texture* TextureManager::background_texture = nullptr;
SDL_Texture* TextureManager::menuBackground_overlay_texture = nullptr;

SDL_Texture* TextureManager::slider_body_texture = nullptr;
SDL_Texture* TextureManager::slider_thumb_texture = nullptr;

SDL_Texture* TextureManager::play_button_texture = nullptr;
SDL_Texture* TextureManager::playAgain_button_texture = nullptr;
SDL_Texture* TextureManager::quit_button_texture = nullptr;
SDL_Texture* TextureManager::resign_button_texture = nullptr;

SDL_Texture* TextureManager::tile_free_texture = nullptr;
SDL_Texture* TextureManager::tile_hover_texture = nullptr;
SDL_Texture* TextureManager::tile_hoverBlock_texture = nullptr;
SDL_Texture* TextureManager::tile_blocked_texture = nullptr;
SDL_Texture* TextureManager::queen_texture = nullptr;
SDL_Texture* TextureManager::player1_turn_texture = nullptr;
SDL_Texture* TextureManager::player2_turn_texture = nullptr;

SDL_Texture* TextureManager::winscreen_player1won_texture = nullptr;
SDL_Texture* TextureManager::winscreen_player2won_texture = nullptr;

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

void TextureManager::init() {
	background_texture = loadTexture(BACKGROUND_BMP);
	menuBackground_overlay_texture = loadTexture(MENU_BACKGROUND_OVERLAY_BMP);

	slider_body_texture = loadTexture(SLIDER_BODY_BMP);
	slider_thumb_texture = loadTexture(SLIDER_THUMB_BMP);

	play_button_texture = loadTexture(PLAY_BUTTON_BMP);
	playAgain_button_texture = loadTexture(PLAYAGAIN_BUTTON_BMP);
	quit_button_texture = loadTexture(QUIT_BUTTON_BMP);
	resign_button_texture = loadTexture(RESIGN_BUTTON_BMP);

	tile_free_texture = loadTexture(TILE_FREE_BMP);
	tile_hover_texture = loadTexture(TILE_HOVER_BMP);
	tile_hoverBlock_texture = loadTexture(TILE_HOVERBLOCK_BMP);
	tile_blocked_texture = loadTexture(TILE_BLOCKED_BMP);
	queen_texture = loadTexture(QUEEN_BMP);
	player1_turn_texture = loadTexture(PLAYER1_TURN_BMP);
	player2_turn_texture = loadTexture(PLAYER2_TURN_BMP);

	winscreen_player1won_texture = loadTexture(WINSCREEN_PLAYER1WON_BMP);
	winscreen_player2won_texture = loadTexture(WINSCREEN_PLAYER2WON_BMP);
}

void TextureManager::destruct() {
	SDL_DestroyTexture(background_texture);
	SDL_DestroyTexture(menuBackground_overlay_texture);

	SDL_DestroyTexture(slider_body_texture);
	SDL_DestroyTexture(slider_thumb_texture);

	SDL_DestroyTexture(play_button_texture);
	SDL_DestroyTexture(playAgain_button_texture);
	SDL_DestroyTexture(quit_button_texture);
	SDL_DestroyTexture(resign_button_texture);

	SDL_DestroyTexture(tile_free_texture);
	SDL_DestroyTexture(tile_hover_texture);
	SDL_DestroyTexture(tile_hoverBlock_texture);
	SDL_DestroyTexture(tile_blocked_texture);
	SDL_DestroyTexture(queen_texture);
	SDL_DestroyTexture(player1_turn_texture);
	SDL_DestroyTexture(player2_turn_texture);

	SDL_DestroyTexture(winscreen_player1won_texture);
	SDL_DestroyTexture(winscreen_player2won_texture);
}