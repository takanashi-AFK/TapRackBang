#include "SphereTarget.h"

SphereTarget::SphereTarget(GameObject* parent)
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);
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
	for (int y = 1; y <= PLACE_SIZE; y++)
		for (int x = 1; x <= PLACE_SIZE; x++){
			transform_.position_.x = PLACE_OUTSET * x;
			transform_.position_.y = PLACE_OUTSET * y;
			Model::SetTransform(hSphereModel_, transform_);
			Model::Draw(hSphereModel_);
		}
}

void SphereTarget::Release()
{
}
