#include "Transition.h"

namespace Transition {

	Sprite* pSp[TID_MAX] = { nullptr };
	TRANSITION_TYPE type_;
	Transform imageTransform;

	float alpha;

	const float FPS = 60.0f;			//フレームレート
	const float FINISH_TIME = 510.0f;	//トランジションの終了まで掛かる時間(fps)
	const float ALPHA_MAX = 255.0f;		//最大alpha値
	const float ALPHA_MIN = 0.0f;		//最小alpha値
	RECT rect;

	bool isAlphaNow;
	bool isActive;
	bool isChange;
	int timer;
};


HRESULT Transition::Initialize()
{
	for (int i = 0; i < TID_MAX; i++) {
		pSp[i] = new Sprite;
	}
	HRESULT hr;


	hr = pSp[TID_BLACKOUT]->Load("Transition/BlackOut.png");
	if (hr != S_OK)return hr;

	return hr;
}

void Transition::Update()
{
	switch (type_)
	{
	case TID_NONE:
		isChange = true; isActive = true;
		break;
	case TID_BLACKOUT:
		Transition::Blackout();
		break;
	case TID_MAX:
		break;
	default:
		isChange = true; isActive = true;
		break;
	}
}

void Transition::Draw()
{
	pSp[type_]->Draw(imageTransform, rect, alpha/ALPHA_MAX);
}

void Transition::Release()
{
}

void Transition::SetType(TRANSITION_TYPE tType)
{
	type_ = tType; 
}

void Transition::SetTimer(int time)
{
	timer = time * FPS;
}

void Transition::Execute()
{
	isActive = true;
}


bool Transition::GetIsActive()
{
	return isActive;
}

void Transition::Blackout()
{
	
	rect.left   = 0;
	rect.right  = pSp[TID_BLACKOUT]->GetTextureSize().x;
	rect.top    = 0;
	rect.bottom = pSp[TID_BLACKOUT]->GetTextureSize().y;

	if (alpha >= ALPHA_MAX) {
		isChange = true;
		isAlphaNow = true;
	}

	if (isAlphaNow) {
		alpha -= timer;
		if (alpha <= ALPHA_MIN) isAlphaNow = false;
	}
	else alpha += timer;


}
