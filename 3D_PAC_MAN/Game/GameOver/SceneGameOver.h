#pragma once

#include "../../Library/Scene.h"

//�Q�[���I�[�o�[�N���X
class CSceneGameOver :public CSceneBase
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