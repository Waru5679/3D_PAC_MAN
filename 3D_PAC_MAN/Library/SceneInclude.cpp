//���C�u�����t�@�C��
#include "SceneInclude.h"
#include "Task.h"

//�Q�[���Ŏg���V�[���t�@�C��
#include "../Game/Main/SceneMain.h"
#include "../Game/Title/SceneTitle.h"
#include "../Game/GameOver/SceneGameOver.h"
#include "../Game/Clear/SceneClear.h"

//�V�[���̍쐬
void CSceneInclude::LoadScene()
{
	//���C��
	CSceneMain* main = new CSceneMain();
	g_Scene.Insert(main, SceneName::SceneMain);
	
	//�^�C�g��
	CSceneTitle* pTitle = new CSceneTitle();
	g_Scene.Insert(pTitle, SceneTitle);

	//�N���A
	CSceneClear* pClear = new CSceneClear();
	g_Scene.Insert(pClear, SceneClear);

	//�Q�[���I�[�o�[
	CSceneGameOver* pGame = new CSceneGameOver();
	g_Scene.Insert(pGame, SceneGameOver);
}