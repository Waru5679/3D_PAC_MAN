//ライブラリファイル
#include "../../Library/Math.h"
#include "../../Library/Task.h"
#include "../../Library/ObjLoader.h"
#include "../../Library/Obb.h"

//ゲームファイル
#include "Wall.h"

//コンストラクタ
CWall::CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CWall::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_pMesh = g_Loader.GetMesh(Model_Wall);

	//最小値・最大値
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//ワールドマトリックス
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);
}

//更新
void CWall::Update()
{
}

//描画
void CWall::Draw()
{
	g_Loader.Draw(m_matWorld, m_pMesh,NULL);
}
