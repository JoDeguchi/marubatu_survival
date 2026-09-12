#pragma once

class Mouse
{
	public:
		//	マウスの座標
		int mouse_x = 0;
		int mouse_y = 0;
		//	マウスのボタン状態
		bool mouse_left = false;
		bool mouse_right = false;
		bool mouse_middle = false;
		//	マウスの状態を更新する
		void Update();



};