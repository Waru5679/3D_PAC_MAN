#pragma once

#include "Scene.h"
class CSceneTitle :public CScene
{
public:
	CSceneTitle() {};
	~CSceneTitle() {};

	void Init();
	void Update();
	void Draw();
	void Release();

private:
	void LoadAudio();		//���y
	void LoadTexture();		//�e�N�X�`��
	void LoadMesh();		//���b�V��
};