#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Image.h"


//テストシーンを管理するクラス
class SplashScene : public GameObject
{

	int hSplash_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SplashScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};