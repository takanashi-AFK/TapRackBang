#include "Player.h"

const float MODEL_SIZE{ 1 };
Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	speed = 0.1f;
	hPlayerModel_ = Model::Load("TestBird.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");
	transform_.position_.y = 20;	
}

void Player::Update()
{
	mouseMove_ = Input::GetMouseMove();
	PlayerMove();

	XMVECTOR nVMoveZ = XMVector3Normalize(vMoveZ_);

	//�X�e�[�W�̃I�u�W�F�N�g��T�� 
	//�J�����ړ�
	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	hGroundModelHandle_ = pStage->GetModelHandle();

	/////////////////////�ڒn����//////////////////////
	RayCastData groundRayData;
	groundRayData.start = transform_.position_;
	groundRayData.start.y = transform_.position_.y - MODEL_SIZE/2;
	groundRayData.dir = XMFLOAT3(0, -1, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit) {
		transform_.position_.y -= groundRayData.dist;
	}
	//////////////////////////////////////////////////

	////////////////�ǐڐG����////////////////////////

	
	/*�E�����̃��C�L���X�g*/   {
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x = transform_.position_.x + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist <= speed) {
			transform_.position_.x -= speed;
		}
	}

	/*�������̃��C�L���X�g*/   {
		
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x = transform_.position_.x - MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(-1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.x += speed;
		}
	}

	/*�������̃��C�L���X�g*/   {
		
		groundRayData.start = transform_.position_;
		groundRayData.start.z = transform_.position_.z + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, 1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.z -= speed;
		}
	}

	/*��O�����̃��C�L���X�g*/ {
		// Z���������̃��C�L���X�g
		groundRayData.start = transform_.position_;
		groundRayData.start.z = transform_.position_.z - MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, -1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.z += speed;
		}
	}

	////XMMATRIX rotateMatY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//XMFLOAT3 distanceBehindPlayer = {0.f,3.f,-5.f}; // �v���C���[���f���̌��ɔz�u���鋗��

	//XMVECTOR vPPos = XMLoadFloat3(&transform_.position_);
	////XMVECTOR vDistance = XMLoadFloat3(&distanceBehindPlayer);
	////XMVECTOR vNewPos = XMVectorSubtract(vDistance, vPPos);
	////XMVector3TransformCoord(vNewPos, rotateMatY);

	////XMFLOAT3 rotatedCameraPosition;
	////XMStoreFloat3(&rotatedCameraPosition, vNewPos);

	//XMFLOAT3 cameraPosition{};
	//cameraPosition.x = transform_.position_.x - distanceBehindPlayer.x * XMVectorGetX(nVMoveZ);
	//cameraPosition.y = transform_.position_.y + distanceBehindPlayer.y;
	//cameraPosition.z = transform_.position_.z - distanceBehindPlayer.z * XMVectorGetZ(nVMoveZ);

	//XMFLOAT3 focusPosition{};
	//focusPosition.x = transform_.position_.x + XMVectorGetX(nVMoveZ);
	//focusPosition.z = transform_.position_.z + XMVectorGetZ(nVMoveZ);

	//Camera::SetPosition(cameraPosition);
	//Camera::SetTarget(transform_.position_.x, transform_.position_.y-2, transform_.position_.z + 8);

	//vPPos��distance���Ȃ��x�N�g�����쐬����
	

	if (Input::IsKey(DIK_E)) {
		transform_.rotate_.y += 2;
	}
	if (Input::IsKey(DIK_Q)) {
		transform_.rotate_.y -= 2;
	}
	
	
	///////////////////////////////////////////////////
	
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

	vMoveX_ = { speed,0.0f,0.0f,0.0f };
	vMoveZ_ = { 0.0f,0.0f,speed,0.0f };

	vPlayerPos_ = XMLoadFloat3(&transform_.position_);
	XMMATRIX rotateMatY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

	vMoveX_ = XMVector3TransformCoord(vMoveX_, rotateMatY);
	vMoveZ_ = XMVector3TransformCoord(vMoveZ_, rotateMatY);

	if (Input::IsKey(DIK_W)) {
		XMVector3Normalize(vMoveZ_);
		vPlayerPos_ += vMoveZ_;
	}

	if (Input::IsKey(DIK_A)) {
		XMVector3Normalize(vMoveX_);
		vPlayerPos_ -= vMoveX_;
	}

	if (Input::IsKey(DIK_S)) {
		XMVector3Normalize(vMoveZ_);
		vPlayerPos_ -= vMoveZ_;
	}

	if (Input::IsKey(DIK_D)) {
		XMVector3Normalize(vMoveX_);
		vPlayerPos_ += vMoveX_;
	}
	XMVector3Normalize(vPlayerPos_);
	XMStoreFloat3(&transform_.position_, vPlayerPos_);
}
