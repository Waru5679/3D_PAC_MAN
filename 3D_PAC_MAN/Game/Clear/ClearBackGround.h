#pragma once

#include "../../LIbrary/CObj.h"

//クリア背景　クラス
class CClearBackGround :public CObj3DBase
{
public:

	CClearBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CClearBackGround() {};

	void Init();
	void Update();
	void Draw();
private:

};