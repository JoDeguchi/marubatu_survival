#pragma once
#include "SceneBase.h"

#include "Game.h"
#include "Background.h"
#include "KeyReader.h"
#include "Mouse.h"
#include "UI.h"

/// <summary>
/// ルール説明画面（シーン）
/// </summary>
class Rule : public SceneBase
{
	/// <summary>
	/// Game インスタンスのポインター
	/// </summary>
	Game* game_ptr;

	/// <summary>
	/// キーリーダー インスタンス
	/// </summary>
	KeyReader key_state;

	// 背景クラスのインスタンス
	Background bg0;

	// マスコットキャラクターのインスタンス
	Background mascot;
	Background mascot2;

	// マウスのインスタンス
	Mouse mouse;

	UI rule;

	int se_click;

public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_game_ptr">Game インスタンスのポインター</param>
	Rule(Game* arg_game_ptr)
	{
		// Game インスタンスのポインターを保持
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
