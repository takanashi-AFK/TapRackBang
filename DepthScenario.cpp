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

	//Enemy* e1 = Instantiate<Enemy>(this);
	//e1->SetPosition(enemyPos[0]);
	//Enemy* e2 = Instantiate<Enemy>(this);
	//e2->SetPosition(enemyPos[1]);
	//Enemy* e3 = Instantiate<Enemy>(this);
	//e3->SetPosition(enemyPos[2]);
	//Enemy* e4 = Instantiate<Enemy>(this);
	//e4->SetPosition(enemyPos[3]);

	isWaveNow_ = true;
}

void DepthScenario::Update()
{


	
	pPlayer->PlayerMove();

	if (isWaveNow_) {
		for (int i = 0; i < 4; i++) {
			int r = rand() % 4;
			pEnemy[i] = Instantiate<Enemy>(this);
			pEnemy[i]->SetPosition(enemyPos[r]);
		}

		if (isEnemyDead_) {
			for (int i = 0; i < 4; i++) {
				if (pEnemy[i] == nullptr) {
					int r = rand() % 4;
					pEnemy[i] = Instantiate<Enemy>(this);
					pEnemy[i]->SetPosition(enemyPos[r]);
				}
			}
		}

	}
	
	//scenario1�Ɠ��������ōl���Ă����`�H

	//if (isWaveNow_) {
	//	for (int i = 0; i < 4; i++) {
	//		int r = rand() % 4;
	//		enemylist[i] = Instantiate<Enemy>(this);
	//		enemylist[i]->SetPosition(enemyPos[r]);
	//		enemyValue_++;

	//	}
	//}
	//ImGui::Text("%d", enemylist.size());
	//if (isWaveNow_ == true) {
	//	//enemyPos���烉���_���œG���|�b�v
	//	// ���ԓ��ɂP�O�C��ememy���S�̃|�C���g����|�b�v
	//	// ����
	//	// 10�C�S�����񂾂�I���
	//	// KAKINAOSE

	//	int r = rand() % 10;
	//	if (isEnemyAmount_ == true)
	//	{
	//		if (frame >= r) {
	//			enemylist.push_back(Instantiate<Enemy>(this));
	//			int popPos = rand() % 4;
	//			enemylist.back()->SetPosition(enemyPos[popPos]);
	//			if (enemylist.size() > 5)
	//				isEnemyAmount_ = false;
	//			else
	//				isEnemyAmount_ = true;
	//		}
	//	}
	//		
	//	if (true/*�����G���S�����񂾂�*/)
	//		isWaveNow_ = false;
	//}
	//if (isMiniGameNow_ == true) {

	//	//�A��
	//}


	


	frame++;
}

void DepthScenario::Draw()
{

}

void DepthScenario::Release()
{
}

void DepthScenario::onAction()
{
	isEnemyDead_ = true;
}

