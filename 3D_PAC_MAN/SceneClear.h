#pragma once

#include "Scene.h"
class CSceneClear :public CScene
{
public:
	CSceneClear() {};
	~CSceneClear() {};

	void Init();
	void Update();
	void Draw();
	void Release();

private:
	void LoadAudio();		//���y
	void LoadTexture();		//�e�N�X�`��
	void LoadMesh();		//���b�V��
};