#include "Check.h"

//	勝ったかどうか（3×3用、3マスそろえたら勝ち）
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

// 勝ったかどうか（5×5用、4マスそろえたら勝ち）
bool Check::CheckWin2(int board[5][5], int player)
{
	// 横が4つそろったとき
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			if (board[row][col] == player &&
				board[row][col + 1] == player &&
				board[row][col + 2] == player &&
				board[row][col + 3] == player)
			{
				return true;
			}
		}
	}

	// 縦が4つそろったとき
	for (int col = 0; col < 5; col++)
	{
		for (int row = 0; row < 2; row++)
		{
			if (board[row][col] == player &&
				board[row + 1][col] == player &&
				board[row + 2][col] == player &&
				board[row + 3][col] == player)
			{
				return true;
			}
		}
	}

	// 左上 → 右下（4マス連続）
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			if (board[row][col] == player &&
				board[row + 1][col + 1] == player &&
				board[row + 2][col + 2] == player &&
				board[row + 3][col + 3] == player)
			{
				return true;
			}
		}
	}

	// 右上 → 左下（4マス連続）
	for (int row = 0; row < 2; row++)
	{
		for (int col = 3; col < 5; col++)
		{
			if (board[row][col] == player &&
				board[row + 1][col - 1] == player &&
				board[row + 2][col - 2] == player &&
				board[row + 3][col - 3] == player)
			{
				return true;
			}
		}
	}

	return false;
}

//	文字で判定を確認する
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

void Check::Draw3()
{
	SetFontSize(40);
	if(full)	DrawString(500, 500, "ひきわけ", GetColor(255, 255, 0));
	
}

