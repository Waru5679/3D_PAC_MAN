#pragma once
#include "CObj.h"
#include "Obb.h"

class CWall :public CObj3D
{
public:
	CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CWall() {};
	void Init();
	void Update();
	void Draw();
private:
	OBB_Data m_Obb;
};