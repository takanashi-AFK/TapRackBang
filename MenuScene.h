#pragma once
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "AudioManager.h"

//�e�X�g�V�[�����Ǘ�����N���X
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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	MenuScene(GameObject* parent);

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