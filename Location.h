#pragma once

struct Location
{
public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x;			 //positions
	int y;
};