#include "Line.h"

void Line::SetLinePos(int arg_x, int arg_y, int arg_x2, int arg_y2)
{
	//	線の座標
	this->line_x = arg_x;
	this->line_y = arg_y;
	//	線の座標終端
	this->line_x2 = arg_x2;
	this->line_y2 = arg_y2;
}

void Line::Draw()
{
	//	線の描画
	DrawLine(this->line_x, this->line_y, this->line_x2, this->line_y2, GetColor(255, 255, 255));
}	