#include "Player.h"


//���炩����30�x��90�x�̃x�N�g��������Ă���
//���̊p�x�܂ŊJ������Acampos�����̃x�N�g���ɂ����Ⴄ

Player::Player(GameObject* parent)
			:GameObject(parent, "Player"), hPlayerModel_(-1)
{
}

void Player::Initialize()
{
	speed = 0.5f;
	hPlayerModel_ = Model::Load("TestBird.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");
	transform_.position_.x = -2;
	transform_.position_.y = 0;
	transform_.position_.z = 30;
	sensitivity = 0.05;
	Instantiate<Gun>(this);

	hCrosshair_ = Image::Load("crossHair.png");
	assert(hCrosshair_ >= 0);
}

void Player::Update()
{

	XMFLOAT3 center = transform_.position_;
	center.y = center.y + 4;

	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	int hGroundModelHandle_ = pStage->GetModelHandle();

	/////////////////////�ڒn����//////////////////////
	RayCastData groundRayData;
	groundRayData.start = transform_.position_;
	groundRayData.start.y = transform_.position_.y - MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(0, -1, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit) {
		transform_.position_.y -= groundRayData.dist;
	}
	//////////////////////////////////////////////////

	////////////////�ǐڐG����////////////////////////
	/*�E�����̃��C�L���X�g*/ {
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x =  MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.x -= speed;
		}
	}

	/*�������̃��C�L���X�g*/ {

		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x = MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(-1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.x += speed;
		}
	}

	/*�������̃��C�L���X�g*/ {
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.z = MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, 1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.z -= speed;
		}
	}

	/*��O�����̃��C�L���X�g*/ {
		// Z���������̃��C�L���X�g
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.z =  MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, -1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.z += speed;
		}
	}
	
	/*���s�����*/{
		/*
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
		Camera::SetPosition(cameraPosition);
		Camera::SetTarget(cameraTarget);
		*/
		
			}
	
	static XMFLOAT2 rotateAngle{};
	//�}�E�X�̈ړ��ʂ��p�x�Ƃ��Ē~�ς���
	rotateAngle.x += Input::GetMouseMove().x * sensitivity;
	rotateAngle.y += Input::GetMouseMove().y * sensitivity;
	//const float upperlimit = -1.f;
	//if (rotateAngle.y < upperlimit)rotateAngle.y -= Input::GetMouseMove().y * sensitivity;


	XMFLOAT3 camTarget{};
	XMFLOAT3 camPosition{};

	
		const float upperlimit = -30;
		if (rotateAngle.y < upperlimit)rotateAngle.y -= Input::GetMouseMove().y * sensitivity;

		const float lowerlimit = 50.f;
		if (rotateAngle.y > lowerlimit)rotateAngle.y -= Input::GetMouseMove().y * sensitivity;
	

	/*Y����]*/ {
		const float distance{ 10.f };
		//���ۂɂ͉��̃x�N�g���ŁAplayerToCamTarget�ł͂Ȃ��A�����ϐ�����T����
		XMVECTOR playerToCamTarget{ 0.f,0.f,1.f,0.f };
		//Y���ŉ���]�s����쐬�AplayerToCamTarget����]������
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(rotateAngle.x));
		playerToCamTarget = XMVector3Transform(playerToCamTarget, rotY);
		playerToCamTarget *= distance;

		//���_����playerPos�Ɍ������x�N�g��
		XMVECTOR originToPlayer = XMLoadFloat3(&center);
		//���_����CamTarget�Ɍ������x�N�g��
		XMVECTOR originToCamTarget = playerToCamTarget + originToPlayer;

		//�v���C���[����^�[�Q�b�g�Ɍ����������x�N�g���̋t�x�N�g�����Ƃ�A
		//�v���C���[����|�W�V�����ւ̃x�N�g���𐶐��A��]
		XMVECTOR playerToCamPosition = -playerToCamTarget;
		playerToCamPosition = XMVector3Transform(playerToCamPosition, XMMatrixRotationY(XMConvertToRadians(-30)));

		XMVECTOR originToCamPosition = originToPlayer + playerToCamPosition;

		//�J�����̃^�[�Q�b�g���쐬
		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);

	}

	/*X����]*/ {
		
		// �V�������S�_���쐬
		XMFLOAT3 newCenter{};
		XMStoreFloat3(&newCenter, (XMLoadFloat3(&camPosition) + XMLoadFloat3(&camTarget)) * 0.5f);

		debT.position_ = newCenter;
		
		// ��]�̎����쐬
		XMVECTOR rotateAxis = XMVector3Normalize(XMLoadFloat3(&newCenter) - XMLoadFloat3(&center));

		// ��]�s����쐬
		XMMATRIX rotAxisMat = XMMatrixRotationAxis(rotateAxis, XMConvertToRadians(rotateAngle.y));

		// ��]������x�N�g����p��
		XMVECTOR newCenterToCamTarget = XMLoadFloat3(&camTarget) - XMLoadFloat3(&newCenter);

		// ��]������
		newCenterToCamTarget = XMVector3Transform(newCenterToCamTarget, rotAxisMat);

		// �t�x�N�g�����쐬
		XMVECTOR newCenterToCamPosition = -newCenterToCamTarget;

		// ���_����̃x�N�g�����쐬
		XMVECTOR originToCamTarget = XMLoadFloat3(&newCenter) + newCenterToCamTarget;
		XMVECTOR originToCamPosition = XMLoadFloat3(&newCenter) + newCenterToCamPosition;


		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);

	}


	Camera::SetTarget(camTarget);
	Camera::SetPosition(camPosition);


}

void Player::Draw()
{
	Transform tCrosshair;

	Image::SetTransform(hCrosshair_, tCrosshair);
	Image::Draw(hCrosshair_);
	Model::SetTransform(hPlayerModel_, transform_);
	Model::Draw(hPlayerModel_);

}

void Player::Release()
{
}

void Player::PlayerMove()
{
	////�����̃x�N�g����ɂ܂Ƃ߂���񂾂�����܂Ƃ߂Ă��܂�����
	//vMoveX_ = { speed,0.0f,0.0f,0.0f };
	//vMoveZ_ = { 0.0f,0.0f,speed,0.0f };
	//

	//vPlayerPos_ = XMLoadFloat3(&transform_.position_);
	//XMMATRIX rotateMatY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

	//vMoveX_ = XMVector3TransformCoord(vMoveX_, rotateMatY);
	//vMoveZ_ = XMVector3TransformCoord(vMoveZ_, rotateMatY);

	//if (Input::IsKey(DIK_W)) {
	//	XMVector3Normalize(vMoveZ_);
	//	vPlayerPos_ += vMoveZ_;

	//}

	//if (Input::IsKey(DIK_A)) {
	//	XMVector3Normalize(vMoveX_);
	//	vPlayerPos_ -= vMoveX_;
	//}

	//if (Input::IsKey(DIK_S)) {
	//	XMVector3Normalize(vMoveZ_);
	//	vPlayerPos_ -= vMoveZ_;
	//}

	//if (Input::IsKey(DIK_D)) {
	//	XMVector3Normalize(vMoveX_);
	//	vPlayerPos_ += vMoveX_;
	//}
	//XMVector3Normalize(vPlayerPos_);
	//XMStoreFloat3(&transform_.position_, vPlayerPos_);
	XMVECTOR dir{};
	XMVECTOR sightLine = Camera::GetSightLine();
	sightLine = XMVectorSetY(sightLine, 0);
	sightLine = XMVector3Normalize(sightLine);
	float rotationAngle = 0.0f;


	if (Input::IsKey(DIK_W)) {
		dir += sightLine;
	}

	if (Input::IsKey(DIK_A)) {
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(-90)));
	}

	if (Input::IsKey(DIK_S)) {
		dir += -sightLine;
	}

	if (Input::IsKey(DIK_D)) {
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(90)));
	}


	transform_.rotate_.y = rotationAngle;

	XMVECTOR move = dir * speed;

	XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + move);
}

XMVECTOR Player::GetForwardVector()
{
	return playerForward;
}
