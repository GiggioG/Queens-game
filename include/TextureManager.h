#pragma once

#include "defines.h"

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* background_texture;
	static SDL_Texture* menuBackground_overlay_texture;

	static SDL_Texture* slider_body_texture;
	static SDL_Texture* slider_thumb_texture;

	static SDL_Texture* play_button_texture;
	static SDL_Texture* playAgain_button_texture;
	static SDL_Texture* quit_button_texture;
	static SDL_Texture* resign_button_texture;

	static SDL_Texture* tile_free_texture;
	static SDL_Texture* tile_hover_texture;
	static SDL_Texture* tile_hoverBlock_texture;
	static SDL_Texture* tile_blocked_texture;
	static SDL_Texture* queen_texture;
	static SDL_Texture* player1_turn_texture;
	static SDL_Texture* player2_turn_texture;

	static SDL_Texture* winscreen_player1won_texture;
	static SDL_Texture* winscreen_player2won_texture;

	void init();
	void destruct();
};