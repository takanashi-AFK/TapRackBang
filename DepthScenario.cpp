#include "DepthScenario.h"
#include "Enemy.h"


DepthScenario::DepthScenario(GameObject* parent):
	GameObject(parent, "DepthScenario")
{
}

void DepthScenario::Initialize()
{
	Instantiate<SimpleStage>(this);
	Instantiate<SkySphere>(this);
	Instantiate<Player>(this);
	pPlayer = (Player*)FindObject("Player");
	pGun = (Gun*)FindObject("Gun");

	isWaveNow_ = true;
	enemyPos[0] = {mapSize, 0, mapSize};
	enemyPos[1] = {mapSize, 0, -mapSize};
	enemyPos[2] = {-mapSize, 0, mapSize};
	enemyPos[3] = {-mapSize, 0, -mapSize};
	
	GenerateEnemy();
}

void DepthScenario::Update()
{
	pPlayer->PlayerMove();

	if (enemyCount_ == 4){
		ReGenerateEnemy();
		enemyCount_ = 0;
	}
	
	//if (isWaveNow_ == true) {
	//	//enemyPos���烉���_���œG���|�b�v
	//	// ���ԓ��ɂP�O�C��ememy���S�̃|�C���g����|�b�v
	//	// ����
	//	// 10�C�S�����񂾂�I���
	//	// KAKINAOSE



	

	if (isMiniGameNow_ == true) {

		//�A��
	}

	frame++;
	ImGui::Text("%d", enemyCount_);
}

void DepthScenario::Draw()
{

}

void DepthScenario::Release()
{
}

void DepthScenario::GenerateEnemy()
{
	for (int i = 0; i < 4; i++) {
		enemyList_[i]= Instantiate<Enemy>(this);
		int r = rand() % 4;
		enemyList_[i]->SetPosition(enemyPos[r]);
	}
}

void DepthScenario::ReGenerateEnemy()
{
	GenerateEnemy();
	generateCount_++;
}

void DepthScenario::onAction()
{
	enemyCount_++;
	if (enemyCount_ == 4) {
		isEnemyDead_ = true;
	}

	
}

