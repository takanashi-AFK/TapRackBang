#include "PlayScene.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"),hModel_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	hModel_ = Model::Load("SkySphere/SkySphere.fbx");
	assert(hModel_ >= 0);
	transform_.position_.y = -30;
}


//更新
void PlayScene::Update()
{
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

	if (ImGui::CollapsingHeader("position_")) {
		ImGui::SliderFloat("position_x", &transform_.position_.x, -100.0f, 100.0f);
		ImGui::SliderFloat("position_y", &transform_.position_.y, -100.0f, 100.0f);
		ImGui::SliderFloat("position_z", &transform_.position_.z, -100.0f, 100.0f);
		if (ImGui::Button("ResetPos")) {
			transform_.position_.x = 0;
			transform_.position_.y = -30;
			transform_.position_.z = 0;
		}
	}

	if (ImGui::CollapsingHeader("rotate_")) {
		ImGui::SliderFloat("rotate_x", &transform_.rotate_.x, -180.f, 180.f);
		ImGui::SliderFloat("rotate_y", &transform_.rotate_.y, -180.f, 180.f);
		ImGui::SliderFloat("rotate_z", &transform_.rotate_.z, -180.f, 180.f);
		if (ImGui::Button("ResetRot")) {
			transform_.rotate_.x = 0;
			transform_.rotate_.y = 0;
			transform_.rotate_.z = 0;
		}
	}

	if (ImGui::CollapsingHeader("scale_")) {
		ImGui::SliderFloat("scale_x", &transform_.scale_.x, -100.f, 100.f);
		ImGui::SliderFloat("scale_y", &transform_.scale_.y, -100.f, 100.f);
		ImGui::SliderFloat("scale_z", &transform_.scale_.z, -100.f, 100.f);
		if (ImGui::Button("ResetSca")) {
			transform_.scale_.x = 1;
			transform_.scale_.y = 1;
			transform_.scale_.z = 1;
		}
	}
	ImGui::End();

}

//描画
void PlayScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void PlayScene::Release()
{
}
