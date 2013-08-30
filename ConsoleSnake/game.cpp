#include <iostream>
#include "winFun.hpp"
#include "game.hpp"

bool Game::SOUND = false;
bool Game::PAUSE = false;
Game::Game()
{
	snake_ = Snake();
	field_ = Field();
	score_ = Score();
	speedGame = START_SPEED_GAME;
	difficulty_ = EASY;
}
void Game::draw()
{
	
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
void Game::drawBorder() const
{
	field_.drawBorder();
}
void Game::drawScore() const
{
	gotoxy(Field::WIDTH+5,3);
	std::cout << "Level: ";
	gotoxy(Field::WIDTH+5,4);
	std::cout << "Score: ";
	gotoxy(Field::WIDTH+5,5);
	std::cout << "Speed: ";
	
}
void Game::redrawScore() const
{
	gotoxy(Field::WIDTH+12,3);
	std::cout << score_.getLevel()+1 << "    ";
	gotoxy(Field::WIDTH+12,4);
	std::cout << score_.getScore() << "    ";
	gotoxy(Field::WIDTH+12,5);
	std::cout << speedGame<< "    ";
}
