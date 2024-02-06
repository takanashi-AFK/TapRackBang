#include "sceneManager.h"

#include "../PlayScene.h"
#include "../SplashScene.h"
#include "Model.h"
#include "Image.h"
#include "Audio.h"


//コンストラクタ
SceneManager::SceneManager(GameObject * parent)
	: GameObject(parent, "SceneManager")
{
}

//初期化
void SceneManager::Initialize()
{
	//最初のシーンを準備
	currentSceneID_ = SCENE_ID_SPLASH;
	nextSceneID_ = currentSceneID_;
	Instantiate<SplashScene>(this);
}

//更新
void SceneManager::Update()
{
	//次のシーンが現在のシーンと違う　＝　シーンを切り替えなければならない
	if (currentSceneID_ != nextSceneID_)
	{
		//そのシーンのオブジェクトを全削除
		KillAllChildren();

		//ロードしたデータを全削除
		Audio::Release();
		Model::AllRelease();
		Image::AllRelease();

		//次のシーンを作成
		switch (nextSceneID_)
		{
		case SCENE_ID_SPLASH: Instantiate<SplashScene>(this); break;
		case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;

		}
		Audio::Initialize();
		currentSceneID_ = nextSceneID_;
	}
}

//描画
void SceneManager::Draw()
{
}

//開放
void SceneManager::Release()
{
}

//シーン切り替え（実際に切り替わるのはこの次のフレーム）
void SceneManager::ChangeScene(SCENE_ID next)
{
	nextSceneID_ = next;
}

void SceneManager::ChangeScene(SCENE_ID next, TRANSITION_TYPE transition)
{
	//トランジションが動作中はシーン遷移を行わない
	if (!Transition::GetIsActive()) {
		//トランジションを使わない場合、シーンIDをセット
		Transition::SetType(transition);

		//トランジションを開始し、シーンIDをセット
		Transition::Execute(); tmpID_ = next;
	}
}
