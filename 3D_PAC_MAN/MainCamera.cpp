#include "MainCamera.h"
#include "Input.h"
#include "DirectX.h"
#include "Task.h"
#include "Player.h"
#include "Math.h"

//初期化
void CMainCamera::Init()
{
	//初期カメラの位置
	m_vEye = D3DXVECTOR3(0.0f, 15.0f, -2.0f);
	m_vLook = D3DXVECTOR3(0.0f, 10.0f, 10.0f);
	m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);

	m_fCameraDis = 1.0f;
	m_fLookDis = 3.0f;

	m_vDir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

	//角度
	m_vAngle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vAngleSave=m_vAngle;

	//垂直にするための回転量
	m_vVertical = D3DXVECTOR3(0.79,0.0f,0.0f);

	//見下ろしフラグ
	m_bLookingDown=false;
}

//更新関数
void CMainCamera::Update()
{

	//視点チェンジ
	if (g_input.GetTriggerKeyPush(VK_SPACE) == true)
	{
		if (m_bLookingDown == true)
		{
			//見下ろし解除
			m_vAngle = m_vAngleSave;
			m_vVertical = D3DXVECTOR3(0.79f, m_vAngle.y, 0.0f);
		}
		else
		{
			//見下ろし
			m_vAngleSave = m_vAngle;
			m_vVertical = D3DXVECTOR3(-4.71f,-1.57f,0.0f);
		}

		//フラグ反転
		m_bLookingDown = !(m_bLookingDown);
	}

	//通常視点
	if (m_bLookingDown == false)
	{
		//回転
		if (g_input.GetKeyPush(VK_LEFT) == true)
		{
			m_vAngle.y -= 0.2f;
			m_vVertical.y = m_vAngle.y;
		}

		if (g_input.GetKeyPush(VK_RIGHT) == true)
		{
			m_vAngle.y += 0.2f;
			m_vVertical.y = m_vAngle.y;
		}

		//プレイヤーの位置
		CPlayer* m_pPlayer=dynamic_cast<CPlayer*>(g_Task.Get3DObj(OBJ_PLAYER));
		m_vPlayerPos = m_pPlayer->GetPos();

		//プレイヤーの方向
		m_matRot = MakeMatRot(m_vAngle);
		D3DXVec3TransformCoord(&m_vPlayerDir, &m_vDir, &m_matRot);

		//注視点とカメラ位置を求める
		m_vLook = m_vPlayerPos + m_vPlayerDir * m_fLookDis;
		m_vEye = m_vPlayerPos - m_vPlayerDir * m_fCameraDis;

		m_vEye.y += 4.0f;

		m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//プレイヤーの正面向きのベクトル
		m_vFront = m_vPlayerPos - m_vEye;

		m_vFront.y = 0.0f;//高さは無視

		D3DXVec3Normalize(&m_vFront, &m_vFront);

	}

	//見下ろし視点
	else
	{
		m_vEye = D3DXVECTOR3(40.0f, 48.0f, 36.0f);
		m_vLook = D3DXVECTOR3(40.0f, 0.0f, 36.0f);
		m_vUp = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
		m_vAngle = D3DXVECTOR3(0.0f, -1.55f, 0.0f);
		
	}

	//頂点シェーダ用のマトリックス作成
	CreateVSMatrix(&m_vEye, &m_vLook, &m_vUp, &m_matView, &m_matProj, WINDOW_WIDTH, WINDOW_HEIGHT);
}
