#include "../../LIbrary/Task.h"
#include "../../LIbrary/Camera.h"
#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Audio.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Shader.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Font.h"

#include "TitleBackGround.h"
#include "TitleCamera.h"
#include "SceneTitle.h"

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
	CTitleCamera* pCamera = new CTitleCamera();
	g_Task.InsertObj(pCamera,OBJ_TITLE_CAMERA);

	//�V�F�[�_�ɃJ�����Z�b�g
	g_Shader.SetCamera(pCamera);
	//2D�`��p�J�����Z�b�g
	g_Draw.SetCamera(pCamera);
	
	//�w�i�I�u�W�F�N�g
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Angle(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 0.0f);
	
	CTitleBackGround* back = new CTitleBackGround(Pos, Angle, Scale);
	g_Task.InsertObj(back, 0);

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
}

//�e�N�X�`��
void CSceneTitle::LoadTexture()
{
	g_Draw.LoadTexture(0, "../../Texture/Title.png");
}

//���b�V��
void CSceneTitle::LoadMesh()
{
}