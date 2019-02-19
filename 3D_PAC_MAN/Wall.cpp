#include "Math.h"
#include "Task.h"
#include "ObjLoader.h"
#include "Wall.h"
#include "Obb.h"

CWall::CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

void CWall::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_Mesh = g_Task.GetMesh(Model_Wall);

	//最小値・最大値
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//ワールドマトリックス
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

}

void CWall::Update()
{

}

void CWall::Draw()
{
	g_Loader.Draw(m_matWorld, &m_Mesh);
}
