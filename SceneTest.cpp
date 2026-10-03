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
	//	時間0に
	timer = 0;
	//	勝敗決定フラグをオフに
	decide = false;

	//	盤目の位置
	board = Board("", 550, 330);

	//	線の基準を決める
	int base_x = LINE_BASE_X;
	int base_y = LINE_BASE_Y;
	int size = 400;
	int cell = size / 3;	//	1マス分

	// 横線
	line_w[0].SetLinePos(base_x, base_y + cell, base_x + size, base_y + cell);
	line_w[1].SetLinePos(base_x, base_y + cell * 2, base_x + size, base_y + cell * 2);

	// 縦線
	line_h[0].SetLinePos(base_x + cell, base_y, base_x + cell, base_y + size);
	line_h[1].SetLinePos(base_x + cell * 2, base_y, base_x + cell * 2, base_y + size);

	//	丸とバツ　マスごとに初期化（3×3）
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			//	1マス133pxとして
			int x = base_x + col * 133;
			int y = base_y + row * 133;

			maru[row][col] = Maru("maru.png", x+8, y+5);
			batu[row][col] = Batu("batu.png", x-15, y-15);
		}
	}

	//	UI
	ui = UI("playerUI.png", 30, -60);
	ui2 = UI("NPCUI.png", 950, -70);

	//背景画像
	this->bg0 = Background("kokuban.png");

	// マウス状態をリセット
	this->mouse.Reset();
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
/// 丸と×をリセット（5×5用）
/// </summary>
void SceneTest::ResetMaruBatu()
{
	int base_x = LINE_BASE_X;
	int base_y = LINE_BASE_Y;

	// 盤面データをクリア（5×5全て）
	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++){
			board.board_size[row][col] = 0;
		}
	}

	// 丸と×を再初期化（5×5）
	int cell_size = 666 / 5;	// 133.2px
	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++){
			int x = base_x - 133 + col * cell_size;
			int y = base_y - 133 + row * cell_size;

			maru_5x5[row][col] = Maru("maru.png", x+8, y+5);
			batu_5x5[row][col] = Batu("batu.png", x-15, y-15);
		}
	}
}

/// <summary>
/// 5×5をリセット（引き分け時）
/// </summary>
void SceneTest::Reset5x5()
{
	int base_x = LINE_BASE_X;
	int base_y = LINE_BASE_Y;

	// 盤面データをクリア（5×5全て）
	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++){
			board.board_size[row][col] = 0;
		}
	}

	// 丸と×を再初期化（5×5）
	int cell_size = 666 / 5;	// 133.2px
	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++){
			int x = base_x - 133 + col * cell_size;
			int y = base_y - 133 + row * cell_size;

			maru_5x5[row][col] = Maru("maru.png", x+8, y+5);
			batu_5x5[row][col] = Batu("batu.png", x-15, y-15);
		}
	}

	// フラグをリセット
	check.playerwinner = false;
	check.npcwinner = false;
	check.full = false;
	decide = false;
	timer = 0;
}

/// <summary>
/// 更新処理
/// </summary>
void SceneTest::Update()
{
	//	勝敗が決まっていない場合のみマウスクリック処理
	if (!decide && mouse.ClicPress())
	{
		//	マウス座標
		int mx = mouse.GetX() - LINE_BASE_X;
		int my = mouse.GetY() - LINE_BASE_Y;

		// 3×3か5×5か判定して呼び分ける
		if (!check.draw) {
			// 3×3の場合
			turn.TurnChange(board, mx, my);
		}
		else {
			// 5×5の場合
			int mx_5x5 = mouse.GetX() - (LINE_BASE_X - 133);
			int my_5x5 = mouse.GetY() - (LINE_BASE_Y - 133);
			turn.TurnChange5x5(board, mx_5x5, my_5x5);
		}
	}

	//	そろったら勝ったと判定　それぞれ
	if (!check.draw) {
		// 3×3の判定
		int board_3x3[3][3];
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				board_3x3[row][col] = board.board_size[row][col];
			}
		}

		if (check.CheckWin(board_3x3, 1))
		{
			timer++;
			check.playerwinner = true;
			decide = true;	// 勝敗決定
		}
		else if (check.CheckWin(board_3x3, 2))
		{
			timer++;
			check.npcwinner = true;
			decide = true;	// 勝敗決定
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
				decide = false;	// 5×5では置き続けられる

				//	丸と×をリセット
				this->ResetMaruBatu();

				board.SetPos((550 - 133), (330 - 133));

				//	線の基準を決める
				int base_x = LINE_BASE_X - 133;
				int base_y = LINE_BASE_Y - 133;
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
	}
	else {
		// 5×5の判定
		int board_5x5[5][5];
		for (int row = 0; row < 5; row++){
			for (int col = 0; col < 5; col++){
				board_5x5[row][col] = board.board_size[row][col];
			}
		}

		if (check.CheckWin2(board_5x5, 1))
		{
			timer++;
			check.playerwinner = true;
			decide = true;	// 勝敗決定
		}
		else if (check.CheckWin2(board_5x5, 2))
		{
			timer++;
			check.npcwinner = true;
			decide = true;	// 勝敗決定
		}
		//	5×5での引き分けの場合
		else
		{
			// 盤面が全部埋まっているか確認
			check.full = true;

			for (int row = 0; row < 5; row++)
			{
				for (int col = 0; col < 5; col++)
				{
					if (board.board_size[row][col] == 0)
					{
						check.full = false;
					}
				}
			}

			// 全部埋まっていたら5×5をリセット
			if (check.full)
			{
				this->Reset5x5();
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
		decide = false;
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

	if (!check.draw) {
		//	丸と×の描画（3×3）
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				if (board.board_size[row][col] == 1){
					// 丸を描画
					maru[row][col].Draw();
				}
				else if (board.board_size[row][col] == 2){
					// ×を描画
					batu[row][col].Draw();
				}
			}
		}
	}
	else {
		//	丸と×の描画（5×5）
		for (int row = 0; row < 5; row++){
			for (int col = 0; col < 5; col++){
				if (board.board_size[row][col] == 1){
					// 丸を描画
					maru_5x5[row][col].Draw();
				}
				else if (board.board_size[row][col] == 2){
					// ×を描画
					batu_5x5[row][col].Draw();
				}
			}
		}
	}

	//	UIの描画
	ui.Draw();
	ui2.Draw();

	//	そろったと文字列でそれぞれ描画
	if (!check.draw) {
		int board_3x3[3][3];
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				board_3x3[row][col] = board.board_size[row][col];
			}
		}

		if (check.CheckWin(board_3x3, 1)){
			check.Draw();
		}
		else if (check.CheckWin(board_3x3, 2)){
			check.Draw2();
		}
		else {
			check.Draw3();
		}
	}
	else {
		int board_5x5[5][5];
		for (int row = 0; row < 5; row++){
			for (int col = 0; col < 5; col++){
				board_5x5[row][col] = board.board_size[row][col];
			}
		}

		if (check.CheckWin2(board_5x5, 1)){
			check.Draw();
		}
		else if (check.CheckWin2(board_5x5, 2)){
			check.Draw2();
		}
	}

	// ターン表示（勝敗が決まっていない場合のみ)
	if (!decide) {
		SetFontSize(40);
		
		// turn クラスのターン番号を取得するか、現在のターンを判定する必要があります
		// ここでは簡易的に、盤面の埋まり具合でターンを判定します
		int count = 0;
		if (!check.draw) {
			// 3×3のターン計算
			for (int row = 0; row < 3; row++){
				for (int col = 0; col < 3; col++){
					if (board.board_size[row][col] != 0) {
						count++;
					}
				}
			}
		}
		else {
			// 5×5のターン計算
			for (int row = 0; row < 5; row++){
				for (int col = 0; col < 5; col++){
					if (board.board_size[row][col] != 0) {
						count++;
					}
				}
			}
		}

		// count が偶数なら丸の番、奇数なら×の番
		if (count % 2 == 0) {
			DrawString(600, 150, "今は丸の番です", GetColor(255, 255, 0));
		}
		else {
			DrawString(600, 150, "今は×の番です", GetColor(255, 255, 0));
		}
	}
}

/// <summary>
/// 音声再生処理
/// </summary>
void SceneTest::Sound_play()
{
}
