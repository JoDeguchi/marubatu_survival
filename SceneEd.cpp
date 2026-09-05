#include "SceneEd.h"

#include "DxLib.h"


void SceneEd::Init()
{
	// ”wŒi‰æ‘œ‚Ì“Ç
	this->bg0.Load_image("ed.png");

	



}

/// <summary>
/// •`‰æˆ—
/// </summary>
void SceneEd::Draw()
{
	// ”wŒi0‚ğ•`‰æ
	//this->bg0.Draw();


	SetFontSize(64);
	DrawString(500, 100, "››‚ÌŸ‚¿", GetColor(255, 255, 255));
	DrawString(600, 100, "ƒ^ƒCƒgƒ‹‚É–ß‚é", GetColor(255, 255, 255));
	DrawString(600, 100, "ƒQ[ƒ€I—¹", GetColor(255, 255, 255));

}
