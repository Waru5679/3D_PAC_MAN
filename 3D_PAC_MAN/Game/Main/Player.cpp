#include "../../LIbrary/Task.h"
#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Camera.h"
#include "../../LIbrary/Math.h"

#include "Player.h"

//コンストラクタ
CPlayer::CPlayer(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CPlayer::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);
	
	//モデル
	m_Mesh = g_Task.GetMesh(Model_Player);

	//最小値・最大値
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//移動ベクトル
	m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_vLastMove=m_vMove;

	//移動スピード
	m_fSpeed=0.8f;

	//カウンタ
	m_Count = 0;	

	//パワーカウンタ
	m_PowerCount=0;	
	
	//パワーフラグ
	m_bPower = false;

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);
}

//更新
void CPlayer::Update()
{
	//カウンタ更新
	m_Count++;
	if (m_Count > 10000)
		m_Count = 0;

	//パワー状態
	if (m_bPower == true)
	{
		m_PowerCount--;

		//カウント０でパワー状態解除
		if (m_PowerCount <= 0)
			m_bPower = false;
	}

	//入力
	Input();

	//正規化
	D3DXVec3Normalize(&m_vMove, &m_vMove);

	CMainCamera* m_pCamera=dynamic_cast<CMainCamera*> (g_Task.GetObj(OBJ_MAIN_CAMERA));

	//カメラの向きから移動ベクトルを変換
	m_matRot = MakeMatRot(m_pCamera->GetAngle());
	D3DXVec3TransformCoord(&m_vMove, &m_vMove, &m_matRot);

	//移動
	m_vPos += m_vMove*m_fSpeed;
	
	//当たり判定更新
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//壁に当たった時
	vector<HIT_DATA> HitData;
	HitData = g_Obb.ObjNameHit(&m_Obb, OBJ_WALL);

	if (HitData.size() > 0)
	{
		//移動分戻す
		m_vPos -= m_vMove*m_fSpeed;
	}

	//左右の地点をつなぐ
	if (m_vPos.z < 0.0f)
		m_vPos.z = MAP_Z * 4.0f;

	if ( MAP_Z * 4.0f < m_vPos.z )
		m_vPos.z = 0.0f;
	   
	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	m_vLastMove = m_vMove;
	m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//入力
void CPlayer::Input()
{
	//移動
	if (g_input.GetKeyPush('W') == true)
	{
		m_vMove += D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	}
	if (g_input.GetKeyPush('S') == true)
	{
		m_vMove += D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	}
	if (g_input.GetKeyPush('D') == true)
	{
		m_vMove += D3DXVECTOR3(1.0f, 0.0f, 0.0f);

	}
	if (g_input.GetKeyPush('A') == true)
	{
		m_vMove += D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
	}
}

//描画
void CPlayer::Draw()
{
	g_Loader.Draw(m_matWorld, &m_Mesh);
}
