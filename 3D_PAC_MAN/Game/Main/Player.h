#pragma once

#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

#include "MainCamera.h"

//無敵時間
#define POWER_TIME 100

//プレイヤークラス
class CPlayer:public CObj3D
{
public:
	CPlayer(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CPlayer() {};

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
	void Input();	//入力

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }
	D3DXVECTOR3 GetDir() { return m_vLastMove; }

	bool GetPower() { return m_bPower; }

	//パワー状態
	void SetPower() 
	{
		m_bPower = true; 
		m_PowerCount = POWER_TIME;
	}

private:
	D3DXVECTOR3 m_vMove;	//移動
	D3DXVECTOR3 m_vLastMove;//最後の移動
	OBB_Data m_Obb;			//OBB情報
	float m_fSpeed;			//移動スピード
	int m_Count;			//カウンタ
	int m_PowerCount;		//パワーカウンタ
	bool m_bPower;			//パワーフラグ
};

