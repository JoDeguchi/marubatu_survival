#pragma once
#include <string>
#include "DxLib.h"		// DxLib
#include "Background.h"

#define BOARD_SIZE_W 3
#define BOARD_SIZE_H 3


/// <summary>
/// 盤単体のクラス
/// </summary>
class Board: public Background
{
protected:

	//	座標位置
	int pos_x=0 ,pos_y = 0;

private:

	static const int board_size_w = BOARD_SIZE_W;
	static const int board_size_h = BOARD_SIZE_H;

	//	幅
	int extend = 400;	//	伸ばす

public:

	//	盤の大きさ
	int board_size[board_size_w][board_size_h] = {};
	//	５マスに変える方法がなかったので新しい変数で変えるように
	int current_w = 3;
	int current_h = 3;

	///// <summary>
	///// デフォルトコンストラクタ
	///// </summary>
	Board(){}
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_file_path">初期画像ファイルパス</param>
	Board(std::string arg_file_path, int arg_x, int arg_y)
	{
		this->Load_image(arg_file_path);

		this->pos_x = arg_x;
		this->pos_y = arg_y;
	}

	void SetPos(int arg_x, int arg_y)
	{
		pos_x = arg_x;
		pos_y = arg_y;
	}

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="arg_diff_x">横位置の差分</param>
	/// <param name="arg_diff_y">縦位置の差分</param>
	void Move(int arg_diff_x, int arg_diff_y)
	{
		this->pos_x += arg_diff_x;
		this->pos_y += arg_diff_y;
	}

	/// <summary>
	/// 引き分けの場合
	/// </summary>
	void Drawflag(bool arg_draw)
	{
		if (arg_draw) {
			current_w = 5;
			current_h = 5;
			extend = 533;
			
		}
		else{
			current_w = 3;
			current_h = 3;
			extend= 400;
		}
	}

	/// <summary>
	///	盤面描画
	/// 　透過あり
	/// </summary>
	void Draw() 
	{
		// 盤面描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(this->pos_x, this->pos_y,this->pos_x+extend, this->pos_y+extend, GetColor(0,200,0));	
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
};
