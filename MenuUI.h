#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "AudioManager.h"
#include "Engine/SceneManager.h" 
#include "ImGuiManager.h"
class MenuUI :public GameObject
{
private:
	int hScenario1ButtonNormal_;
	int hScenario1ButtonSelected_;
	Transform buttonTransform_;
	Transform titleTrans;
	XMFLOAT3 size;
	XMFLOAT3 mousePos_;
	bool isPushable;
	int titleImage;

public:
	MenuUI(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	bool IsMouseInRect();
};

