#include "PlayScene.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
}


//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
	pText->Draw(30, 30, "Play");
}

//開放
void PlayScene::Release()
{
}
