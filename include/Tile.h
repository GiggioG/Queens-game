#pragma once

#include "defines.h"

struct Tile {
public:
    Tile();
    ~Tile();

    SDL_Rect rect = {0};
    bool hasQueen = false;
    bool isBlocked = false;

    void init(SDL_Rect in_rect);
    void draw();
    void drawHover();
    void drawHoverBlock();
    void destruct();
};