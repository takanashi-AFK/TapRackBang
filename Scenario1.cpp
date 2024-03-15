#include "Scenario1.h"

Scenario1::Scenario1(GameObject* parent)
	:GameObject(parent,"Scenario1"), time_(nullptr)
{
	isTargetBroken = false;
}

void Scenario1::Initialize()
{
	Instantiate<SkySphere>(this);

	{
	for (int y = 0; y < PLACE_SIZE; y++)
		for (int x = 0; x < PLACE_SIZE; x++) {
			targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x - 4, PLACE_OUTSET * y -15, 3);
		}
	
		sp[0] = Instantiate<SphereTarget>(this);
		xPos = rand() % PLACE_SIZE;
		yPos = rand() % PLACE_SIZE;

		sp[0]->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[0] = targetPlace_[xPos][yPos];

		//もし1と重なってたら
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y);
		sp[1] = Instantiate<SphereTarget>(this);
		sp[1]->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[1] = targetPlace_[xPos][yPos];


		//もし１と、２と重なってたら
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y ||
			previousPos[1].x == targetPlace_[xPos][yPos].x &&
			previousPos[1].y == targetPlace_[xPos][yPos].y);

		sp[2] = Instantiate<SphereTarget>(this);
		sp[2]->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[2] = targetPlace_[xPos][yPos];
	}
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);


	speed = 0.1;
	time_ = new Text;
	time_->Initialize();
}

void Scenario1::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->PlayerMove();
	XMFLOAT3 PPos = pPlayer->GetPosition();
	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	hGroundModelHandle_ = pStage->GetModelHandle();

	/////////////////////接地処理//////////////////////
	RayCastData groundRayData;
	groundRayData.start = PPos;
	groundRayData.start.y = PPos.y - MODEL_SIZE / 2;
	groundRayData.dir = XMFLOAT3(0, -1, 0);
	Model::RayCast(hGroundModelHandle_, &groundRayData);
	if (groundRayData.hit) {
		PPos.y -= groundRayData.dist;
	}
	//////////////////////////////////////////////////

	////////////////壁接触処理////////////////////////


	/*右方向のレイキャスト*/ {
		groundRayData.dist = 99999.f;
		groundRayData.start = PPos;
		groundRayData.start.x = PPos.x + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			PPos.x -= speed;
		}
	}

	/*左方向のレイキャスト*/ {

		groundRayData.dist = 99999.f;
		groundRayData.start = PPos;
		groundRayData.start.x = PPos.x - MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(-1, 0, 0);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			PPos.x += speed;
		}
	}

	/*奥方向のレイキャスト*/ {

		groundRayData.start = PPos;
		groundRayData.start.z = PPos.z + MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, 1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			PPos.z -= speed;
		}
	}

	/*手前方向のレイキャスト*/ {
		// Z軸負方向のレイキャスト
		groundRayData.start = PPos;
		groundRayData.start.z = PPos.z - MODEL_SIZE / 2;
		groundRayData.dir = XMFLOAT3(0, 0, -1);
		Model::RayCast(hGroundModelHandle_, &groundRayData);
		if (groundRayData.hit && groundRayData.dist < speed) {
			PPos.z += speed;
		}
	}
	pPlayer->SetPosition(PPos);

	ImGui::Begin("rueausu");
	ImGui::Text("Scenario1");

	if (ImGui::Button("SceneChange")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();

	if (isTargetBroken) {
		for (int i = 0; i < 3; i++)
			if (brokenTargetPos.x == previousPos[i].x && brokenTargetPos.y == previousPos[i].y)
				brokenTarget = i;

		//もし１と、２と重なってたら
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y ||
			previousPos[1].x == targetPlace_[xPos][yPos].x &&
			previousPos[1].y == targetPlace_[xPos][yPos].y ||
			previousPos[2].x == targetPlace_[xPos][yPos].x &&
			previousPos[2].y == targetPlace_[xPos][yPos].y );

		sp[brokenTarget] = Instantiate<SphereTarget>(this);
		sp[brokenTarget]->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[brokenTarget] = targetPlace_[xPos][yPos];

		isTargetBroken = false;
	}

	frame_++;

	if (frame_ / 60 > 10) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT, TID_BLACKOUT, 0.5f);
	}
		
}

void Scenario1::Draw()
{
	time_ -> Draw(30, 30, frame_ / 60);
}

void Scenario1::Release()
{
}

void Scenario1::onAction(XMFLOAT3 pos)
{
	brokenTargetPos = pos;
	isTargetBroken = true;

	//もしpreviousPosとbrokenTargetPosが同じなら、そのインスタンスの再生成
}
