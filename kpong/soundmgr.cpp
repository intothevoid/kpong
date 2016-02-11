#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include "soundmgr.h"

// Audio
char* FX_HIT = "fx\\ball-hit.wav";
char* FX_MISS = "fx\\ball-miss.wav";
char* FX_WALL = "fx\\ball-wall.wav";
char* FX_INTRO = "fx\\kpong-intro.wav";

SoundMgr::SoundMgr()
{
}


SoundMgr::~SoundMgr()
{
}

void SoundMgr::playIntro()
{
	playSound("C:\\git\\kpong\\kpong\\fx\\kpong-intro.wav");
}

bool SoundMgr::playSound(char* soundfile)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return false;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		return false;
	}

	Mix_Chunk* snd = Mix_LoadWAV(soundfile);

	Mix_PlayChannel(-1, snd, 0);

	const char* err = Mix_GetError();

	Mix_FreeChunk(snd);
	Mix_Quit();

	return true;
}
