#include "PlayScene.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
}


//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(30, 30, "Play");
}

//�J��
void PlayScene::Release()
{
}
