#include "Scenario1.h"

Scenario1::Scenario1(GameObject* parent)
	:GameObject(parent,"Scenario1")
{
	isTargetBroken = false;
}

void Scenario1::Initialize()
{
	Instantiate<SkySphere>(this);

	{
	for (int y = 0; y < PLACE_SIZE; y++)
		for (int x = 0; x < PLACE_SIZE; x++) {
			targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y, 0);
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
}

void Scenario1::Update()
{
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

	ImGui::Text("0x=%f", previousPos[0].x);
	ImGui::Text("0y=%f", previousPos[0].y);
	ImGui::Text("1x=%f", previousPos[1].x);
	ImGui::Text("1y=%f", previousPos[1].y);
	ImGui::Text("2x=%f", previousPos[2].x);
	ImGui::Text("2y=%f", previousPos[2].y);

	
}

void Scenario1::Draw()
{
	
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
