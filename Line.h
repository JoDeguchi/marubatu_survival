#pragma once
#include "DxLib.h"		// DxLib

/// <summary>
///		線のクラス
/// </summary>
class Line
{
public:
	//	線の座標
	int line_x = 0;
	int line_y = 0;
	//	線の座標終端
	int line_x2 = 0;
	int line_y2 = 0;
	//	線の座標
	void SetLinePos(int arg_x, int arg_y, int arg_x2, int arg_y2);
	//	描画
	void Draw();
};