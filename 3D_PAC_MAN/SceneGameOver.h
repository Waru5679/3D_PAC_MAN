#pragma once

#include "Scene.h"
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver() {};
	~CSceneGameOver() {};

	void Init();
	void Update();
	void Draw();
	void Release();

private:
	void LoadAudio();		//���y
	void LoadTexture();		//�e�N�X�`��
	void LoadMesh();		//���b�V��
};