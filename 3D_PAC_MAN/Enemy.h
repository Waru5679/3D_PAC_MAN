#pragma once

#include "CObj.h"
#include "Player.h"
#include "Obb.h"
#include "Map.h"
#include "Route.h"

//継承用Enemyオブジェクト
class CEnemy :public CObj3D
{
public:
	virtual void Move() = 0;	//移動関数

protected:
	OBB_Data m_Obb;		//OBBデータ
	D3DXVECTOR3 m_vMove;//移動ベクトル
	CPlayer* m_pPlayer;	//プレイヤーのポインタ
	CMap*  m_pMap;		//マップポインタ

	bool m_bRest; //休憩フラグ
	int m_Count;//カウンター

	D3DXVECTOR2 m_vRestPoint[4];//休憩地点
	int m_RestCount;//休憩カウント
	
	float m_fSpeed;//移動スピード

	bool m_bRun;//イジケフラグ

	MY_MESH m_RunMesh;
	D3DXVECTOR2 m_vStartPoint;	//復活位置
	bool m_bEat;//食べられた
};

void PlayerHit(OBB_Data obb,bool run);

//イジケ状態での移動
MY_Pos EnemyRun(MY_Pos Pos,int Start_x,int Start_y,int Goal_x,int Goal_y, CMap* pMap);

