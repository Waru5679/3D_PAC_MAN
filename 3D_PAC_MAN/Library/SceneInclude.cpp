//ライブラリファイル
#include "SceneInclude.h"
#include "Task.h"

//ゲームで使うシーンファイル
#include "../Game/Main/SceneMain.h"
#include "../Game/Title/SceneTitle.h"
#include "../Game/GameOver/SceneGameOver.h"
#include "../Game/Clear/SceneClear.h"

//シーンの作成
void CSceneInclude::LoadScene()
{
	//メイン
	CSceneMain* main = new CSceneMain();
	g_Scene.Insert(main, SceneName::SceneMain);
	
	//タイトル
	CSceneTitle* pTitle = new CSceneTitle();
	g_Scene.Insert(pTitle, SceneTitle);

	//クリア
	CSceneClear* pClear = new CSceneClear();
	g_Scene.Insert(pClear, SceneClear);

	//ゲームオーバー
	CSceneGameOver* pGame = new CSceneGameOver();
	g_Scene.Insert(pGame, SceneGameOver);
}