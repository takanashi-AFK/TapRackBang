#include "SphereTarget.h"
#include "TargetManager.h"
SphereTarget::SphereTarget(GameObject* parent):
	GameObject(parent,"SphereTarget")
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);
	/*失敗したコード*/ {
		//for (int y = 0; y < 4; y++)
		//	for (int x = 0; x < 4; x++) {
		//		targetPlace_[x][y] = XMFLOAT3(2.25f * x, 2.25f * y, 0);
		//	}

		////これは不動
		//	xPos = rand() % 4;
		//	yPos = rand() % 4;

		//	t[0].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[0].targetTrans.position_, 1.2f);
		//	AddCollider(collision);

		////もし1と重なってたら
		//	do {
		//	xPos = rand() % 4;
		//	yPos = rand() % 4;
		//	} while (t[0].targetTrans.position_.x == targetPlace_[xPos][yPos].x&&
		//			 t[0].targetTrans.position_.y == targetPlace_[xPos][yPos].y);

		//	t[1].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[1].targetTrans.position_, 1.2f);
		//	AddCollider(collision);


		////もし１と、２と重なってたら
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
	TargetManager* t = (TargetManager*)FindObject("TargetManager");
	//弾に当たったとき
	if (pTarget->GetObjectName() == "Bullet"){
		KillMe();
		pTarget->KillMe();
		NotifyTargetDestroy(t);
		g_Point += 1;
	}
}

void SphereTarget::NotifyTargetDestroy(TargetManager* t)
{
	AudioManager::PlayKillSound();
	pos = transform_.position_;
	t->onAction(pos);
}

XMFLOAT3 SphereTarget::ReturnBreakPos()
{
	return transform_.position_;
}

