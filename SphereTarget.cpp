#include "SphereTarget.h"

SphereTarget::SphereTarget(GameObject* parent)
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);

	for (int y = 0; y < PLACE_SIZE; y++)
		for (int x = 0; x < PLACE_SIZE; x++) {
			targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y, 0);
		}


	for (int i = 0; i < 3; i++) {
		do {
			xPos = rand() % PLACE_SIZE;
			yPos = rand() % PLACE_SIZE;
		} while (t[i].targetTrans.position_.x == targetPlace_[xPos][yPos].x &&
			t[i].targetTrans.position_.y == targetPlace_[xPos][yPos].y);
		
		t[i].targetTrans.position_ = targetPlace_[xPos][yPos];
	}
}

void SphereTarget::Update()
{

}

void SphereTarget::Draw()
{
	
	for(int i = 0; i < PLACE_SIZE-1;i++){

		Model::SetTransform(hSphereModel_, t[i].targetTrans);
		Model::Draw(hSphereModel_);
	}

}

void SphereTarget::Release()
{
}

