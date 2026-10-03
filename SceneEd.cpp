
#include "SceneEd.h"

#include "DxLib.h"
#include <cstdlib> // exit


void SceneEd::Init()
{
	// 背景画像の読込
	this->bg0.Load_image("background.png");

	
	this->mouse.Reset();// マウス状態をリセット

	// UI画像の読込
	this->title_return.Load_image("title_return.png");// タイトルに戻るUIの背景
	this->once_again.Load_image("once_again.png");// もう一度プレイするUIの背景
	this->total_victory.Load_image("total_victory.png");// 〇勝ちUIの背景
	this->decisive_victory.Load_image("decisive_victory.png");// ×勝ちUIの背景
}

static void DrawButtonSimple(int mouseX, int mouseY,
	int x, int y, int w, int h,
	const char* text, int fontSize)
{
	SetFontSize(fontSize);

	int color = GetColor(255, 255, 255);

	// マウスが上にあるか判定（領域は x..x+w, y..y+h）
	if (mouseX >= x && mouseX <= x + w &&
		mouseY >= y && mouseY <= y + h)
	{
		color = GetColor(255, 255, 0);
	}

	DrawString(x, y, text, color);
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

	// 常時表示するUI（タイトルに戻る・もう一度プレイ）
	this->title_return.Draw();
	this->once_again.Draw();

	// ゲームの勝利情報を取得
	Check& check_data = this->game_ptr->GetCheckData();

	// 勝者に応じて該当の画像のみを表示する
	if (check_data.playerwinner)
	{
		// プレイヤー（〇）が勝利したときに 〇用画像を表示
		this->total_victory.Draw();
	}
	else if (check_data.npcwinner)
	{
		// NPC（×）が勝利したときに ×用画像を表示
		this->decisive_victory.Draw();
	}
	// 引き分けなど勝敗がない場合は勝敗画像は表示しない

	// マウス座標
	int mouseX = this->mouse.GetX();
	int mouseY = this->mouse.GetY();

	// 「タイトルに戻る」
	DrawButtonSimple(mouseX, mouseY, 300, 300, 500, 60, "タイトルに戻る", 64);

	// 「ゲーム終了」
	DrawButtonSimple(mouseX, mouseY, 300, 400, 500, 60, "ゲーム終了", 64);
}