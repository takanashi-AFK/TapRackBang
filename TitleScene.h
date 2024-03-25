#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/Input.h"
#include "AudioManager.h"

//�e�X�g�V�[�����Ǘ�����N���X
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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};