#include "KeyReader.h"

KeyReader::KeyReader()
{
	// キー状態配列を初期化
	for (int cnt = 0; cnt < 256; cnt++)
	{
		this->key_state_arr[cnt] = 0;
	}
}

void KeyReader::Read()
{
	for (int cnt = 0; cnt < 256; cnt++)
	{
		old_key_state_arr[cnt] = key_state_arr[cnt];
	}

	GetHitKeyStateAll(this->key_state_arr);

	this->key_press = false;
	for (int cnt = 0; cnt < 256; cnt++)
	{
		if (this->key_state_arr[cnt] != 0)
		{
			this->key_press = true;
		}
	}
}

bool KeyReader::CheckKey(int arg_key_code)
{
	// 指定されたキーの状態をチェック
	if (this->key_state_arr[arg_key_code] == 1 && old_key_state_arr[arg_key_code] == 0)
	{
		// 押されていればtrueを返す
		return true;
	}
	// 押されていなければfalseを返す
	return false;
}

bool KeyReader::KeyPress()
{
	return this->key_press;
}