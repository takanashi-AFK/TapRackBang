#pragma once
#include "GameObject.h"

//-----------------------------------------------------------
//カメラ
//-----------------------------------------------------------
namespace Camera
{
	//初期化（プロジェクション行列作成）
	void Initialize();

	//更新（ビュー行列作成）
	void Update();

	//視点（カメラの位置）を設定
	void SetPosition(XMFLOAT3 position);

	void SetPosition(float x,float y,float z);

	//焦点（見る位置）を設定
	void SetTarget(XMFLOAT3 target);
	void SetTarget(float x, float y, float z);

	//位置を取得
	XMFLOAT3 GetPosition();

	//焦点を取得
	XMFLOAT3 GetTarget();

	//ビュー行列を取得
	XMMATRIX GetViewMatrix();

	XMVECTOR GetSightLine();

	//プロジェクション行列を取得
	XMMATRIX GetProjectionMatrix();

	//ビルボード用回転行列を取得
	XMMATRIX GetBillboardMatrix();
};