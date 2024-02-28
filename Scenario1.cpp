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
	
		SphereTarget* sp1 = Instantiate<SphereTarget>(this);
		xPos = rand() % PLACE_SIZE;
		yPos = rand() % PLACE_SIZE;

		sp1->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[0] = targetPlace_[xPos][yPos];

		//Ç‡Çµ1Ç∆èdÇ»Ç¡ÇƒÇΩÇÁ
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y);
		sp2 = Instantiate<SphereTarget>(this);
		sp2->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[1] = targetPlace_[xPos][yPos];

		//Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y ||
			previousPos[1].x == targetPlace_[xPos][yPos].x &&
			previousPos[1].y == targetPlace_[xPos][yPos].y);

		sp3 = Instantiate<SphereTarget>(this);
		sp3->SetPosition(targetPlace_[xPos][yPos]);
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

	if (isTargetBroken == true) {
		//Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
			previousPos[0].y == targetPlace_[xPos][yPos].y ||
			previousPos[1].x == targetPlace_[xPos][yPos].x &&
			previousPos[1].y == targetPlace_[xPos][yPos].y||
			previousPos[2].x == targetPlace_[xPos][yPos].x &&
			previousPos[2].y == targetPlace_[xPos][yPos].y );

		sp3 = Instantiate<SphereTarget>(this);
		sp3->SetPosition(targetPlace_[xPos][yPos]);
		previousPos[2] = targetPlace_[xPos][yPos];

		isTargetBroken = false;
	}
	
}

void Scenario1::Draw()
{
	
}

void Scenario1::Release()
{
}

void Scenario1::onAction()
{
	isTargetBroken = true;
}
