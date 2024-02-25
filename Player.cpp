#include "Player.h"

const float MODEL_SIZE{ 1 };
//���炩����30�x��90�x�̃x�N�g��������Ă���
//���̊p�x�܂ŊJ������Acampos�����̃x�N�g���ɂ����Ⴄ


Player::Player()
{
}

Player::Player(GameObject* parent)
			:GameObject(parent, "Player")
{
}

void Player::Initialize()
{
	speed = 0.1f;
	hPlayerModel_ = Model::Load("TestBird.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");
	transform_.position_.y = 20;	
	sensitivity = 0.2f;
	playerCameraDistance = 20.f;
	Instantiate<Gun>(this);

	verticalP = { 0,1,0,0 };
	XMMATRIX upRotateY = XMMatrixRotationY(30);
	upLimit = XMVector3Transform(verticalP, upRotateY);
	XMVECTOR downLimit = {};
}

void Player::Update()
{
	PlayerMove();

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
	

	mouseMove_ = Input::GetMouseMove();
	XMFLOAT3 cameraPosition = Camera::GetPosition();

	//�J��������v���C���[�֌������x�N�g�����쐬�A�P�ʃx�N�g����
	playerForward = XMLoadFloat3(&transform_.position_) - XMLoadFloat3(&cameraPosition);
	playerForward = XMVector3Normalize(playerForward);

	//�e�����̈ړ���(���x������)
	auto rotX = XMConvertToRadians(mouseMove_.x * sensitivity);
	auto rotY = XMConvertToRadians(mouseMove_.y * sensitivity);

	//�}�E�X�̈ړ��ʂ����]�s����쐬
	XMMATRIX matRotate = XMMatrixRotationX(rotY) * XMMatrixRotationY(rotX);
	

	XMMATRIX matTranslateToPlayer = XMMatrixTranslation(transform_.position_.x, transform_.position_.y, transform_.position_.z);
	XMMATRIX matTranslateBack = XMMatrixTranslation(-transform_.position_.x, -transform_.position_.y, -transform_.position_.z);
	XMMATRIX matCombined = matTranslateToPlayer * matRotate * matTranslateBack;

	// �J�����̈ʒu�𒆐S�ɂ��ĉ�]�s���K�p���A���̌��ʂ��v���C���[�̈ʒu�ɕ��s�ړ�������
	XMVECTOR cameraPositionTranslated = XMVector3Transform(XMLoadFloat3(&cameraPosition) - XMLoadFloat3(&transform_.position_), matCombined) + XMLoadFloat3(&transform_.position_);
	XMStoreFloat3(&cameraPosition, cameraPositionTranslated);

	//��ō쐬������]�s���p���āA�J��������v���C���[�ւ̃x�N�g������]
	playerForward = XMVector3Transform(-playerForward, matRotate);

	//�J�������v���C���[�̌��ɂ��邽�߁A���������|���ăx�N�g����L�΂�
	playerForward *= playerCameraDistance;

	//�J�����̈ʒu���w�肷�邽�߁A���_����J�����̈ʒu�ւ̃x�N�g�����쐬
	XMVECTOR originToCamPos = playerForward + XMLoadFloat3(&transform_.position_);
	XMStoreFloat3(&cameraPosition, originToCamPos);


	//if (mouseMove_.x < 0) {
	//	//�������ɃJ������������()
	//}
	//else if (mouseMove_.y >= 0) {
	//	//�E�����ɃJ������������
	//}

	XMFLOAT3 cameraTarget = transform_.position_;
	cameraTarget.x = transform_.position_.x + 3;
	cameraTarget.x = transform_.position_.x + 3;

	Camera::SetPosition(cameraPosition);
	Camera::SetTarget(cameraTarget);

	///////////////////////////////////////////////////
	
	ImGui::Begin("Debug");
	ImGui::Text("x=%f", mouseMove_.x);
	ImGui::Text("y=%f", mouseMove_.y);
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
	//�����̃x�N�g����ɂ܂Ƃ߂���񂾂�����܂Ƃ߂Ă��܂�����
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

XMVECTOR Player::GetForwardVector()
{
	return playerForward;
}
