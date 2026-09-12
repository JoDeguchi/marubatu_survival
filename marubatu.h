#pragma once
#include "DxLib.h"		// DxLib
#include"board.h"

//	継承
//	丸クラス
class Maru :public Board
{
	int turn = 0;
public:
	//	デフォルト
	Maru() {};
	//	コンストラクタ
	Maru(std::string arg_file_path, int arg_x, int arg_y);
	void Draw();
	
};

//	×クラス
class Batu :public Maru
{
	Maru maru;
public:
	//	デフォルト
	Batu() {};
	//	コンストラクタ
	Batu(std::string arg_file_path, int arg_x, int arg_y);
	void Draw();
};
