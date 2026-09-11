#include "SceneTest.h"
#include "DxLib.h"

/// <summary>
/// 初期化
/// </summary>
void SceneTest::Init()
{
	//	横線
	line_w[0].SetLinePos(430, 330, 830, 330);
	line_w[1].SetLinePos(430, 470, 830, 470);
	//	縦線
	line_h[0].SetLinePos(550, 200, 550, 600);
	line_h[1].SetLinePos(700, 200, 700, 600);

	//	盤目の位置
	board = Board("", 430, 200);
	//	丸とバツ
	maru=Maru("maru.png", 430, 200);
	batu = Batu("batu.png", 430, 400);
}

/// <summary>
/// 入力処理
/// </summary>
void SceneTest::Input()
{
	// キー状態読込（一括）
	this->key_state.Read();
}

/// <summary>
/// 更新処理
/// </summary>
void SceneTest::Update()
{
	// ESCキーで終了
	if (this->key_state.CheckKey(KEY_INPUT_ESCAPE))
	{
		this->game_ptr->ChageScene(2);
	}

}

/// <summary>
/// 描画処理
/// </summary>
void SceneTest::Draw()
{
	// 背景0を描画
	this->bg0.Draw();

	// スプライトの描画
	this->board.Draw();

	//	線の描画	
	for(int i = 0; i < 2; i++)
	{
		line_w[i].Draw();
		line_h[i].Draw();
	}
	
	//	丸とバツの描画
	maru.Draw();
	batu.Draw();
}

/// <summary>
/// 音声再生処理
/// </summary>
void SceneTest::Sound_play()
{


}
