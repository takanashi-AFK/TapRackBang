#pragma once
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "AudioManager.h"
#include "Player.h"
#include "SimpleStage.h"
#include "MenuUI.h"

//テストシーンを管理するクラス
class MenuScene : public GameObject
{
	int hBackGround_;
	int titleImage;
	int frame;

	Player* pPlayer;
	XMFLOAT3 pos;

	XMFLOAT3 campos;
	XMFLOAT3 target;

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
};