#pragma once
#include "Dxlib.h"
#include "Marubatu.h"

/// <summary>
/// 丸ばつそろったかどうかを判定するクラス
/// </summary>
class Check:public Batu
{
	Board board;

public:

	bool playerwinner = false;	//	プレイヤーの勝利
	bool npcwinner = false;		//	NPCの勝利
	bool draw = false;			//	引き分け
	bool full = false;			//	フル（3×3が全て埋まったか）

	//	3マスのときの勝利パターン
	bool CheckWin(int board[3][3],int player);
	//	5マスのときの勝利パターン（4マスそろえたら勝ち）
	bool CheckWin2(int board[5][5], int player);

	void Draw();
	void Draw2();
	void Draw3();
};