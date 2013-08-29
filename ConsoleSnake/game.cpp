#include <iostream>
#include "game.hpp"

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
	}
}