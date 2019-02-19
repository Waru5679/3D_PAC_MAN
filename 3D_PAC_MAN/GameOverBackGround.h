#pragma once
#include "CObj.h"

//ゲームオーバー　背景　クラス
class CGameOverBackGround :public CObj2D
{
public:

	CGameOverBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CGameOverBackGround() {};

	void Init();
	void Update();
	void Draw();
private:

};