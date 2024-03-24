#include "PlayScene.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"),hModel_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<SkySphere>(this);
}


//更新
void PlayScene::Update()
{
#ifdef _DEBUG
	ImGui::Begin("rueausu");
	ImGui::Text("Play");
	if (ImGui::Button("toMenu")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
	if (ImGui::Button("toTitle")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
#endif // DEBUG

	
}



//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
