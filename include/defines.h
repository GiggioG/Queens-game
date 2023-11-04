#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <SDL.h>

#include "config.h"

using namespace std;

#define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
#define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
#define __FILE_NAME__ (strrchr(__FILE__, '\\' ) ? strrchr(__FILE__, '\\') + 1 : __FILE__)

static string MENU_FOLDER = "menu\\";
static string MAIN_FOLDER = "main\\";
static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string FONT_FOLDER = "ttf\\";
static string SOUND_FOLDER = "music\\";
static string TITLE_SCREEN_FOLDER = "titleScreen\\";
static string WIN_SCREEN_FOLDER = "winScreen\\";
static string GAME_FOLDER = "game\\";

struct int2 {
    int x = 0;
    int y = 0;
};

struct float2
{
    float x = 0;
    float y = 0;
};

enum class SOUND
{
    NONE = 0,
    BACKGROUND = 1
};

struct Drawable{
    SDL_Texture* texture = nullptr;
    SDL_Rect rect = { 0 }; /// The rect where we draw
};

enum GameState {
    NONE = 0,
    MENU = 1,
    PLAYING = 2,
    WINSCREEN = 3
};