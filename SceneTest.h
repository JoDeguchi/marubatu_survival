#pragma once
#include "SceneBase.h"

#include "Game.h"			// ゲームクラス
#include "Background.h"		// 背景クラス
#include "board.h"			// スプライトクラス
#include "KeyReader.h"		// キーリーダー
#include "Line.h"
#include "marubatu.h"
#include "Mouse.h"
#include "UI.h"
#include "Check.h"

/// <summary>
/// テスト（シーン）
/// </summary>
class SceneTest : public SceneBase
{
	/// <summary>
	/// Gameインスタンスのポインター
	/// </summary>
	Game* game_ptr = nullptr;

	/// <summary>
	/// キーリーダーインスタンス
	/// </summary>
	KeyReader key_state;

	// 背景クラスのインスタンス
	Background bg0;

	// スプライトクラスのインスタンス
	Board board;

	//	線のインスタンス
	Line line_w[2];
	Line line_h[2];

	//	丸とバツのインスタンス
	Maru maru[3][3];
	Batu batu[3][3];	

	//	ターン
	int turn = 0;

	//	マウス
	Mouse mouse;

	//	うい
	UI ui;
	UI ui2;

	//	勝利判定
	Check check;

	float timer = 0.0f;

public:

	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_game_ptr">Gameインスタンスのポインター</param>
	SceneTest(Game* arg_game_ptr)
	{
		// Gameインスタンスのポインターを保持
		this->game_ptr = arg_game_ptr;
	}

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init() override;

	/// <summary>
	/// 入力処理
	/// </summary>
	void Input() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;
	
	/// <summary>
	/// 音声再生処理
	/// </summary>
	void Sound_play() override;

};
