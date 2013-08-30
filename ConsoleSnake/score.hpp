#pragma once
#ifndef _SCORE_HPP_
#define _SCORE_HPP_

class Score
{
public:
	enum { SCORE_PER_APPLE = 10, APPLE_PER_LEVEL = 1 };
private:
	int countApple_;
	int level_;
	int score_;
public:
	Score();
	int getLevel() const;
	int getScore() const;
	void plusApple();
};

#endif