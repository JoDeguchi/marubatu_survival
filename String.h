#pragma once
#include "DxLib.h"
#include "Hit.h"

/// <summary>
/// 文字用クラス
/// </summary>
class String
{
private:
	int pos_x = 0; int pos_y = 0;			//	描画座標
	int fontSize = 32;						//	フォントサイズ
	const char* text = "";					//	文字列

	int color = GetColor(255, 255, 255);	//	色（白の状態）

	bool HitIn = false;						//	マウスが文字の中にあるかどうか

public:

	String() {}
	//	コンストラクター
	String(int arg_x, int arg_y, const char* arg_text, int arg_font_size=32)
		: pos_x(arg_x), pos_y(arg_y), text(arg_text), fontSize(arg_font_size)
	{

	}
	//	描画
	void Draw()
	{
		SetFontSize(fontSize);	//	フォントサイズを設定

		int drawColor = color;	//	色変える用の変数

		if (HitIn) {
			drawColor = GetColor(255, 255, 0);   // マウスが乗ったら黄色
		}
		//	普通の文字描画
		DrawString(pos_x, pos_y, text, drawColor);
	}

	// 文字とマウスのあたり判定
	//	Hitクラスで定義したCheckTextに必要な変数入れる
	bool HitText(int mx, int my)
	{
		HitIn = Hit::CheckText(mx, my, pos_x, pos_y,  text, fontSize);
		return HitIn;
	}

};