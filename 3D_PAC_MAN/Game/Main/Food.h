#pragma once

//必要なライブラリファイルのロード
#include "../../LIbrary/Main.h"
#include "../../LIbrary/CObj.h" 
#include "../../LIbrary/Obb.h"

//餌クラス
class CFood :public CObj3D
{
public:
	CFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CFood() {};

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();
	void Update();
	void Draw();
private:
	OBB_Data m_Obb;
};

