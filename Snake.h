#pragma once

#include "Board.h"


class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;					  //return location as reference
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);				  //ensure body follows previous head locations
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target) const; //for collision detection
	bool IsInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;			//head and body colours
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax]; 				   //index to fill empty array spots
	int nSegments = 1;
};