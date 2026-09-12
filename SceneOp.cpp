#include "SceneOp.h"
#include "DxLib.h"


void SceneOp::Init()
{
	
}

/// <summary>
/// 入力処理
/// </summary>
void SceneOp::Input()
{
	// キー状態読込（一括）
	this->key_state.Read();
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
	// 背景0を描画
	this->bg0.Draw();

	// メッセージを描画

	SetFontSize(64);
	DrawString(400, 100, "〇×サバイバル", GetColor(255, 255, 255));

	SetFontSize(32);
	DrawString(400, 300, "オフライン対戦", GetColor(255, 255, 255));
	DrawString(400, 340, "コンピューター対戦（むずかしさ）", GetColor(255, 255, 255));

	SetFontSize(25);
	DrawString(500, 400, "ふつう", GetColor(255, 255, 255));
	DrawString(500, 430, "むずかしい", GetColor(255, 255, 255));
	DrawString(500, 460, "げきむず", GetColor(255, 255, 255));

	SetFontSize(22);
	DrawString(1000, 600, "あそびかた", GetColor(255, 255, 255));

	
/*
	if ((this->update_cnt / 40) % 2 == 0)
	{
		SetFontSize(32);
		DrawString(522, 602, "Press Any Key!!", GetColor(220, 220, 220));
		DrawString(520, 600, "Press Any Key!!", GetColor(255, 0, 0));
	}
*/
}

