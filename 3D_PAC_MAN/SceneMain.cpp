#include "SceneMain.h"
#include "Task.h"
#include "MainCamera.h"
#include "ObjLoader.h"
#include "Map.h"
#include "Route.h"
#include "Audio.h"
#include "Polygon.h"
#include "Shader.h"

//初期化
void CSceneMain::Init()
{
	//音楽初期化
	g_Audio.Init();

	//素材読み込み
	LoadTexture();
	LoadAudio();
	LoadMesh();
		
	//マップ
	CMap* map = new CMap();
	g_Task.Insert3DObj(map, OBJ_MAP);
	map->Create();

	//カメラ
	CMainCamera* camera = new CMainCamera();
	g_Task.InsertCamera(camera, 0);
	
	//シェーダーにカメラセット
	g_Shader.SetCamera(camera);
	
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 1.0f);
	
	//ダイクストラ法初期化
	g_Route.Init(MAP_Z,MAP_X);
	
	//音量設定
	g_Audio.MasterVolume(0.8f);

	//音楽スタート
	g_Audio.StartMusic(Audio_Stage);
}

//更新
void CSceneMain::Update()
{
	g_Task.Update();
}

//描画
void CSceneMain::Draw()
{
	g_Task.Draw();
}

void CSceneMain::Release()
{
	g_Task.Release();
	g_Audio.Delete();
}

//音楽
void CSceneMain::LoadAudio()
{
	g_Audio.Load(Audio_Stage, "Stage.wav",true);
	g_Audio.Load(Audio_Food_Get, "FoodGet.wav", false);
	g_Audio.Load(Audio_Damage, "Damage.wav",false);
}

//テクスチャ
void CSceneMain::LoadTexture()
{

}

//メッシュ
void CSceneMain::LoadMesh()
{
	g_Loader.LoadMesh(Model_Player, "Player.obj");
	g_Loader.LoadMesh(Model_Wall, "Wall.obj");
	g_Loader.LoadMesh(Model_Food, "Food.obj");
	g_Loader.LoadMesh(Model_Power_Food, "PowerFood.obj");
	g_Loader.LoadMesh(Model_Enemy_Red, "EnemyRed.obj");
	g_Loader.LoadMesh(Model_Enemy_Blue, "EnemyBlue.obj");
	g_Loader.LoadMesh(Model_Enemy_Orange, "EnemyOrange.obj");
	g_Loader.LoadMesh(Model_Enemy_Pink, "EnemyPink.obj");
	g_Loader.LoadMesh(Model_Enemy_Run, "EnemyRun.obj");
}