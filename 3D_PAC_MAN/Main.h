#pragma once

//必要なヘッダーファイルのインクルード
#include <windows.h>
#include <D3D10.h>
#include <d3dx10.h>

//必要なライブラリファイルのロード
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")

//定数
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//シーン読み込み
void LoadScene();

//ウインドウ名
static WCHAR szAppName[] = L"ライブラリ";
//static char szAppName[] = "ライブラリ";

//初めのシーン
#define START_SCENE SceneTitle

//マップ要素
#define MAP_X 21
#define MAP_Y 2
#define MAP_Z 19
#define MAP_ARRAY_NUM (MAP_X*MAP_Y*MAP_Z) 

//オブジェクト
enum ObjName
{
	OBJ_PLAYER,
	OBJ_WALL,
	OBJ_MAP,
	OBJ_FOOD,
	OBJ_POWER_FOOD,
	OBJ_ENEMY_RED,
	OBJ_ENEMY_BLUE,
	OBJ_ENEMY_ORANGE,
	OBJ_ENEMY_PINK,
	OBJ_CAMERA,
};

//音楽
enum AudioName
{
	Audio_Stage,
	Audio_Food_Get,
	Audio_Damage,

};

//シーン
enum SceneName
{
	SceneMain,
	SceneTitle,
	SceneClear,
	SceneGameOver,
};

//モデル
enum ModelName
{
	Model_Player,
	Model_Wall,
	Model_Food,
	Model_Power_Food,
	Model_Enemy_Red,
	Model_Enemy_Blue,
	Model_Enemy_Orange,
	Model_Enemy_Pink,
	Model_Enemy_Run,
};
