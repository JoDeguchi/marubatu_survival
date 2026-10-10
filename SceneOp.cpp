#include "SceneOp.h"
#include "DxLib.h"

int SceneOp::bgm_title = -1;
int SceneOp::se_mascot = -1;

void SceneOp::Init()
{   
	// 背景画像
	bg = Background("background.png", 0, 0);
	//	UI画像 (画像と座標)の初期値
	mascot		= UI("aikon.png", 0, 500);					//  マスコットキャラ
	mascot2		= UI("aikon2.png", 1000, 800);				//  マスコットキャラ２
	title		= UI("tytle.png", 150, -20);				//	タイトル名
	StartBotan  = UI("StartBotan.png", 450, 400);			//	スタートボタン
	RuleBotan	= UI("RuleBotan.png", 550, 600);	//	ルールボタン

	// SE読み込み
	se_click = LoadSoundMem("decision_1.mp3");

	// マスコットSE読み込み
	if (se_mascot == -1)
	{
		se_mascot = LoadSoundMem("pyopyo.mp3");   // 実際のファイル名に
	}

	// BGM読み込み
	if (bgm_title == -1) {

		bgm_title = LoadSoundMem("BGM1.mp3");
		ChangeVolumeSoundMem(150, bgm_title);               // BGMはSEより小さめが聞きやすい
		//PlaySoundMem(bgm_title, DX_PLAYTYPE_LOOP);          // ループ再生
	}

	// 鳴っていない時だけ再生
	if (CheckSoundMem(bgm_title) == 0)
	{
		PlaySoundMem(bgm_title, DX_PLAYTYPE_LOOP);
	}

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
	StartBotan.HitImg(mx, my);
	RuleBotan.HitImg(mx, my);

	// クリック時の判定（押された瞬間）
	//	スタートボタン
	if (mouse.ClicRelease())
	{
		if (StartBotan.HitImg(mx, my))
		{
			PlaySoundMem(se_click, DX_PLAYTYPE_BACK);
			/*StopSoundMem(bgm_title);*/     // BGM停止
			game_ptr->ChageScene(1);	//	ゲームシーンへ
			return;
		}

		// マスコットをクリック
		if (mascot.HitImg(mx, my) || mascot2.HitImg(mx, my))
		{
			PlaySoundMem(se_mascot, DX_PLAYTYPE_BACK);
		}
	}

	// クリック離された瞬間のみの判定
	//	ルールボタン
	if (mouse.ClicRelease())
	{
		if (RuleBotan.HitImg(mx, my))
		{
			PlaySoundMem(se_click, DX_PLAYTYPE_BACK);
			game_ptr->ChageScene(3);	//	ルール説明シーンへ
			return;
		}
	}
	
	


	
	// フェーズ1：それぞれの位置まで移動
	if (UI_timer == 0)
	{
		if (mascot2.GetY() > 500 || mascot.GetY() < 800)
		{
			mascot.Move(0, 20);
			mascot2.Move(0, -20);
		}
		else
		{
			UI_timer = 1;
		}
	}

	// フェーズ2：停止して120フレーム待つ
	else if (UI_timer >= 1 && UI_timer <= 120)
	{
		mascot.Move(0, 0);
		mascot2.Move(0, 0);

		UI_timer++;

		if (UI_timer > 120)
		{
			UI_timer = 121;
		}
	}

	// フェーズ3：反対方向へ移動
	else if (UI_timer == 121)
	{
		if (mascot2.GetY() < 800 || mascot.GetY() > 500)
		{
			mascot.Move(0, -20);
			mascot2.Move(0, 20);
		}
		else
		{
			UI_timer = 122;
		}
	}

	// フェーズ4：停止して120フレーム待ち、最初に戻る
	else if (UI_timer >= 122)
	{
		mascot.Move(0, 0);
		mascot2.Move(0, 0);

		UI_timer++;

		if (UI_timer >= 242)
		{
			UI_timer = 0;
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
