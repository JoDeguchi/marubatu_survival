#pragma once
#include "board.h"
#include "Dxlib.h"

class Check
{
	Board board;
public:

	bool CheckWin(int board[3][3],int player);
	void Draw();
	void Draw2();
};