#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Route.h"
#include "../../LIbrary/Audio.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Shader.h"

#include "SceneMain.h"
#include "MainCamera.h"
#include "Map.h"

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
	g_Task.InsertObj(map, OBJ_MAP);
	map->Create();

	//カメラ
	CMainCamera* pCamera = new CMainCamera();
	g_Task.InsertObj(pCamera, OBJ_MAIN_CAMERA);
	
	//シェーダーにカメラセット
	g_Shader.SetCamera(pCamera);
	
	//2D描画用カメラセット
	g_Draw.SetCamera(pCamera);
	
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

//解放
void CSceneMain::Release()
{
	g_Task.Release();	//オブジェクトデータ破棄
	g_Audio.DeleteMusic();//音楽データ破棄
}

//音楽
void CSceneMain::LoadAudio()
{
	g_Audio.Load(Audio_Stage	,"../../Audio/Stage.wav"	,true);
	g_Audio.Load(Audio_Food_Get	,"../../Audio/FoodGet.wav"	, false);
	g_Audio.Load(Audio_Damage	,"../../Audio/Damage.wav"	,false);
}

//テクスチャ
void CSceneMain::LoadTexture()
{

}

//メッシュ
void CSceneMain::LoadMesh()
{
	g_Loader.LoadMesh(Model_Player		, "../../OBJ/Player.obj");
	g_Loader.LoadMesh(Model_Wall		, "../../OBJ/Wall.obj");
	g_Loader.LoadMesh(Model_Food		, "../../OBJ/Food.obj");
	g_Loader.LoadMesh(Model_Power_Food	, "../../OBJ/PowerFood.obj");
	g_Loader.LoadMesh(Model_Enemy_Red	, "../../OBJ/EnemyRed.obj");
	g_Loader.LoadMesh(Model_Enemy_Blue	, "../../OBJ/EnemyBlue.obj");
	g_Loader.LoadMesh(Model_Enemy_Orange, "../../OBJ/EnemyOrange.obj");
	g_Loader.LoadMesh(Model_Enemy_Pink	, "../../OBJ/EnemyPink.obj");
	g_Loader.LoadMesh(Model_Enemy_Run	, "../../OBJ/EnemyRun.obj");
}