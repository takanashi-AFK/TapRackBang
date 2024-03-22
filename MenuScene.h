#pragma once
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "AudioManager.h"

//テストシーンを管理するクラス
class MenuScene : public GameObject
{

	int hScenario1ButtonNormal_;
	int hScenario1ButtonSelected_;
	int hBackGround_;
	Transform buttonTransform_;

	XMFLOAT3 mousePos_;
	XMFLOAT3 size;
	bool isPushable;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	MenuScene(GameObject* parent);

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