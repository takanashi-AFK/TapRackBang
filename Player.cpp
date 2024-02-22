#include "Player.h"

const float MODEL_SIZE{ 1 };
//あらかじめ30度と90度のベクトルを作っておく
//その角度まで開いたら、camposをそのベクトルにしちゃう


Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	speed = 0.1f;
	hPlayerModel_ = Model::Load("TestBird.fbx");
	pSM=(SceneManager*)FindObject("SceneManager");
	transform_.position_.y = 20;	
	sensitivity = 0.2;
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

	XMVECTOR nVMoveZ = XMVector3Normalize(vMoveZ_);

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

	//角度を判定するための上方向に伸びるベクトル
	

	XMFLOAT3 mouseMove = Input::GetMouseMove();

	XMFLOAT3 playerHead_position = transform_.position_;

	XMFLOAT3 camera_position = Camera::GetPosition();


		XMVECTOR player_To_camPos = XMLoadFloat3(&camera_position) - XMLoadFloat3(&playerHead_position);
		player_To_camPos = XMVector3Normalize(player_To_camPos);

		auto rotY = XMConvertToRadians(mouseMove.y * sensitivity);
		auto rotX = XMConvertToRadians(mouseMove.x * sensitivity);

		// 回転行列をマウスの移動量を基に作成
		XMMATRIX matRotate =
			XMMatrixRotationX(rotY) * XMMatrixRotationY(rotX);

			// 回転行列を掛けて、向きベクトルを回転
			player_To_camPos = XMVector3Transform(player_To_camPos, matRotate);

			// 長さを変更
			player_To_camPos *= playerCameraDistance;

			// 原点０，０から回転後のカメラの位置に伸びるベクトルを作成し、位置に代入
			XMVECTOR origin_To_camPos = player_To_camPos + XMLoadFloat3(&playerHead_position);
			XMStoreFloat3(&camera_position, origin_To_camPos);


		float dotProduct = XMVectorGetX(XMVector3Dot(XMVector3Normalize(player_To_camPos), XMVector3Normalize(verticalP)));

		// 角度を度に変換
		float angle = acos(dotProduct);
		if (angle >= XMConvertToRadians(90))
		{
			camera_position.y = 0;//fix to rotation
		}

		sensitivity = .2f;
		if (angle < XMConvertToRadians(30))
		{
			XMStoreFloat3(&camera_position, upLimit);
		}
	Camera::SetPosition(camera_position);
	Camera::SetTarget(playerHead_position);
	
	// プレイヤーが進む方向ベクトルを計算
	XMVECTOR player_forward = player_To_camPos;

	// プレイヤーの向きを設定
	transform_.rotate_.y = atan2(XMVectorGetX(-player_forward), XMVectorGetZ(-player_forward)) * (180.0f / XM_PI);
	
	///////////////////////////////////////////////////
	
	ImGui::Begin("Debug");
	ImGui::Text("x=%f", transform_.position_.x);
	ImGui::Text("y=%f", transform_.position_.x);
	ImGui::Text("z=%f", transform_.position_.z);
	ImGui::Text("angle = %f", angle);
	ImGui::Text("rotY = %f", rotY);
	
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
	return vMoveZ_;
}
