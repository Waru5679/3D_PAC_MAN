#pragma once
#include "CObj.h"

//�N���A�w�i�@�N���X
class CClearBackGround :public CObj2D
{
public:

	CClearBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CClearBackGround() {};

	void Init();
	void Update();
	void Draw();
private:

};