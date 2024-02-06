#pragma once
#include "Engine/Sprite.h"
#include "Engine/Transform.h"

/// <summary>
/// �g�����W�V�������Ǘ����邽�߂̃N���X
/// �V�[���ƃV�[���̍��ԂɃX�v���C�g���͂��݁A���̓����x��ς���A�ʒu��ς���Ȃǂ��ăg�����W�V������������
/// </summary>

enum TRANSITION_TYPE
{
	TID_NONE,
	TID_BLACKOUT,
	TID_MAX,
};
namespace Transition
{
	//���s����
	HRESULT Initialize();
	void Update();
	void Draw();
	void Release();

	void SetType(TRANSITION_TYPE tType);
	void SetTimer(int time);
	void Execute();
	bool GetIsActive();

	void Blackout();
};
