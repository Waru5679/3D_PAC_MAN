#pragma once
#include "CObj.h"

//タイトル背景　クラス
class CTitleBackGround :public CObj2D
{
public:

	CTitleBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CTitleBackGround() {};

	void Init();
	void Update();
	void Draw();
private:
	float m_z;
};