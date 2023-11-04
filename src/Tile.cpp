#include "Tile.h"
#include "Presenter.h"
#include "TextureManager.h"

Tile::Tile(){}

Tile::~Tile(){}

void Tile::init(SDL_Rect in_rect) {
	bool hasQueen = false;
	bool isBlocked = false;

	rect = in_rect;
}

void Tile::draw(){
	Drawable dummyDrawable;
	dummyDrawable.rect = rect;
	if (!isBlocked) {
		dummyDrawable.texture = TextureManager::tile_free_texture;
	} else {
		dummyDrawable.texture = TextureManager::tile_blocked_texture;
	}
	drawObject(dummyDrawable);

	if (hasQueen) {
		dummyDrawable.texture = TextureManager::queen_texture;
		drawObject(dummyDrawable);
	}
}

void Tile::drawHover() {
	Drawable dummyDrawable;
	dummyDrawable.rect = rect;
	dummyDrawable.texture = TextureManager::tile_hover_texture;
	drawObject(dummyDrawable);
}

void Tile::drawHoverBlock() {
	Drawable dummyDrawable;
	dummyDrawable.rect = rect;
	dummyDrawable.texture = TextureManager::tile_hoverBlock_texture;
	drawObject(dummyDrawable);
}

void Tile::destruct() {
	
}
