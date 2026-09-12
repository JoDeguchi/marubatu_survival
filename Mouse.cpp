#include "Mouse.h"
#include "DxLib.h"

void Mouse::Read()
{
	// 前フレームの状態を保存
	bool prev = mouse_frame;
	// 今の状態を取得
	mouse_frame = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
	// 押された瞬間
	clic_down = (!prev && mouse_frame);
	//	マウス座標
	GetMousePoint(&mouse_x, &mouse_y);
}

//	結果を返す
bool Mouse::ClicPress() const
{
	return clic_down;
}


/// <summary>
   /// マウスX座標
   /// </summary>
int Mouse::GetX() const
{
	return mouse_x;
}

/// <summary>
/// マウスY座標
/// </summary>
int Mouse::GetY() const
{
	return mouse_y;
}