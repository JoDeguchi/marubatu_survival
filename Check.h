#pragma once
#include "Dxlib.h"
#include "Marubatu.h"

/// <summary>
/// 丸ばつそろったかどうかを判定するクラス
/// </summary>
class Check:public Batu
{
	Board board;
	Maru maru[3][3];
	Batu batu[3][3];
public:

	bool playerwinner = false;	//	プレイヤーの勝利
	bool npcwinner = false;		//	NPCの勝利
	bool draw = false;			//	引き分け
	bool full;			//	フルか

	bool CheckWin(int board[3][3],int player);
	void Draw();
	void Draw2();
	void Draw3();
};