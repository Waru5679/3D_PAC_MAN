#pragma once

#include "../../LIbrary/Scene.h"

//クリアシーン　
class CSceneClear :public CSceneBase
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