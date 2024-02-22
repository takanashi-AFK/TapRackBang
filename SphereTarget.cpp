#include "SphereTarget.h"

SphereTarget::SphereTarget(GameObject* parent)
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);

	for (int i = 0; i < PLACE_SIZE; i++) {
		for (int j = 0; j < PLACE_SIZE; j++) {
			targetPlace_[i][j] = XMFLOAT3(i * PLACE_OUTSET, j * PLACE_OUTSET, 0);
		}
	}
}

void SphereTarget::Update()
{
	//if (/*‚à‚µ‰ó‚³‚ê‚½‚ç*/true) {
	//	if (/*“ñŽŸŒ³”z—ñ‚Ì“¯‚¶ˆÊ’u‚¶‚á‚È‚©‚Á‚½‚ç*/true) {
	//		SetPosition(targetPlace_[rand() % PLACE_SIZE][rand() % PLACE_SIZE]);
	//	}
	//}
}

void SphereTarget::Draw()
{
	Model::SetTransform(hSphereModel_, transform_);
	Model::Draw(hSphereModel_);
}

void SphereTarget::Release()
{
}
