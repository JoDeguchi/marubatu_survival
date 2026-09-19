#include "SceneEd.h"

#include "DxLib.h"
#include <cstdlib> // exit


void SceneEd::Init()
{
	// 背景画像の読込
	this->bg0.Load_image("background.png");
}

/// <summary>
/// 入力処理
/// </summary>
void SceneEd::Input()
{
	// マウス読み込み
	this->mouse.Read();
}

/// <summary>
/// 更新処理
/// </summary>
void SceneEd::Update()
{
	// マウスクリック時の処理
	if (this->mouse.ClicPress())
	{
		int x = this->mouse.GetX();
		int y = this->mouse.GetY();

		// 「タイトルに戻る」のクリック領域（テキストの表示位置に合わせた矩形）
		const int title_left = 300;
		const int title_top = 300;
		const int title_right = 800;
		const int title_bottom = 360;

		// 「ゲーム終了」のクリック領域
		const int quit_left = 300;
		const int quit_top = 400;
		const int quit_right = 800;
		const int quit_bottom = 460;

		// タイトルへ戻る
		if (x >= title_left && x <= title_right && y >= title_top && y <= title_bottom)
		{
			this->game_ptr->ChageScene(0);
			return;
		}

		// ゲーム終了
		if (x >= quit_left && x <= quit_right && y >= quit_top && y <= quit_bottom)
		{
			// 即終了
			exit(0);
		}
	}
}

/// <summary>
/// 描画処理
/// </summary>
void SceneEd::Draw()
{
	// 背景0を描画
	this->bg0.Draw();

	SetFontSize(64);
	
	// ゲームの勝利情報を取得
	Check& check_data = this->game_ptr->GetCheckData();
	
	// 勝者を判定して文字列を表示
	if (check_data.playerwinner)
	{
		DrawString(500, 100, "○の勝ち", GetColor(255, 255, 255));
	}
	else if (check_data.npcwinner)
	{
		DrawString(500, 100, "×の勝ち", GetColor(255, 255, 255));
	}
	
	
	DrawString(300, 300, "タイトルに戻る", GetColor(255, 255, 255));
	DrawString(300, 400, "ゲーム終了", GetColor(255, 255, 255));
}
