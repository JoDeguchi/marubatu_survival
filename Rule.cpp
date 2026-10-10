#include "Rule.h"
#include "DxLib.h"

void Rule::Init()
{
	// 背景画像
	this->bg0.Load_image("background.png");

	// マスコットキャラを読み込む
	this->mascot.Load_image("aikon.png");
	this->mascot2.Load_image("aikon2.png");


	// SE読み込み
	se_click = LoadSoundMem("decision_1.mp3");

	// マウス状態をリセット
	this->mouse.Reset();
}

void Rule::Input()
{
	this->key_state.Read();	// キーボード
	this->mouse.Read();		// マウス
}

void Rule::Update()
{
	// マウスが離された時だけ
	if (this->mouse.ClicRelease())
	{
		// マウス座標取得
		int x = this->mouse.GetX();
		int y = this->mouse.GetY();

		// 戻るボタン
		if (x >= 1000 && x <= 1100 &&
			y >= 600 && y <= 625)
		{
			PlaySoundMem(se_click, DX_PLAYTYPE_BACK);
			this->game_ptr->ChageScene(0);
			return;
		}
	}
}

void Rule::Draw()
{
	// 背景
	this->bg0.Draw();

	// マウス座標
	int mouseX = this->mouse.GetX();
	int mouseY = this->mouse.GetY();

	// タイトル
	SetFontSize(64);
	DrawString(400, 50, "あそびかた", GetColor(255, 255, 255));

	//// マスコットキャラを描画
	//DrawGraph(0, 500, this->mascot.GetImageHandle(), TRUE);
	//DrawGraph(1000, 500, this->mascot2.GetImageHandle(), TRUE);

	// ルール説明テキスト
	SetFontSize(32);
	DrawString(100, 150, "ゲームのルール", GetColor(255, 255, 255));
	DrawString(100, 200, "・3×3のマスにて〇と×を交互に置きます", GetColor(255, 255, 255));
	DrawString(100, 240, "・先に自分の記号を3つそろえたら勝ちです", GetColor(255, 255, 255));
	DrawString(100, 280, "・全てのマスが埋まったら引き分けです", GetColor(255, 255, 255));
	DrawString(100, 320, "・引き分けの場合5Ｘ5に切り替わります", GetColor(255, 255, 255));
	DrawString(100, 360, "・切り替わり後4マスそろえたほうが勝ちです", GetColor(255, 255, 255));

	// 戻るボタン
	SetFontSize(25);
	int button_color = GetColor(255, 255, 255);
	if (mouseX >= 1000 && mouseX <= 1100 &&
		mouseY >= 600 && mouseY <= 625)
	{
		button_color = GetColor(255, 255, 0);
	}
	DrawString(1000, 600, "戻る", button_color);
}