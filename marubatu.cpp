#include "marubatu.h"

void Maru::Set_pos(int arg_x, int arg_y)
{
	//	ŠÛ‚ÌÀ•W
	this->pos_x = arg_x;
	this->pos_y = arg_y;
}

void Maru::Draw()
{
	//	ŠÛ‚Ì•`‰æ
	DrawGraph(this->pos_x, this->pos_y, this->image_hnd, true);
}