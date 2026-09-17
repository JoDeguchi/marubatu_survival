#include "Check.h"

//	勝ったかどうか
bool Check::CheckWin(int board[3][3],int player)
{
	//	横がそろったとき
	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == player &&
			board[row][1] == player &&
			board[row][2] == player)
		{
			return true;
		}
	}

	// 縦
	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == player &&
			board[1][col] == player &&
			board[2][col] == player)
		{
			return true;
		}
	}

	// 左上 → 右下
	if (board[0][0] == player &&
		board[1][1] == player &&
		board[2][2] == player)
	{
		return true;
	}

	// 右上 → 左下
	if (board[0][2] == player &&
		board[1][1] == player &&
		board[2][0] == player)
	{
		return true;
	}

	return false;
}

//	文字で判定をたしかめる
void Check::Draw()
{
	SetFontSize(40);
	DrawString(500, 500, "プレイヤーそろったね", GetColor(255, 255, 0));
}

void Check::Draw2()
{
	SetFontSize(40);
	DrawString(500, 500, "NPCそろったね", GetColor(255, 255, 0));
}
