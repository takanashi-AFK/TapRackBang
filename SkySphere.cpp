#include "SkySphere.h"

SkySphere::SkySphere(GameObject* parent)
{
}

void SkySphere::Initialize()
{
	hSkySphere = Model::Load("SkySphere/SkySphere.fbx");
	assert(hSkySphere >= 0);
}

void SkySphere::Update()
{
#ifdef _DEBUG
	ImGui::Begin("rueausu");

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
#endif // _DEBUG
}

void SkySphere::Draw()
{
	Model::SetTransform(hSkySphere, transform_);
	Model::Draw(hSkySphere);
}

void SkySphere::Release()
{
}
