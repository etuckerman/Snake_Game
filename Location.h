#pragma once

class Location
{
public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y; //overloaded operator
	}
	int x;			 //positions
	int y;
};