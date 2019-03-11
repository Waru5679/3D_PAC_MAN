#include "PowerFood.h"
#include "Math.h"
#include "Task.h"
#include "ObjLoader.h"

CPowerFood::CPowerFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CPowerFood::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_Mesh = g_Task.GetMesh(Model_Power_Food);

	//最小値・最大値
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

	//プレイヤーのポイント
	m_pPlayer = nullptr;

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

void CPowerFood::Update()
{

	//プレイヤーのアドレス取得
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.GetObj(OBJ_PLAYER));
	}

	vector<HIT_DATA> HitData;
	HitData = g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER);

	//プレイヤーに触れたとき
	if (HitData.size() > 0)
	{
		//プレイヤーをパワー状態にする
		m_pPlayer->SetPower();

		//自身を削除
		m_fDelete = true;
	}
}

void CPowerFood::Draw()
{
	g_Loader.Draw(m_matWorld, &m_Mesh);
}
