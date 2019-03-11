#include "SceneGameOver.h"
#include "Task.h"
#include "Camera.h"
#include "ObjLoader.h"
#include "Audio.h"
#include "Input.h"
#include "GameOverCamera.h"
#include "Shader.h"
#include "GameOverBackGround.h"
#include "Polygon.h"
#include "Font.h"

//������
void CSceneGameOver::Init()
{
	//���y������
	g_Audio.Init();

	//�f�ޓǂݍ���
	LoadTexture();
	LoadAudio();
	LoadMesh();

	//�J����
	CGameOverCamera* pCamera = new CGameOverCamera();
	g_Task.InsertObj(pCamera, OBJ_GAMEOVER_CAMERA);

	//�V�F�[�_�ɃJ�����Z�b�g
	g_Shader.SetCamera(pCamera);
	//2D�`��p�J�����Z�b�g
	g_Draw.SetCamera(pCamera);

	//�w�i�I�u�W�F�N�g
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);

	CGameOverBackGround* back = new CGameOverBackGround(Pos, Angle, Scale);
	g_Task.InsertObj(back, 0);
}

//�X�V
void CSceneGameOver::Update()
{
	g_Task.Update();

	//�G���^�[�L�[�Ń^�C�g����
	if (g_input.GetTriggerKeyPush(VK_RETURN) == true)
	{
		g_Scene.SetScene(SceneTitle);
	}
}

//�`��
void CSceneGameOver::Draw()
{
	g_Task.Draw();
}

//���
void CSceneGameOver::Release()
{
	g_Task.Release();
}

//���y
void CSceneGameOver::LoadAudio()
{
}

//�e�N�X�`��
void CSceneGameOver::LoadTexture()
{
}

//���b�V��
void CSceneGameOver::LoadMesh()
{
}