#include <iostream>
#include "game.hpp"

bool Game::SOUND = false;
bool Game::PAUSE = false;
Game::Game()
{
	snake_ = Snake();
	field_ = Field();
	score_ = Score();
	speedGame = START_SPEED_GAME;
	difficulty_ = HARD;
}
void Game::draw()
{
	std::cout << "Level: " << score_.getLevel()+1
				<< " Score: " << score_.getScore()
				<< " Speed: " << speedGame << std::endl;
	field_.draw(snake_);
	
}
void Game::keyEvent(Snake::Direction d)
{
	snake_.keyEvent(d);
}
void Game::update()
{
	if(!snake_.update(*this))
	{
		snake_ = Snake();
		field_ = Field();
		score_ = Score();
		speedGame = START_SPEED_GAME;
	}
	if((START_SPEED_GAME - score_.getLevel()*SPEED_PER_LEVEL) <= 10)
		speedGame = 10;
	else speedGame = START_SPEED_GAME - score_.getLevel()*SPEED_PER_LEVEL;
}
int Game::getSpeedGame() const
{
	return speedGame;
}
Field & Game::getField()
{
	return field_;
}
Score & Game::getScore()
{
	return score_;
}
Game::Difficulty Game::getDiffuculty() const
{
	return difficulty_;
}
