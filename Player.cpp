#include "Player.h"

Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	hPlayerModel_ = Model::Load("TestBird.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");

	if (pSM->GetCurrentScene() == SCENE_ID_SCENARIO1) {
		SinpleStage* pStage = (SinpleStage*)FindObject("SinpleStage");
		hGroundModelHandle_ = pStage->GetModelHandle();
	}

}

void Player::Update()
{
	PlayerMove();
	//ステージのオブジェクトを探す
		//カメラ移動
	Camera::SetPosition(XMFLOAT3(transform_.position_.x, transform_.position_.y + 3	, transform_.position_.x));
	Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y,transform_.position_.z + 8));

}

void Player::Draw()
{
	Model::SetTransform(hPlayerModel_, transform_);
	Model::Draw(hPlayerModel_);
}

void Player::Release()
{
}

void Player::PlayerMove()
{
	vPlayerPos_ = XMLoadFloat3(&transform_.position_);
	float speed = 0.1f;
	vMoveX_ = { speed,0.0f,0.0f,0.0f };
	vMoveZ_ = { 0.0f,0.0f,speed,0.0f };

	XMMATRIX rotateMatY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

	vMoveZ_ = XMVector3TransformCoord(vMoveZ_, rotateMatY);
	vMoveX_ = XMVector3TransformCoord(vMoveX_, rotateMatY);

	if (Input::IsKey(DIK_W)) {
		vPlayerPos_ += vMoveZ_;
		XMVector3Normalize(vMoveZ_);
	}

	if (Input::IsKey(DIK_A)) {
		vPlayerPos_ -= vMoveX_;
		XMVector3Normalize(vMoveX_);
	}

	if (Input::IsKey(DIK_S)) {
		vPlayerPos_ -= vMoveZ_;
		XMVector3Normalize(vMoveZ_);
	}

	if (Input::IsKey(DIK_D)) {
		vPlayerPos_ += vMoveX_;
		XMVector3Normalize(vMoveX_);
	}

	XMVector3Normalize(vPlayerPos_);
	XMStoreFloat3(&transform_.position_, vPlayerPos_);

	ImGui::Begin("Debug");
	/////////////////////接地処理//////////////////////
	RayCastData groundRayData;
	groundRayData.start = transform_.position_;
	groundRayData.dir = XMFLOAT3(0, -1, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit) {
		transform_.position_.y = 0.f;
	ImGui::Text("%f", groundRayData.dist);
	}
	///////////////////////////////////////////////////
	ImGui::End();
}
