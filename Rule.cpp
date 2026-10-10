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

	rule = UI("rule2.png", -100, -50);
	
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
		if (x >= 1300 && x <= 1500 &&
			y >= 800 && y <= 855)
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

	
	rule.Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
	DrawFillBox(1200, 770, 1600, 900, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 戻るボタン
	SetFontSize(60);
	int button_color = GetColor(255, 255, 255);
	if (mouseX >= 1300 && mouseX <= 1500 &&
		mouseY >= 800 && mouseY <= 850)
	{
		button_color = GetColor(255, 255, 0);
	}
	DrawString(1300, 800, "戻る", button_color);
}