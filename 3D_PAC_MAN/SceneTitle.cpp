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

//������
void CSceneTitle::Init()
{
	//���y������
	g_Audio.Init();

	//�f�ޓǂݍ���
	LoadTexture();
	LoadAudio();
	LoadMesh();

	//�J����
	CTitleCamera* camera = new CTitleCamera();
	g_Task.InsertCamera(camera,0);

	//�V�F�[�_�ɃJ�����Z�b�g
	g_Shader.SetCamera(camera);

	//�w�i�I�u�W�F�N�g
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);
	
	CTitleBackGround* back = new CTitleBackGround(Pos, Angle, Scale);
	g_Task.Insert2DObj(back, 0);

}

//�X�V
void CSceneTitle::Update()
{
	g_Task.Update();

	//�G���^�[�L�[�ŃV�[�����C����
	if (g_input.GetTriggerKeyPush(VK_RETURN) == true)
	{
		g_Scene.SetScene(SceneMain);
	}
}

//�`��
void CSceneTitle::Draw()
{
	g_Task.Draw();
}

//���
void CSceneTitle::Release()
{
	g_Task.Release();
}

//���y
void CSceneTitle::LoadAudio()
{
	g_Audio.Load(Audio_Stage, "Stage.wav", true);
	g_Audio.Load(Audio_Food_Get, "FoodGet.wav", false);
}

//�e�N�X�`��
void CSceneTitle::LoadTexture()
{
	g_Draw.LoadTexture(0, "Title.png");
	g_Draw.LoadTexture(1, "EnemyRed.png");
}

//���b�V��
void CSceneTitle::LoadMesh()
{
}