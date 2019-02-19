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
	void LoadAudio();		//音楽
	void LoadTexture();		//テクスチャ
	void LoadMesh();		//メッシュ
};