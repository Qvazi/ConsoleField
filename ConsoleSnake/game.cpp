#include <iostream>
#include "game.hpp"

Game::Game()
{
	snake_ = Snake();
	field_ = Field();
	score_ = Score();
	speedGame = START_SPEED_GAME;
}
void Game::draw()
{
	field_.draw(snake_);
	std::cout << "Level: " << score_.getLevel()
				<< " Score: " << score_.getScore() << std::endl;
}
void Game::keyEvent(Snake::Direction d)
{
	snake_.keyEvent(d);
}
void Game::update()
{
	if(!snake_.update(field_,score_))
	{
		snake_ = Snake();
		field_ = Field();
		score_ = Score();
		speedGame = START_SPEED_GAME;
	}
	if((speedGame - score_.getLevel()*SPEED_PER_LEVEL) <= 30)
		speedGame = 50;
	else speedGame = START_SPEED_GAME - score_.getLevel()*SPEED_PER_LEVEL;
}
int Game::getSpeedGame() const
{
	return speedGame;
}
