#pragma once
#include "Dxlib.h"

/// <summary>
/// あたり判定
/// </summary>
class Hit
{
private:

public:

	//	マウスと画像のあたり判定をチェック
	static bool Check(int mx, int my, int imgx, int imgy, 
		int image_hnd)
	{
		int w, h;
		GetGraphSize(image_hnd, &w, &h);

		return (mx >= imgx && mx <= imgx + w &&
			my >= imgy && my <= imgy + h);
	}


};