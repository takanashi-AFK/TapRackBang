#pragma once
#include "Engine/Sprite.h"
#include "Engine/Transform.h"

/// <summary>
/// トランジションを管理するためのクラス
/// シーンとシーンの合間にスプライトをはさみ、その透明度を変える、位置を変えるなどしてトランジションをかける
/// </summary>

enum TRANSITION_TYPE
{
	TID_NONE,
	TID_BLACKOUT,
	TID_MAX,
};
namespace Transition
{
	//実行処理
	HRESULT Initialize();
	void Update();
	void Draw();
	void Release();

	void SetType(TRANSITION_TYPE tType);
	void SetTimer(int time);
	void Execute();
	bool GetIsActive();

	void Blackout();
};
