#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "field.hpp"
#include "snake.hpp"
#include "score.hpp"

class Game
{
private:
	Field field_;
	Snake snake_;
	Score score_;
public:
	void draw();
	void keyEvent(Snake::Direction d);
	void update();
};
#endif