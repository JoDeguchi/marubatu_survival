#include "SceneOp.h"
#include "DxLib.h"

// ボタン描画
// マウス座標、ボタン座標、ボタン横幅
void DrawButton(int mouseX, int mouseY,
	int x, int y, int w, int h,
	const char* text, int fontSize)
{
	SetFontSize(fontSize);

	int color = GetColor(255, 255, 255);

	// マウスが上にあるか判定
	if (mouseX >= x && mouseX <= x + w &&
		mouseY >= y && mouseY <= y + h)
	{
		color = GetColor(255, 255, 0);
	}

	DrawString(x, y, text, color);
}

void SceneOp::Init()
{   // 背景画像
	this->bg0.Load_image("background.png");
}

void SceneOp::Input()
{
	this->key_state.Read(); // キーボード
	this->mouse.Read();     // マウス
}

void SceneOp::Update()
{   // クリックしたら
	if (this->mouse.ClicPress())
	{   // マウス座標取得
		int x = this->mouse.GetX();
		int y = this->mouse.GetY();

		// オフライン対戦
		if (x >= 400 && x <= 650 &&
			y >= 300 && y <= 335)
		{
			this->game_ptr->ChageScene(1);
			return;
		}
	}
}

void SceneOp::Draw()
{
	// 背景
	this->bg0.Draw();

	// マウス座標
	int mouseX = this->mouse.GetX();
	int mouseY = this->mouse.GetY();

	// タイトル
	SetFontSize(64);
	DrawString(400, 100, "〇×サバイバル",GetColor(255, 255, 255));

	// ボタン
	// 文字列描画
	DrawButton(mouseX, mouseY,400, 300, 250, 35, "オフライン対戦", 32);
	DrawButton(mouseX, mouseY,400, 340, 620, 35,"コンピューター対戦     （むずかしさ）", 32);
	DrawButton(mouseX, mouseY,830, 400, 70, 30, "ふつう", 25);
	DrawButton(mouseX, mouseY,830, 430, 130, 25, "むずかしい", 25);
	DrawButton(mouseX, mouseY,830, 460, 100, 25, "げきむず", 25);
	DrawButton(mouseX, mouseY,1000, 600, 100, 25, "あそびかた", 22);

}
