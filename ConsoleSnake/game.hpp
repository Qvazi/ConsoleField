#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "field.hpp"
#include "snake.hpp"
#include "score.hpp"

class Game
{
public:
	enum { START_SPEED_GAME = 270, SPEED_PER_LEVEL = 20 };
	enum Difficulty { EASY , MEDIUM , HARD };
	static bool SOUND;
	static bool PAUSE;
private:
	Field field_;
	Snake snake_;
	Score score_;
	int speedGame;
	Difficulty difficulty_;
public:
	Game();

	void draw();
	int getSpeedGame() const;
	Field & getField();
	Score & getScore();
	void drawBorder() const;
	void drawScore() const;
	void redrawScore() const;
	Difficulty getDiffuculty() const;
	void keyEvent(Snake::Direction d);
	void update();
};
#endif
