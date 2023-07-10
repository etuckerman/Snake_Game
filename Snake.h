#pragma once

#include "Board.h"


class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);				  //ensure body follows previous head locations
	void Grow();
	void Draw(Board& brd) const;

private:
	static constexpr Color headColor = Colors::Yellow;			//head and body colours
	static constexpr Color bodyColor = Colors::Green;

	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax]; 				   //index to fill empty array spots
	int nSegments = 1;
};