#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Image.h"


//�e�X�g�V�[�����Ǘ�����N���X
class SplashScene : public GameObject
{

	int hSplash_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SplashScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};