#pragma once

enum gwo_type { player, ai, ball };

const int PADDLE_SPEED = 2;
const int MOVE_STEP = 20;
const int PADDING = 10;
const int PLAYER_HEIGHT = 100;
const int PLAYER_WIDTH = 20;
const int AI_HEIGHT = 100;
const int AI_WIDTH = 20;
const int BALL_SIDE = 20;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;
const int SEED_LOW = -10;
const int SEED_HIGH = 10;
const int FPS = 60;

// Keyboard constants
// Scancodes from SDL_keyboard.h
const int KEY_UP = 82;
const int KEY_DOWN = 81;
const int KEY_w = 26;
const int KEY_s = 22;

