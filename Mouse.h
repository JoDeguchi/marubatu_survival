#pragma once
#include "DxLib.h"

class Mouse
{
	int mouse_x = 0;
	int mouse_y = 0;

	//	マウスがクリックされたフラグ
	bool clic_down = false;
	bool clic_up = false;
	bool mouse_frame = false;

public:

	//	読み込み
	void Read();

	//	押された瞬間を返す
	bool ClicPress() const;

	//	離された瞬間を返す
	bool ClicRelease() const;

	/// <summary>
	/// マウスX座標
	/// </summary>
	int GetX() const;

	/// <summary>
	/// マウスY座標
	/// </summary>
	int GetY() const;

	/// <summary>
	/// マウス状態をリセット
	/// </summary>
	void Reset();
};