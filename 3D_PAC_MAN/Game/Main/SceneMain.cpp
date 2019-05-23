#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Route.h"
#include "../../LIbrary/Audio.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Shader.h"

#include "SceneMain.h"
#include "MainCamera.h"
#include "Map.h"

//������
void CSceneMain::Init()
{
	//���y������
	g_Audio.Init();

	//�f�ޓǂݍ���
	LoadTexture();
	LoadAudio();
	LoadMesh();
		
	//�}�b�v
	CMap* map = new CMap();
	g_Task.InsertObj(map, OBJ_MAP);
	map->Create();

	//�J����
	CMainCamera* pCamera = new CMainCamera();
	g_Task.InsertObj(pCamera, OBJ_MAIN_CAMERA);
	
	//�V�F�[�_�[�ɃJ�����Z�b�g
	g_Shader.SetCamera(pCamera);
	
	//2D�`��p�J�����Z�b�g
	g_Draw.SetCamera(pCamera);
	
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 1.0f);
	
	//�_�C�N�X�g���@������
	g_Route.Init(MAP_Z,MAP_X);
	
	//���ʐݒ�
	g_Audio.MasterVolume(0.8f);

	//���y�X�^�[�g
	g_Audio.StartMusic(Audio_Stage);
}

//�X�V
void CSceneMain::Update()
{
	g_Task.Update();
}

//�`��
void CSceneMain::Draw()
{
	g_Task.Draw();
}

//���
void CSceneMain::Release()
{
	g_Task.Release();	//�I�u�W�F�N�g�f�[�^�j��
	g_Audio.DeleteMusic();//���y�f�[�^�j��
}

//���y
void CSceneMain::LoadAudio()
{
	g_Audio.Load(Audio_Stage	,"../../Audio/Stage.wav"	,true);
	g_Audio.Load(Audio_Food_Get	,"../../Audio/FoodGet.wav"	, false);
	g_Audio.Load(Audio_Damage	,"../../Audio/Damage.wav"	,false);
}

//�e�N�X�`��
void CSceneMain::LoadTexture()
{

}

//���b�V��
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