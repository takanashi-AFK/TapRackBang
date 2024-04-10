#include "SphereTarget.h"

SphereTarget::SphereTarget(GameObject* parent):
	GameObject(parent,"SphereTarget")
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);
	/*é∏îsÇµÇΩÉRÅ[Éh*/ {
		//for (int y = 0; y < 4; y++)
		//	for (int x = 0; x < 4; x++) {
		//		targetPlace_[x][y] = XMFLOAT3(2.25f * x, 2.25f * y, 0);
		//	}

		////Ç±ÇÍÇÕïsìÆ
		//	xPos = rand() % 4;
		//	yPos = rand() % 4;

		//	t[0].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[0].targetTrans.position_, 1.2f);
		//	AddCollider(collision);

		////Ç‡Çµ1Ç∆èdÇ»Ç¡ÇƒÇΩÇÁ
		//	do {
		//	xPos = rand() % 4;
		//	yPos = rand() % 4;
		//	} while (t[0].targetTrans.position_.x == targetPlace_[xPos][yPos].x&&
		//			 t[0].targetTrans.position_.y == targetPlace_[xPos][yPos].y);

		//	t[1].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[1].targetTrans.position_, 1.2f);
		//	AddCollider(collision);


		////Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
		//	do {
		//	xPos = rand() % 4;
		//	yPos = rand() % 4;
		//	} while (t[0].targetTrans.position_.x == targetPlace_[xPos][yPos].x &&
		//		t[0].targetTrans.position_.y == targetPlace_[xPos][yPos].y ||
		//		t[1].targetTrans.position_.x == targetPlace_[xPos][yPos].x &&
		//		t[1].targetTrans.position_.y == targetPlace_[xPos][yPos].y);
		//	
		//	t[2].targetTrans.position_ = targetPlace_[xPos][yPos];

		//	SphereCollider* collision = new SphereCollider(t[2].targetTrans.position_, 1.2f);
		//	AddCollider(collision);
	}
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.f);
	AddCollider(collision);
}


void SphereTarget::Update()
{
}

void SphereTarget::Draw()
{
	Model::SetTransform(hSphereModel_, transform_);
	Model::Draw(hSphereModel_);
}

void SphereTarget::Release()
{
}

void SphereTarget::OnCollision(GameObject* pTarget)
{
	Scenario1* sc1 = (Scenario1*)FindObject("Scenario1");
	//íeÇ…ìñÇΩÇ¡ÇΩÇ∆Ç´
	if (pTarget->GetObjectName() == "Bullet"){
		KillMe();
		pTarget->KillMe();
		NotifyTargetDestroy(sc1);
		g_Point += 1;
	}
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) {
			targetPlace_[x][y] = XMFLOAT3(2.25f * x, 2.25f * y - 15, 70);
		}

	sp[0] = Instantiate<SphereTarget>(GetParent()->GetParent());
	xPos = rand() % 4;
	yPos = rand() % 4;

	sp[0]->SetPosition(targetPlace_[xPos][yPos]);
	previousPos[0] = targetPlace_[xPos][yPos];

	//Ç‡Çµ1Ç∆èdÇ»Ç¡ÇƒÇΩÇÁ
	do {
		xPos = rand() % 4;
		yPos = rand() % 4;
	} while (previousPos[0].x == targetPlace_[xPos][yPos].x && previousPos[0].y == targetPlace_[xPos][yPos].y);
	sp[1] = Instantiate<SphereTarget>(GetParent()->GetParent());
	sp[1]->SetPosition(targetPlace_[xPos][yPos]);
	previousPos[1] = targetPlace_[xPos][yPos];


	//Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
	do {
		xPos = rand() % 4;
		yPos = rand() % 4;
	} while (previousPos[0].x == targetPlace_[xPos][yPos].x &&
		previousPos[0].y == targetPlace_[xPos][yPos].y ||
		previousPos[1].x == targetPlace_[xPos][yPos].x &&
		previousPos[1].y == targetPlace_[xPos][yPos].y);

	sp[2] = Instantiate<SphereTarget>(GetParent()->GetParent());
	sp[2]->SetPosition(targetPlace_[xPos][yPos]);
	previousPos[2] = targetPlace_[xPos][yPos];
}

void SphereTarget::NotifyTargetDestroy(Scenario1* sc)
{
	AudioManager::PlayKillSound();
	pos = transform_.position_;
	sc->onAction(pos);
}

XMFLOAT3 SphereTarget::ReturnBreakPos()
{
	return transform_.position_;
}

