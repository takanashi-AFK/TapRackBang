#include "DepthScenario.h"


DepthScenario::DepthScenario(GameObject* parent):
	GameObject(parent, "DepthScenario")
{
}

void DepthScenario::Initialize()
{
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	pPlayer = (Player*)FindObject("Player");
	pGun = (Gun*)FindObject("Gun");

	isWaveNow_ = true;

	enemyPos[0] = {mapSize, 0, mapSize};
	enemyPos[1] = {mapSize, 0, -mapSize};
	enemyPos[2] = {-mapSize, 0, mapSize};
	enemyPos[3] = {-mapSize, 0, -mapSize};
}

void DepthScenario::Update()
{
	pPlayer->PlayerMove();
	
	if (isWaveNow_ == true) {
		//enemyPos���烉���_���œG���|�b�v
		// ���ԓ��ɂP�O�C��ememy���S�̃|�C���g����|�b�v
		// ����
		// 10�C�S�����񂾂�I���
		// KAKINAOSE


		int r = rand() % 10;
		if (isEnemyAmount_ == true)
		{
			if (frame >= r) {
				enemylist.push_back(Instantiate<Enemy>(this));
				int popPos = rand() % 4;
				enemylist.back()->SetPosition(enemyPos[popPos]);
				if (enemylist.size() > 5)
					isEnemyAmount_ = false;
				else
					isEnemyAmount_ = true;
			}

		}


			



		if (true/*�����G���S�����񂾂�*/)
			isWaveNow_ = false;
	}

	if (isMiniGameNow_ == true) {

		//�A��
	}

	frame++;
}

void DepthScenario::Draw()
{

}

void DepthScenario::Release()
{
}

