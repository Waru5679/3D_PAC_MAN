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
	void LoadAudio();		//音楽
	void LoadTexture();		//テクスチャ
	void LoadMesh();		//メッシュ
};