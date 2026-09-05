#pragma once
#include <string>
#include "DxLib.h"		// DxLib
#include "Background.h"

/// <summary>
/// スプライトクラス
/// </summary>
class Sprite: public Background
{
protected:

	/// <summary>
	/// 横表示位置
	/// </summary>
	int pos_x = 0;
	int pos_x2 = 250;

	/// <summary>
	/// 縦表示位置
	/// </summary>
	int pos_y = 0;
	int pos_y2 = 50;
	
	//	線の座標
	int line_x = 0;
	int line_y = 0;

	//	線の座標終端
	int line_x2 = 0;
	int line_y2 = 0;


public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Sprite(){}

	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_file_path">初期画像ファイルパス</param>
	Sprite(std::string arg_file_path)
	{
		// 画像ファイルの読み込み
		this->Load_image(arg_file_path);
	}

	/// <summary>
	/// 表示位置の指定
	/// </summary>
	/// <param name="arg_x">横位置</param>
	/// <param name="arg_y">縦位置</param>
	void Set_pos(int arg_x, int arg_y)
	{
		// 横座標の登録
		this->pos_x = arg_x;
		// 縦座標の登録
		this->pos_y = arg_y;
	}

	void Line_pos(int arg_x, int arg_y, int arg_x2, int arg_y2)
	{
		// 線の座標の登録
		this->line_x = arg_x;
		this->line_y = arg_y;
		// 線の座標終端の登録
		this->line_x2 = arg_x2;
		this->line_y2 = arg_y2;
	}	

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="arg_diff_x">横位置の差分</param>
	/// <param name="arg_diff_y">縦位置の差分</param>
	void Move(int arg_diff_x, int arg_diff_y)
	{
		// 横位置の差分を反映
		this->pos_x += arg_diff_x;
		// 縦位置の差分を反映
		this->pos_y += arg_diff_y;
	}

	/// <summary>
	///	盤面描画
	/// 　透過あり
	/// </summary>
	void Draw() override
	{
		// 盤面描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(this->pos_x, this->pos_y,this->pos_x+400, this->pos_y+400, GetColor(0,200,0));	
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	//UI描画
	void DrawUI()
	{
		DrawBox(pos_x2, pos_y2, pos_x2 + 200, pos_y2 + 100, GetColor(255, 0, 0), true);
		
	}

	

};
