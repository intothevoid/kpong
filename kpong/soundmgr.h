#pragma once

class SoundMgr
{
public:
	SoundMgr();
	~SoundMgr();
	void playIntro();
	void playBallHit();
	void playBallMiss();
	void playWallHit();

private:
	bool playSound(char* soundfile);

};

