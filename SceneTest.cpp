#include "SceneTest.h"
#include "DxLib.h"

/// <summary>
/// 初期化
/// </summary>
void SceneTest::Init()
{
	// 横線
	line_w[0].SetLinePos(430, 333, 830, 333);
	line_w[1].SetLinePos(430, 466, 830, 466);

	// 縦線
	line_h[0].SetLinePos(563, 200, 563, 600);
	line_h[1].SetLinePos(696, 200, 696, 600);

	//	盤目の位置
	board = Board("", 430, 200);
	//	丸とバツ
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			//	１マス１３３pxとして
			int x = 430 + col * 133;
			int y = 200 + row * 133;

			maru[row][col] = Maru("maru.png", x, y);
			batu[row][col] = Batu("batu.png", x, y);
		}
	}

	ui = UI("playerUI.png",30,-60);
	ui2 = UI("NPCUI.png", 750, -70);
}

/// <summary>
/// 入力処理
/// </summary>
void SceneTest::Input()
{
	// キー状態読込（一括）
	this->key_state.Read();
	//	マウス読み込み
	mouse.Read();
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

	//	マウスクリックされたら
	if (mouse.ClicPress())
	{

		int x =mouse.GetX() - 430;
		int y =mouse.GetY() - 200;

		if (x >= 0 && x < 400 && y >= 0 && y < 400)
		{
			int col = x / (400 / 3);
			int row = y / (400 / 3);

			if (board_size[row][col] == 0)
			{
				if (turn == 0)
				{
					board_size[row][col] = 1;	// 〇
					turn = 1;
				}
				else
				{
					board_size[row][col] = 2;	// ×
					turn = 0;
				}
			}
		}
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
	
	
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board_size[row][col] == 1)
			{
				// 〇を描画
				maru[row][col].Draw();
			}
			else if (board_size[row][col] == 2)
			{
				// ×を描画
				batu[row][col].Draw();
			}
		}
	}

	ui.Draw();
	ui2.Draw();
}

/// <summary>
/// 音声再生処理
/// </summary>
void SceneTest::Sound_play()
{


}
