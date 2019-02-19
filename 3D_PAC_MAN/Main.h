#pragma once

//�K�v�ȃw�b�_�[�t�@�C���̃C���N���[�h
#include <windows.h>
#include <D3D10.h>
#include <d3dx10.h>

//�K�v�ȃ��C�u�����t�@�C���̃��[�h
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")

//�萔
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//�V�[���ǂݍ���
void LoadScene();

//�E�C���h�E��
static WCHAR szAppName[] = L"���C�u����";
//static char szAppName[] = "���C�u����";

//���߂̃V�[��
#define START_SCENE SceneTitle

//�}�b�v�v�f
#define MAP_X 21
#define MAP_Y 2
#define MAP_Z 19
#define MAP_ARRAY_NUM (MAP_X*MAP_Y*MAP_Z) 

//�I�u�W�F�N�g
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

//���y
enum AudioName
{
	Audio_Stage,
	Audio_Food_Get,
	Audio_Damage,

};

//�V�[��
enum SceneName
{
	SceneMain,
	SceneTitle,
	SceneClear,
	SceneGameOver,
};

//���f��
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
