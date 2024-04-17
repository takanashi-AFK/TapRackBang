#pragma once
#include "Engine/GameObject.h"
class ActionListener
{
public:
	virtual void onAction(XMFLOAT3 pos) = 0;
	virtual void onAction() = 0;
};

