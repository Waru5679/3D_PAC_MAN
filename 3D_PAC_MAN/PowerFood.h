#pragma once

//必要なライブラリファイルのロード
#include "Main.h"
#include "CObj.h" 
#include "Obb.h"
#include "Player.h"
//パワー餌クラス
class CPowerFood :public CObj3D
{
public:
	CPowerFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CPowerFood() {};

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();
	void Update();
	void Draw();
private:
	OBB_Data m_Obb;
	CPlayer* m_pPlayer;

};

