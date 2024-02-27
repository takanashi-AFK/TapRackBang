#include "SphereTarget.h"

SphereTarget::SphereTarget(GameObject* parent)
{
}

void SphereTarget::Initialize()
{
	hSphereModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	assert(hSphereModel_ > 0);
	/*���s�����R�[�h*/ {
		//for (int y = 0; y < PLACE_SIZE; y++)
		//	for (int x = 0; x < PLACE_SIZE; x++) {
		//		targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y, 0);
		//	}

		////����͕s��
		//	xPos = rand() % PLACE_SIZE;
		//	yPos = rand() % PLACE_SIZE;

		//	t[0].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[0].targetTrans.position_, 1.2f);
		//	AddCollider(collision);

		////����1�Əd�Ȃ��Ă���
		//	do {
		//	xPos = rand() % PLACE_SIZE;
		//	yPos = rand() % PLACE_SIZE;
		//	} while (t[0].targetTrans.position_.x == targetPlace_[xPos][yPos].x&&
		//			 t[0].targetTrans.position_.y == targetPlace_[xPos][yPos].y);

		//	t[1].targetTrans.position_ = targetPlace_[xPos][yPos];
		//	SphereCollider* collision = new SphereCollider(t[1].targetTrans.position_, 1.2f);
		//	AddCollider(collision);


		////�����P�ƁA�Q�Əd�Ȃ��Ă���
		//	do {
		//	xPos = rand() % PLACE_SIZE;
		//	yPos = rand() % PLACE_SIZE;
		//	} while (t[0].targetTrans.position_.x == targetPlace_[xPos][yPos].x &&
		//		t[0].targetTrans.position_.y == targetPlace_[xPos][yPos].y ||
		//		t[1].targetTrans.position_.x == targetPlace_[xPos][yPos].x &&
		//		t[1].targetTrans.position_.y == targetPlace_[xPos][yPos].y);
		//	
		//	t[2].targetTrans.position_ = targetPlace_[xPos][yPos];

		//	SphereCollider* collision = new SphereCollider(t[2].targetTrans.position_, 1.2f);
		//	AddCollider(collision);
	}
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
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
	//�e�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "Bullet"){
		KillMe();
		pTarget->KillMe();
	}
}