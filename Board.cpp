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

	const int off_x = x;
	const int off_y = y;

	gfx.DrawRectDim(loc.x * dimension + off_x, loc.y * dimension + off_y, dimension, dimension, c); //grid coord * cell = position on screen
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
	return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x; //boundaries
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension; //calculate bottom coord
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	//borders

	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);

	//left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth,bottom - borderWidth, borderColor);

	//right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);

	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
}
