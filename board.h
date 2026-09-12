#pragma once
#include <string>
#include "DxLib.h"		// DxLib
#include "Background.h"

/// <summary>
/// 盤
/// </summary>
class Board: public Background
{
protected:

	//	座標位置
	int pos_x=0 ,pos_y = 0;

public:

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
	///	盤面描画
	/// 　透過あり
	/// </summary>
	void Draw() 
	{
		// 盤面描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(this->pos_x, this->pos_y,this->pos_x+400, this->pos_y+400, GetColor(0,200,0));	
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
};
