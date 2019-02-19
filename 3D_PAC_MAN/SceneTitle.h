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
	void LoadAudio();		//音楽
	void LoadTexture();		//テクスチャ
	void LoadMesh();		//メッシュ
};