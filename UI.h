#pragma once
#include "Background.h"
#include "Hit.h"

/// <summary>
/// 画像クラス
/// </summary>
class UI: public Background
{
private:
	bool HitIn = false;	//	マウスが画像の中にあるかどうか
public:

	//	デフォルト
	UI(){}
	//	コンストラクタ
	UI(std::string arg_file_path, int arg_x, int arg_y)
	{
		Load_image(arg_file_path);
		SetPos(arg_x, arg_y);
	}

	//	マウス(引数)と画像のあたり判定
	bool HitImg(int mx, int my)
	{
		HitIn= Hit::CheckImage(mx, my, pos_x, pos_y, image_hnd);
		return HitIn;
	}

	//	描画
	void Draw()
	{
		int w, h;							//	画像の幅と高さ
		GetGraphSize(image_hnd, &w, &h);	//	画像サイズを取得

		//	マウスが画像の中にある場合は、画像を縮小して描画
		if (HitIn) {
			//	ちょっと補正
			DrawExtendGraph(pos_x+50, pos_y, pos_x+w*0.92, pos_y + h*0.9, image_hnd, true);
		}
		else {
			//	普通に描画
			DrawGraph(pos_x, pos_y, image_hnd, true);
		}
		
	}
};
