#pragma once
#include "CObj.h"

//�^�C�g���w�i�@�N���X
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