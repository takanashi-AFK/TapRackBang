#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "AudioManager.h"
#include "Engine/SceneManager.h" 
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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	bool IsMouseInRect();
};

