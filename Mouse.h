#pragma once
#include "DxLib.h"

class Mouse
{
	int mouse_x = 0;
	int mouse_y = 0;

	//	マウスが押された瞬間
	bool clic_down = false;
	bool mouse_frame = false;

public:

	//	読み込み
	void Read();

	//	結果を返す
	bool ClicPress() const;

	/// <summary>
	/// マウスX座標
	/// </summary>
	int GetX() const;

	/// <summary>
	/// マウスY座標
	/// </summary>
	int GetY() const;

		
};