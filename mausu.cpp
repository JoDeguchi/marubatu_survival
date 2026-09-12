#include "Mouse.h"
#include "DxLib.h"

void Mouse::Update()
{
	// マウス位置を取得
	int x = 0;
	int y = 0;
	GetMousePoint(&x, &y);
	this->mouse_x = x;
	this->mouse_y = y;

	// マウスボタン状態を取得（DxLib のフラグを使用）
	int mouseInput = GetMouseInput();
	this->mouse_left = (mouseInput & MOUSE_INPUT_LEFT) != 0;
	this->mouse_right = (mouseInput & MOUSE_INPUT_RIGHT) != 0;
	this->mouse_middle = (mouseInput & MOUSE_INPUT_MIDDLE) != 0;
}