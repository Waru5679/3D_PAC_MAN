#pragma once

#include "../../LIbrary/Scene.h"

//�V�[���^�C�g��
class CSceneTitle :public CScene
{
public:
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
	void Release();	//���
private:
	void LoadAudio();		//���y
	void LoadTexture();		//�e�N�X�`��
	void LoadMesh();		//���b�V��
};