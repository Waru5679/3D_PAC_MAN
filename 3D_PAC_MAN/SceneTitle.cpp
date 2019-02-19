#include "SceneTitle.h"
#include "Task.h"
#include "Camera.h"
#include "ObjLoader.h"
#include "Audio.h"
#include "Input.h"
#include "TitleCamera.h"
#include "Shader.h"
#include "TitleBackGround.h"
#include "Polygon.h"
#include "Font.h"

//初期化
void CSceneTitle::Init()
{
	//音楽初期化
	g_Audio.Init();

	//素材読み込み
	LoadTexture();
	LoadAudio();
	LoadMesh();

	//カメラ
	CTitleCamera* camera = new CTitleCamera();
	g_Task.InsertCamera(camera,0);

	//シェーダにカメラセット
	g_Shader.SetCamera(camera);

	//背景オブジェクト
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);
	
	CTitleBackGround* back = new CTitleBackGround(Pos, Angle, Scale);
	g_Task.Insert2DObj(back, 0);

}

//更新
void CSceneTitle::Update()
{
	g_Task.Update();

	//エンターキーでシーンメインへ
	if (g_input.GetTriggerKeyPush(VK_RETURN) == true)
	{
		g_Scene.SetScene(SceneMain);
	}
}

//描画
void CSceneTitle::Draw()
{
	g_Task.Draw();
}

//解放
void CSceneTitle::Release()
{
	g_Task.Release();
}

//音楽
void CSceneTitle::LoadAudio()
{
	g_Audio.Load(Audio_Stage, "Stage.wav", true);
	g_Audio.Load(Audio_Food_Get, "FoodGet.wav", false);
}

//テクスチャ
void CSceneTitle::LoadTexture()
{
	g_Draw.LoadTexture(0, "Title.png");
	g_Draw.LoadTexture(1, "EnemyRed.png");
}

//メッシュ
void CSceneTitle::LoadMesh()
{
}