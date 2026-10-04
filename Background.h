#pragma once
#include <string>
#include "DxLib.h"		// DxLib

/// /// <summary>
/// 背景クラス
/// </summary>
class Background
{
protected:

	/// <summary>
	/// 画像ファイルパス
	/// </summary>
	std::string file_path = "";

	/// <summary>
	/// 画像ハンドル
	/// </summary>
	int image_hnd = -1;

	/// <summary>
	/// 描画座標
	/// </summary>
	int pos_x = 0; int pos_y = 0;

public:

	/// <summary>
	/// デフォルトコンストラクター
	/// </summary>
	Background(){}

	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_file_path">初期画像ファイルパス</param>
	Background(std::string arg_file_path,int x,int y)
	{
		// 画像ファイルを読み込む
		Load_image(arg_file_path);
		SetPos(x, y);
	}

	/// <summary>
	/// 画像ファイルを読み込む
	/// </summary>
	/// <param name="arg_file_path">画像ファイルパス</param>
	void Load_image(std::string arg_file_path)
	{
		// 画像ファイルパスを保持
		file_path = arg_file_path;

		// 指定されたファイルを読み込む
		image_hnd = LoadGraph(file_path.c_str());
	}

	/// <summary>
	/// 描画位置
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetPos(int x, int y)
	{
		pos_x = x;
		pos_y = y;
	}


	/// <summary>
	/// 背景を描画
	/// 　透過無し
	/// </summary>
	void Draw()
	{
		// 背景を描画
		DrawGraph(pos_x, pos_y,image_hnd, true);	
	}
};



