
#include "SceneEd.h"

#include "DxLib.h"
#include <cstdlib> // exit


void SceneEd::Init()
{
	// 背景画像の読込,初期値
	bg = Background("background.png", 0, 0);
	// マウス状態をリセット
	mouse.Reset();
	// UI画像の読込
	CircleVictory = UI("total_victory.png", 450, 160);		// 〇勝ち画像
	CrossVictory  = UI("decisive_victory.png", 450, 160);	// ×勝ち画像

	string0 = String(500, 400, "タイトルに戻る", 70);	
	string1 = String(550, 550, "ゲーム終了", 70);

	confetti = UI("02.png", 0, 0);
	confetti2 = UI("02.png", 0, -1500);
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
	// ゲームの勝利情報を取得
	check_data = this->game_ptr->GetCheckData();

	//	マウス座標を取得
	int x = this->mouse.GetX();
	int y = this->mouse.GetY();

	string0.HitText(x, y); // 「タイトルに戻る」文字のあたり判定
	string1.HitText(x, y); // 「ゲーム終了」文字のあたり判定
	// マウスクリック時の処理
	if (this->mouse.ClicRelease())
	{
		// タイトルへ戻る
		if (string0.HitText(x, y))
		{
			this->game_ptr->ChageScene(0);
			return;
		}

		// ゲーム終了
		if (string1.HitText(x, y))
		{
			// 即終了
			exit(0);
		}
	}

	// 紙吹雪の高さ
	const int IMG_H = 1500;

	// 紙吹雪を下へ移動
	confetti.Move(0, 4);
	confetti2.Move(0, 4);

	// 1枚目が画面下に消えたら上に戻す
	if (confetti.GetY() >= WINDOW_H) {
		confetti.SetPos(0, confetti2.GetY() - IMG_H);
	}

	// 2枚目が画面下に消えたら上に戻す
	if (confetti2.GetY() >= WINDOW_H) {
		confetti2.SetPos(0, confetti.GetY() - IMG_H);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void SceneEd::Draw()
{
	// 背景0を描画
	this->bg.Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
	DrawFillBox(450, 380, 1050, 680, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	紙吹雪描画
	confetti.Draw();
	confetti2.Draw();

	// 勝者に応じて該当の画像のみを表示する
	if (check_data.playerwinner)
	{
		CircleVictory.Draw(); // （〇）勝利時に〇用画像を表示
	}
	else if (check_data.npcwinner)
	{
		CrossVictory.Draw(); //  （×）勝利時に×用画像を表示
	}

	string0.Draw(); // 「タイトルに戻る」文字を描画
	string1.Draw(); // 「ゲーム終了」文字を描画

}