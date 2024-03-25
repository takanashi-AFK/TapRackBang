#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Input.h"
#include "AudioManager.h"

//テストシーンを管理するクラス
class TitleScene : public GameObject
{
	XMFLOAT3 mousePos_;
	Transform uiTransform;
	int hBackGround_;
	int pressSpaceKey;
	int opacity;
	int alpha;
	bool increasing;
	Text* ptext;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};