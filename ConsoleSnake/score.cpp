#include "score.hpp"

Score::Score()
{
	level_ = 1;
	score_ = 0;
	countApple_ = 0;
}
int Score::getLevel() const
{
	return level_;
}
int Score::getScore() const
{
	return score_;
}
void Score::plusApple()
{
	countApple_++;
	if(!(countApple_ % 5))
		level_++;
	score_ = countApple_ * SCORE_PER_APPLE * level_;
}