#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{

}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);				  //ensure window range is locked
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.x < height);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c); //grid coord * cell = position on screen
}

int Board::GetGridWidth() const
{
	return width;
}


int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.y < height;
}
