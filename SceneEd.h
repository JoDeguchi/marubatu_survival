#pragma once
#include "SceneBase.h"

#include "Game.h"			// ゲームクラス
#include "Background.h"		// 背景クラス
#include "Mouse.h"
#include "UI.h"
#include "String.h"

class Check;

/// <summary>
/// エンディング（シーン）
/// </summary>
class SceneEd : public SceneBase
{
	/// <summary>
	/// Gameインスタンスのポインター
	/// </summary>
	Game* game_ptr;

	//	勝利判定（共通）
	Check check_data;

	// 背景クラスのインスタンス
	Background bg;
	//	UI画像
	UI CircleVictory;	// 〇勝ち
	UI CrossVictory;	// ×勝ち
	// マウス
	Mouse mouse;

	// 文字クラスのインスタンス
	String string0;	// タイトルに戻る文字
	String string1;	// ゲーム終了文字

	UI confetti;
	UI confetti2;

public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_game_ptr">Gameインスタンスのポインター</param>
	SceneEd(Game* arg_game_ptr)
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
	void Sound_play() override {};
};
