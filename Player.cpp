#include "Player.h"

const float MODEL_SIZE{ 1 };
//あらかじめ30度と90度のベクトルを作っておく
//その角度まで開いたら、camposをそのベクトルにしちゃう


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

	
	/*右方向のレイキャスト*/   {
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x = transform_.position_.x + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist <= speed) {
			transform_.position_.x -= speed;
		}
	}

	/*左方向のレイキャスト*/   {
		
		groundRayData.dist = 99999.f;
		groundRayData.start = transform_.position_;
		groundRayData.start.x = transform_.position_.x - MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(-1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.x += speed;
		}
	}

	/*奥方向のレイキャスト*/   {
		
		groundRayData.start = transform_.position_;
		groundRayData.start.z = transform_.position_.z + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, 1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			transform_.position_.z -= speed;
		}
	}

	/*手前方向のレイキャスト*/ {
		// Z軸負方向のレイキャスト
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

	//カメラからプレイヤーへ向けたベクトルを作成、単位ベクトル化
	playerForward = XMLoadFloat3(&transform_.position_) - XMLoadFloat3(&cameraPosition);
	playerForward = XMVector3Normalize(playerForward);

	//各方向の移動量(何度動くか)
	auto rotX = XMConvertToRadians(mouseMove_.x * sensitivity);
	auto rotY = XMConvertToRadians(mouseMove_.y * sensitivity);

	//マウスの移動量から回転行列を作成
	XMMATRIX matRotate = XMMatrixRotationX(rotY) * XMMatrixRotationY(rotX);
	

	XMMATRIX matTranslateToPlayer = XMMatrixTranslation(transform_.position_.x, transform_.position_.y, transform_.position_.z);
	XMMATRIX matTranslateBack = XMMatrixTranslation(-transform_.position_.x, -transform_.position_.y, -transform_.position_.z);
	XMMATRIX matCombined = matTranslateToPlayer * matRotate * matTranslateBack;

	// カメラの位置を中心にして回転行列を適用し、その結果をプレイヤーの位置に平行移動させる
	XMVECTOR cameraPositionTranslated = XMVector3Transform(XMLoadFloat3(&cameraPosition) - XMLoadFloat3(&transform_.position_), matCombined) + XMLoadFloat3(&transform_.position_);
	XMStoreFloat3(&cameraPosition, cameraPositionTranslated);

	//上で作成した回転行列を用いて、カメラからプレイヤーへのベクトルを回転
	playerForward = XMVector3Transform(-playerForward, matRotate);

	//カメラをプレイヤーの後ろにするため、距離分を掛けてベクトルを伸ばす
	playerForward *= playerCameraDistance;

	//カメラの位置を指定するため、原点からカメラの位置へのベクトルを作成
	XMVECTOR originToCamPos = playerForward + XMLoadFloat3(&transform_.position_);
	XMStoreFloat3(&cameraPosition, originToCamPos);


	//if (mouseMove_.x < 0) {
	//	//左方向にカメラを向ける()
	//}
	//else if (mouseMove_.y >= 0) {
	//	//右方向にカメラを向ける
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
	//ここのベクトル一つにまとめられるんだったらまとめてしまいたい
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
