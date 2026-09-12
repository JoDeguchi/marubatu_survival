#pragma once
#include "board.h"
#include "Mouse.h"

class UI: public Board
{
	//Mouse mouse;

	int pos_x=0;
	int pos_y=0;

public:

	//	デフォルト
	UI(){}
	//	コンストラクタ
	UI(std::string arg_file_path, int arg_x, int arg_y)
	{
		this->Load_image(arg_file_path);

		this->pos_x = arg_x;
		this->pos_y = arg_y;
	}

	//	描画
	void Draw()
	{
		DrawGraph(pos_x, pos_y, this->image_hnd, true);
	}

};

//void Update(int arg_board_size[][])
//{
//	int x = mouse.GetX() - 430;
//	int y = mouse.GetY() - 200;

//	if (x >= 0 && x < 400 && y >= 0 && y < 400)
//	{
//		int col = x / (400 / 3);
//		int row = y / (400 / 3);

//		if (arg_board_size[row][col] == 0)
//		{
//			if (turn == 0)
//			{
//				board_size[row][col] = 1;	// 〇
//				turn = 1;
//			}
//			else
//			{
//				board_size[row][col] = 2;	// ×
//				turn = 0;
//			}
//		}
//	}
//}