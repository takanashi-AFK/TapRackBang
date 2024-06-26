#include "Enemy.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy")
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("SimpleCube.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.f);
	AddCollider(collision);
}

void Enemy::Update()
{
	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	XMFLOAT3 stagePos = pStage->GetPosition();
	originToCenter_ = XMLoadFloat3(&stagePos);
	originToPos_ = XMLoadFloat3(&transform_.position_);

	pEnemyVec_ = originToPos_ - originToCenter_;
	//これに対して、このベクトルをだんだん縮めながらsinで角度を変え、回転させると渦巻になるんじゃね？
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::NotifyEnemyDead(DepthScenario* d)
{
	AudioManager::PlayKillSound();
	d->onAction();
}

void Enemy::OnCollision(GameObject* pTarget)
{
	DepthScenario* depth = (DepthScenario*)FindObject("DepthScenario");
	//弾に当たったとき
	if (pTarget->GetObjectName() == "Bullet") {
		KillMe();
		pTarget->KillMe();
		NotifyEnemyDead(depth);
		g_Point += 1;
	}
}
