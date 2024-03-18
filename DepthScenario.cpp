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
		//enemyPos‚©‚çƒ‰ƒ“ƒ_ƒ€‚Å“G‚ðƒ|ƒbƒv
		// ŽžŠÔ“à‚É‚P‚O•C‚Ìememy‚ª‚S‚Â‚Ìƒ|ƒCƒ“ƒg‚©‚çƒ|ƒbƒv
		// Žž
		// 10•C‘SˆõŽ€‚ñ‚¾‚çI‚í‚è
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


			



		if (true/*‚à‚µ“G‚ª‘S•”Ž€‚ñ‚¾‚ç*/)
			isWaveNow_ = false;
	}

	if (isMiniGameNow_ == true) {

		//ƒAƒŒ
	}

	frame++;
}

void DepthScenario::Draw()
{

}

void DepthScenario::Release()
{
}

