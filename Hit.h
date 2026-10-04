#pragma once
#include "Dxlib.h"

/// <summary>
/// あたり判定等をまとめた
/// </summary>
class Hit
{
private:

public:

	//-----------------------------------------------------------
	//	マウスと画像のあたり判定をチェック
	//-----------------------------------------------------------
	static bool CheckImage(int mx, int my, int imgx, int imgy, 
		int image_hnd)
	{
		int w, h;									//	画像の幅と高さ
		GetGraphSize(image_hnd, &w, &h);			//	画像サイズを取得

		return (mx >= imgx && mx <= imgx + w &&		//	範囲内にマウスがあるか判定
			my >= imgy && my <= imgy + h);
	}

	//-----------------------------------------------------------
	//	マウスと文字のあたり判定をチェック
	//-----------------------------------------------------------
	static bool CheckText(int mx, int my, int x, int y,
		const char* text,int FontSize)
	{
		int w = GetDrawStringWidth(text, strlen(text));	//	文字列の幅を取得
		int h = FontSize;								// フォントサイズを高さとみなす

		return (mx >= x && mx <= x + w &&
			my >= y && my <= y + h);
	}

};