#include "SceneOp.h"
#include "DxLib.h"


void SceneOp::Init()
{
	// 背景画像の読込
	this->bg0.Load_image("background.png");
}

/// <summary>
/// 入力処理
/// </summary>
void SceneOp::Input()
{
	// キー状態読込（一括）
	this->key_state.Read();

	//	マウス読み込み
	mouse.Read();
}

/// <summary>
/// 更新処理
/// </summary>
void SceneOp::Update()
{
	// キーが押されたかのチェック
	if (this->key_state.KeyPress())
	{
		// 押されていたらテストシーンへ
		this->game_ptr->ChageScene(1);
	}

	// 更新カウンターインクリメント
	this->update_cnt++;
}

/// <summary>
/// 描画処理
/// </summary>
void SceneOp::Draw()
{
	// 背景
	this->bg0.Draw();

	// マウス座標を取得
	int mouseX = mouse.GetX();
	int mouseY = mouse.GetY();


	// タイトル
	SetFontSize(64);
	DrawString(400, 100, "〇×サバイバル",
		GetColor(255, 255, 255));


	// オフライン対戦
	SetFontSize(32);

	int offlineColor = GetColor(255, 255, 255);

	if (mouseX >= 400 && mouseX <= 650 &&
		mouseY >= 300 && mouseY <= 335)
	{
		// マウスをかざすと黄色に
		offlineColor = GetColor(255, 255, 0);
	}

	DrawString(400, 300, "オフライン対戦", offlineColor);


	// コンピューター対戦
	int computerColor = GetColor(255, 255, 255);

	if (mouseX >= 400 && mouseX <= 850 &&
		mouseY >= 340 && mouseY <= 375)
	{
		computerColor = GetColor(255, 255, 0);
	}

	DrawString(400, 340,"コンピューター対戦（むずかしさ）",computerColor);


	// 難易度
	SetFontSize(25);

	int normalColor = GetColor(255, 255, 255);

	if (mouseX >= 500 && mouseX <= 570 &&
		mouseY >= 400 && mouseY <= 430)
	{
		normalColor = GetColor(255, 255, 0);
	}

	DrawString(500, 400, "ふつう", normalColor);

	// むずかしい
	int hardColor = GetColor(255, 255, 255);

	if (mouseX >= 500 && mouseX <= 620 &&
		mouseY >= 430 && mouseY <= 455)
	{
		hardColor = GetColor(255, 255, 0);
	}

	DrawString(500, 430, "むずかしい", hardColor);


	// げきむず
	int veryHardColor = GetColor(255, 255, 255);

	if (mouseX >= 500 && mouseX <= 620 &&
		mouseY >= 460 && mouseY <= 485)
	{
		veryHardColor = GetColor(255, 255, 0);
	}

	DrawString(500, 460, "げきむず", veryHardColor);


	// あそびかた
	
	SetFontSize(22);

	int howToColor = GetColor(255, 255, 255);

	if (mouseX >= 1000 && mouseX <= 1100 &&
		mouseY >= 600 && mouseY <= 625)
	{
		howToColor = GetColor(255, 255, 0);
	}

	DrawString(1000, 600, "あそびかた", howToColor);
}
