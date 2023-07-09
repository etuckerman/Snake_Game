#pragma once

#include "Board.h"


class Snake
{
private:
	class Segment
	{
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);

private:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax]; 				   //index to fill empty array spots
	int nSegments = 1;
};