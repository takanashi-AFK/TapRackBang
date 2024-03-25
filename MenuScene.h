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

//�e�X�g�V�[�����Ǘ�����N���X
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
};