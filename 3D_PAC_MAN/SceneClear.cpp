#include "SceneClear.h"
#include "Task.h"
#include "Camera.h"
#include "ObjLoader.h"
#include "Audio.h"
#include "Input.h"
#include "ClearCamera.h"
#include "Shader.h"
#include "ClearBackGround.h"
#include "Polygon.h"
#include "Font.h"

//初期化
void CSceneClear::Init()
{
	//音楽初期化
	g_Audio.Init();

	//素材読み込み
	LoadTexture();
	LoadAudio();
	LoadMesh();

	//カメラ
	CClearCamera* pCamera = new CClearCamera();
	g_Task.InsertObj(pCamera, OBJ_CLEAR_CAMERA);

	//シェーダにカメラセット
	g_Shader.SetCamera(pCamera);
	//2D描画用カメラセット
	g_Draw.SetCamera(pCamera);

	//背景オブジェクト
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);

	CClearBackGround* back = new CClearBackGround(Pos, Angle, Scale);
	g_Task.InsertObj(back, 0);

}

//更新
void CSceneClear::Update()
{
	g_Task.Update();

	//エンターキーでタイトルへ
	if (g_input.GetTriggerKeyPush(VK_RETURN) == true)
	{
		g_Scene.SetScene(SceneTitle);
	}
}

//描画
void CSceneClear::Draw()
{
	g_Task.Draw();
}

//解放
void CSceneClear::Release()
{
	g_Task.Release();
}

//音楽
void CSceneClear::LoadAudio()
{
}

//テクスチャ
void CSceneClear::LoadTexture()
{
}

//メッシュ
void CSceneClear::LoadMesh()
{
}