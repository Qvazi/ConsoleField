#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "field.hpp"
#include "snake.hpp"
#include "score.hpp"

class Game
{
public:
	enum { START_SPEED_GAME = 200, SPEED_PER_LEVEL = 15 };
private:
	Field field_;
	Snake snake_;
	Score score_;
	int speedGame;
public:
	Game();
	void draw();
	int getSpeedGame() const;
	void keyEvent(Snake::Direction d);
	void update();
};
#endif