#include "Player.h"

const float MODEL_SIZE{ 1 };
Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	hPlayerModel_ = Model::Load("SimpleCube.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");
	transform_.position_.y = 20;
}

void Player::Update()
{
	



	//ステージのオブジェクトを探す 
	//カメラ移動
	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	hGroundModelHandle_ = pStage->GetModelHandle();

	/////////////////////接地処理//////////////////////
	RayCastData groundRayData;
	groundRayData.start = transform_.position_;
	groundRayData.start.y = transform_.position_.y - MODEL_SIZE/2;
	groundRayData.dir = XMFLOAT3(0, -1, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit) {
		transform_.position_.y -= groundRayData.dist;
	}
	//////////////////////////////////////////////////

	////////////////壁接触処理////////////////////////

	// 右方向のレイキャスト
	groundRayData.dist = 99999.f;
	groundRayData.start = transform_.position_;
	groundRayData.start.x = transform_.position_.x + MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(1, 0, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist <= 0.1f) {
		transform_.position_.x -= 0.1f;
	}

	// 左方向のレイキャスト
	groundRayData.dist = 99999.f;
	groundRayData.start = transform_.position_;
	groundRayData.start.x = transform_.position_.x - MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(-1, 0, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist < 0.1f) {
		transform_.position_.x += 0.1f; 
	}

	// Z軸正方向のレイキャスト
	groundRayData.start = transform_.position_;
	groundRayData.start.z = transform_.position_.z + MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(0, 0, 1);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist < 0.1f) {
		transform_.position_.z -= 0.1f;
	}

	// Z軸負方向のレイキャスト
	groundRayData.start = transform_.position_;
	groundRayData.start.z = transform_.position_.z - MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(0, 0, -1);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist < 0.1f) {
		transform_.position_.z += 0.1f; // 減算ではなく加算する
	}

	Camera::SetPosition(transform_.position_.x, transform_.position_.y + 3, transform_.position_.z - 3);
	Camera::SetTarget(transform_.position_.x, transform_.position_.y, transform_.position_.z + 8);

	if (Input::IsKey(DIK_E)) {
		transform_.rotate_.y += 2;
	}
	if (Input::IsKey(DIK_Q)) {
		transform_.rotate_.y -= 2;
	}
	
	/*groundRayData.start = transform_.position_;
	groundRayData.start.x = transform_.position_.x - MODEL_SIZE/2;
	groundRayData.dir = XMFLOAT3(-1, 0, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit&&groundRayData.dist < 1) {
		transform_.position_.x -= groundRayData.dist;
	}

	
	groundRayData.start = transform_.position_;
	groundRayData.start.z = transform_.position_.z + MODEL_SIZE /2;
	groundRayData.dir = XMFLOAT3(0, 0, 1);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist < 1) {	
		transform_.position_.z -= groundRayData.dist;
	}

	groundRayData.start = transform_.position_;
	groundRayData.dir = XMFLOAT3(0, 0, -1);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit && groundRayData.dist < 2) {
		transform_.position_.z -= groundRayData.dist;
	}*/
	///////////////////////////////////////////////////
	PlayerMove();
	ImGui::Begin("Debug");
	ImGui::Text("x=%f", transform_.position_.x);
	ImGui::Text("y=%f", transform_.position_.y);
	ImGui::Text("z=%f", transform_.position_.z);
	

	
	ImGui::End();
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

	
}
