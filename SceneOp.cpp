#include "SceneOp.h"
#include "DxLib.h"

void SceneOp::Init()
{   
	// 背景画像
	bg = Background("background.png", 0, 0);
	//	UI画像 (画像と座標)の初期値
	mascot		= UI("aikon.png", 0, 500);					//  マスコットキャラ
	mascot2		= UI("aikon2.png", 1000, 500);				//  マスコットキャラ２
	title		= UI("tytle.png", 150, -20);				//	タイトル名
	StartBotan  = UI("StartBotan.png", 450, 400);			//	スタートボタン
	RuleBotan	= UI("RuleBotan.png", 550, 600);			//	ルールボタン

	// マウス状態をリセット
	mouse.Reset();
}

void SceneOp::Input()
{
	mouse.Read();     // マウス読み込み
}

void SceneOp::Update()
{
	// マウス座標取得
	int mx = mouse.GetX();
	int my = mouse.GetY();

	//	マウスと画像（スタート、ルールボタン）のあたり判定を毎フレーム読む
	//	画像縮小に必要
	StartBotan.Hit(mx, my);
	RuleBotan.Hit(mx, my);

	// クリック時の判定（押された瞬間）
	//	スタートボタン
	if (mouse.ClicPress())
	{
		if (StartBotan.Hit(mx, my))
		{
			game_ptr->ChageScene(1);	//	ゲームシーンへ
			return;
		}
	}

	// クリック離された瞬間のみの判定
	//	ルールボタン
	if (mouse.ClicRelease())
	{
		if (RuleBotan.Hit(mx, my))
		{
			game_ptr->ChageScene(3);	//	ルール説明シーンへ
			return;
		}
	}
}

void SceneOp::Draw()
{
	// 背景
	bg.Draw();

	mascot.Draw();		//  マスコットキャラ
	mascot2.Draw();		//  マスコットキャラ2
	title.Draw();		//	タイトル名	
	StartBotan.Draw();	//	スタートボタン
	RuleBotan.Draw();	//	ルールボタン
		
}
