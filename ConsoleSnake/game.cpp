#include "game.hpp"

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
	if(!snake_.update(field_))
	{
		snake_ = Snake();
		field_ = Field();
	}
}