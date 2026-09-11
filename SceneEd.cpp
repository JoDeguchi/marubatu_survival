#include "SceneEd.h"

#include "DxLib.h"


void SceneEd::Init()
{
	// 背景画像の読込
	this->bg0.Load_image("ed.png");
}

/// <summary>
/// 描画処理
/// </summary>
void SceneEd::Draw()
{
	// 背景0を描画
	//this->bg0.Draw();


	SetFontSize(64);
	DrawString(500, 100, "○○の勝ち", GetColor(255, 255, 255));
	DrawString(300, 300, "タイトルに戻る", GetColor(255, 255, 255));
	DrawString(300, 400, "ゲーム終了", GetColor(255, 255, 255));

}
