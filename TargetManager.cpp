#include "TargetManager.h"

TargetManager::TargetManager()
{
}

void TargetManager::Initialize()
{
}

void TargetManager::Update()
{
}

void TargetManager::Draw()
{
}

void TargetManager::Release()
{
}

void TargetManager::GenerateSphereTarget()
{
	//for (int y = 0; y < PLACE_SIZE; y++)
	//	for (int x = 0; x < PLACE_SIZE; x++) {
	//		targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y - PLACE_HEIGHT_OUTSET, PLACE_DEPTH);
	//	}

	//sp[0] = Instantiate<SphereTarget>(this);
	//xPos = rand() % PLACE_SIZE;
	//yPos = rand() % PLACE_SIZE;

	//sp[0]->SetPosition(targetPlace_[xPos][yPos]);
	//previousPos[0] = targetPlace_[xPos][yPos];

	////もし1と重なってたら
	//do {
	//	xPos = rand() % PLACE_SIZE;
	//	yPos = rand() % PLACE_SIZE;
	//} while (previousPos[0].x == targetPlace_[xPos][yPos].x && previousPos[0].y == targetPlace_[xPos][yPos].y);
	//sp[1] = Instantiate<SphereTarget>(this);
	//sp[1]->SetPosition(targetPlace_[xPos][yPos]);
	//previousPos[1] = targetPlace_[xPos][yPos];


	////もし１と、２と重なってたら
	//do {
	//	xPos = rand() % PLACE_SIZE;
	//	yPos = rand() % PLACE_SIZE;
	//} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
	//	previousPos[0].y == targetPlace_[xPos][yPos].y ||
	//	previousPos[1].x == targetPlace_[xPos][yPos].x &&
	//	previousPos[1].y == targetPlace_[xPos][yPos].y);

	//sp[2] = Instantiate<SphereTarget>(this);
	//sp[2]->SetPosition(targetPlace_[xPos][yPos]);
	//previousPos[2] = targetPlace_[xPos][yPos];
}

void TargetManager::ReGenerateSphereTarget()
{
	//if (isTargetBroken) {
	//	for (int i = 0; i < 3; i++)
	//		if (brokenTargetPos.x == previousPos[i].x && brokenTargetPos.y == previousPos[i].y)
	//			brokenTarget = i;

	//	//もし１と、２と重なってたら
	//	do {
	//		xPos = rand() % PLACE_SIZE;
	//		yPos = rand() % PLACE_SIZE;
	//	} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
	//		previousPos[0].y == targetPlace_[xPos][yPos].y ||
	//		previousPos[1].x == targetPlace_[xPos][yPos].x &&
	//		previousPos[1].y == targetPlace_[xPos][yPos].y ||
	//		previousPos[2].x == targetPlace_[xPos][yPos].x &&
	//		previousPos[2].y == targetPlace_[xPos][yPos].y);

	//	sp[brokenTarget] = Instantiate<SphereTarget>(this);
	//	sp[brokenTarget]->SetPosition(targetPlace_[xPos][yPos]);
	//	previousPos[brokenTarget] = targetPlace_[xPos][yPos];

	//	isTargetBroken = false;
	//}

}
