#include "marubatu.h"

//----------------------------------------------------------
//	まる
//---------------------------------------------------------
Maru::Maru(std::string arg_file_path, int arg_x, int arg_y)
{
	this->Load_image(arg_file_path);

	this->pos_x = arg_x;
	this->pos_y = arg_y;
}

void Maru::Draw()
{
	//	丸の描画
	DrawGraph(this->pos_x, this->pos_y, this->image_hnd, true);
}

//------------------------------------------------------------
//	ばつ
//-----------------------------------------------------------
Batu::Batu(std::string arg_file_path, int arg_x, int arg_y)
{
	this->Load_image(arg_file_path);

	this->pos_x = arg_x;
	this->pos_y = arg_y;
}
void Batu::Draw()
{
	//	丸の描画
	DrawGraph(this->pos_x, this->pos_y, this->image_hnd, true);
}