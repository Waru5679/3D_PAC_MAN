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

//������
void CSceneClear::Init()
{
	//���y������
	g_Audio.Init();

	//�f�ޓǂݍ���
	LoadTexture();
	LoadAudio();
	LoadMesh();

	//�J����
	CClearCamera* pCamera = new CClearCamera();
	g_Task.InsertObj(pCamera, OBJ_CLEAR_CAMERA);

	//�V�F�[�_�ɃJ�����Z�b�g
	g_Shader.SetCamera(pCamera);
	//2D�`��p�J�����Z�b�g
	g_Draw.SetCamera(pCamera);

	//�w�i�I�u�W�F�N�g
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);

	CClearBackGround* back = new CClearBackGround(Pos, Angle, Scale);
	g_Task.InsertObj(back, 0);

}

//�X�V
void CSceneClear::Update()
{
	g_Task.Update();

	//�G���^�[�L�[�Ń^�C�g����
	if (g_input.GetTriggerKeyPush(VK_RETURN) == true)
	{
		g_Scene.SetScene(SceneTitle);
	}
}

//�`��
void CSceneClear::Draw()
{
	g_Task.Draw();
}

//���
void CSceneClear::Release()
{
	g_Task.Release();
}

//���y
void CSceneClear::LoadAudio()
{
}

//�e�N�X�`��
void CSceneClear::LoadTexture()
{
}

//���b�V��
void CSceneClear::LoadMesh()
{
}