#pragma once

class Board;

/// <summary>
/// ターンクラス
/// </summary>
class Turn
{
	int turn = 0;

public:

	//	ターン切替（3×3用）
	void TurnChange(Board& board, int arg_mouse_x, int arg_mouse_y)
	{
		if (arg_mouse_x >= 0 && arg_mouse_x < 400 
			&& arg_mouse_y >= 0 && arg_mouse_y < 400) {

			int col = arg_mouse_x / (400 / 3);
			int row = arg_mouse_y / (400 / 3);

			//	丸と×を交互に置く
			if (board.board_size[row][col] == 0) {
				//	ターン0のときは1（丸）を置く
				if (turn == 0) {
					board.board_size[row][col] = 1;	// 丸
					turn = 1;
				}
				//	ターン1のときは2（×）を置く
				else {
					board.board_size[row][col] = 2;	// ×
					turn = 0;
				}
			}
		}
	}

	//	ターン切替（5×5用）
	void TurnChange5x5(Board& board, int arg_mouse_x, int arg_mouse_y)
	{
		if (arg_mouse_x >= 0 && arg_mouse_x < 666 
			&& arg_mouse_y >= 0 && arg_mouse_y < 666) {

			int col = arg_mouse_x / (666 / 5);
			int row = arg_mouse_y / (666 / 5);

			//	丸と×を交互に置く
			if (board.board_size[row][col] == 0) {
				//	ターン0のときは1（丸）を置く
				if (turn == 0) {
					board.board_size[row][col] = 1;	// 丸
					turn = 1;
				}
				//	ターン1のときは2（×）を置く
				else {
					board.board_size[row][col] = 2;	// ×
					turn = 0;
				}
			}
		}
	}

	// ターンを初期状態（〇から）にリセット
	void Reset()
	{
		turn = 0;
	}
};