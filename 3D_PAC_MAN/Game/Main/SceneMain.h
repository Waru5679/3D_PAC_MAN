#pragma once

#include "../../LIbrary/Scene.h"

//�V�[�����C��
class CSceneMain :public CScene
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