#pragma once
#include "DxLib.h"		// DxLib
#include"Sprite.h"

//	åpè≥
class Maru :public Sprite
{
	int pos_x = 0;
	int pos_y = 0;

public:

	void Set_pos(int arg_x, int arg_y);
	void Draw();
	
};

