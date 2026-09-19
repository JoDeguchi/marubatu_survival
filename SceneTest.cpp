#include "SceneTest.h"
#include "DxLib.h"

#define LINE_BASE_X 550
#define LINE_BASE_Y 330


/// <summary>
/// 初期化
/// </summary>
void SceneTest::Init()
{
	//	プレイヤーとNPCが勝ったフラグをオフに
	check.playerwinner = false;
	check.npcwinner = false;
	check.draw = false;
	//	時間０に
	timer = 0;

	//	盤目の位置
	board = Board("", 550, 330);

	//	線の基準を決める
	int base_x = LINE_BASE_X;
	int base_y = LINE_BASE_Y;
	int size = 400;
	int cell = size / 3;	//	1マス分

	// 横線
	line_w[0].SetLinePos(base_x , base_y + cell     , base_x + size , base_y + cell);
	line_w[1].SetLinePos(base_x , base_y + cell * 2 , base_x + size , base_y + cell * 2);

	// 縦線
	line_h[0].SetLinePos(base_x + cell     , base_y , base_x + cell     , base_y + size);
	line_h[1].SetLinePos(base_x + cell * 2 , base_y , base_x + cell * 2 , base_y + size);

	
	//	丸とバツ　マスごとに初期化
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			//	１マス１３３pxとして
			int x = base_x + col * 133;
			int y = base_y + row * 133;

			maru[row][col] = Maru("maru.png", x, y);
			batu[row][col] = Batu("batu.png", x, y);
		}
	}

	//	UI
	ui = UI("playerUI.png",30,-60);
	ui2 = UI("NPCUI.png", 950, -70);
	
}

/// <summary>
/// 入力処理
/// </summary>
void SceneTest::Input()
{
	//	マウス読み込み
	mouse.Read();
}

/// <summary>
/// 丸と罰をリセット
/// </summary>
void SceneTest::ResetMaruBatu()
{
	int base_x = LINE_BASE_X;
	int base_y = LINE_BASE_Y;

	// 盤面データをクリア
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			board.board_size[row][col] = 0;
		}
	}

	// 丸と罰を再初期化
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			int x = base_x + col * 133;
			int y = base_y + row * 133;

			maru[row][col] = Maru("maru.png", x, y);
			batu[row][col] = Batu("batu.png", x, y);
		}
	}
}

/// <summary>
/// 更新処理
/// </summary>
void SceneTest::Update()
{
	//	マウスクリックされたら、まるばつ置くための処理（ターン分け交互）
	if (mouse.ClicPress())
	{
		//	マウス座標
		int mx = mouse.GetX() - LINE_BASE_X;
		int my = mouse.GetY() - LINE_BASE_Y;

		turn.TurnChange(board,mx, my);
		
	}

	//	そろったら勝ったと判定　それぞれ
	if (check.CheckWin(board.board_size, 1))
	{
		timer++;
		check.playerwinner = true;
	}
	else if (check.CheckWin(board.board_size, 2))
	{
		timer++;
		check.npcwinner = true;
	}
	//	ひきわけの場合
	else 
	{
		// 盤面が全部埋まっているか確認
		 check.full = true;

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				if (board.board_size[row][col] == 0)
				{
					check.full = false;
				}
			}
		}

		// 全部埋まっていたら引き分け
		if (check.full)
		{
			check.draw = true;
			board.Drawflag(check.draw);

			//	丸と罰をリセット
			this->ResetMaruBatu();

			
			board.SetPos((550-133),(330-133));
		
			//	線の基準を決める
			int base_x = LINE_BASE_X-133;
			int base_y = LINE_BASE_Y-133;
			int size = 666;
			int cell = size / 5;	//	1マス分

			// 横線4本
			for (int i = 0; i < 4; i++)
			{
				line_w[i].SetLinePos(
					base_x,
					base_y + cell * (i + 1),
					base_x + size,
					base_y + cell * (i + 1)
				);
			}

			// 縦線4本
			for (int i = 0; i < 4; i++)
			{
				line_h[i].SetLinePos(
					base_x + cell * (i + 1),
					base_y,
					base_x + cell * (i + 1),
					base_y + size
				);
			}
		}
	}

	//	時間を止める
	if (timer > 180)	timer = 180;
	
	//	勝利時はエンディングへ
	if (timer == 180){
		// 勝利情報をゲームに保存
		this->game_ptr->GetCheckData().playerwinner = check.playerwinner;
		this->game_ptr->GetCheckData().npcwinner = check.npcwinner;
		
		this->game_ptr->ChageScene(2);
		check.playerwinner = false;
		check.npcwinner = false;
		timer = 0;
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


	if (check.draw) {
		//	線の描画	
		for (int i = 0; i < 4; i++)
		{
			line_w[i].Draw();
			line_h[i].Draw();
		}
	}
	else {
		//	線の描画	
		for (int i = 0; i < 2; i++)
		{
			line_w[i].Draw();
			line_h[i].Draw();
		}
	}

	
	
	//	丸とばつの描画
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			if (board.board_size[row][col] == 1){
				// 〇を描画
				maru[row][col].Draw();
			}
			else if (board.board_size[row][col] == 2){
				// ×を描画
				batu[row][col].Draw();
			}
		}
	}

	//	UIの描画
	ui.Draw();
	ui2.Draw();

	//	そろったと文字列でそれぞれ描画
	if (check.CheckWin(board.board_size,1)){
		check.Draw();
	}
	else if (check.CheckWin(board.board_size, 2)){
		check.Draw2();
	}
	else {
		check.Draw3();
	}
}

/// <summary>
/// 音声再生処理
/// </summary>
void SceneTest::Sound_play()
{


}
