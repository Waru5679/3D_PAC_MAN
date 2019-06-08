#pragma once

#include "../../Library/CObj.h"
#include "../../Library/Obb.h"
#include "../../Library/Route.h"

#include "Player.h"
#include "Map.h"

//継承用Enemyオブジェクト
class CEnemy :public CObj3DBase
{
public:
	virtual void Move() = 0;	//移動関数

protected:
	D3DXVECTOR3 m_vMove;		//移動ベクトル
	D3DXVECTOR2 m_vStartPoint;	//復活位置
	D3DXVECTOR2 m_vRestPoint[4];//休憩地点

	int m_Count;	//カウンター
	int m_RestCount;//休憩カウント
	float m_fSpeed;	//移動スピード

	bool m_bRun;	//イジケフラグ
	bool m_bEat;	//食べられた
	bool m_bRest;	//休憩フラグ
	
	MY_MESH* m_pRunMesh;	//逃げるときのメッシュデータ
	CPlayer* m_pPlayer;	//プレイヤーのポインタ
	CMap*  m_pMap;		//マップポインタ
	OBB_Data m_Obb;		//OBBデータ

};

//プレイヤーとのヒット確認
void PlayerHit(OBB_Data obb,bool run);

//イジケ状態での移動
MY_Pos EnemyRun(MY_Pos Pos,int Start_x,int Start_y,int Goal_x,int Goal_y, CMap* pMap);

