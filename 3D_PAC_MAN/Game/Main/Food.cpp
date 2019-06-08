#include "../../LIbrary/Task.h"
#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Audio.h"
#include "../../LIbrary/Math.h"

#include "Food.h"
#include "Map.h"

//コンストラクタ
CFood::CFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CFood::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_pMesh = g_Loader.GetMesh(Model_Food);

	//最小値・最大値
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//更新
void CFood::Update()
{
	//プレイヤーに触れたとき
	if (g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER)==true)
	{
		//餌取得音
		g_Audio.StartMusic(Audio_Food_Get);

		//餌のカウント減らす
		CMap* map = dynamic_cast<CMap*>(g_Task.GetObj(OBJ_MAP));
		map->CountAdd(-1);
		
		//自身を削除
		SetDelete(true);
	}
}

//描画
void CFood::Draw()
{
	g_Loader.Draw(m_matWorld, m_pMesh,NULL);
}
