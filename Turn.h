#pragma once

class Board;

/// <summary>
/// ターンクラス
/// </summary>
class Turn
{
	int turn = 0;

public:

	//	ターン切替
	void TurnChange(Board& board,int arg_mouse_x,int arg_mouse_y)
	{
		if (arg_mouse_x >= 0 && arg_mouse_x < 400 
			&& arg_mouse_y >= 0 && arg_mouse_y < 400) {

			int col = arg_mouse_x / (400 / 3);
			int row = arg_mouse_y / (400 / 3);

			//	◎罰交互
			if (board.board_size[row][col] == 0) {
				//	ターン０のときは１（〇）を
				if (turn == 0) {
					board.board_size[row][col] = 1;	// 〇
					turn = 1;
				}
				//	ターン１のときは２（×）を
				else {
					board.board_size[row][col] = 2;	// ×
					turn = 0;
				}
			}
		}

	}
};