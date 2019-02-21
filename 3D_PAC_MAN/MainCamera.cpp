#include "MainCamera.h"
#include "Input.h"
#include "DirectX.h"
#include "Task.h"
#include "Player.h"
#include "Math.h"

//������
void CMainCamera::Init()
{
	//�����J�����̈ʒu
	m_vEye = D3DXVECTOR3(0.0f, 15.0f, -2.0f);
	m_vLook = D3DXVECTOR3(0.0f, 10.0f, 10.0f);
	m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);

	m_fCameraDis = 1.0f;
	m_fLookDis = 3.0f;

	m_vDir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

	//�p�x
	m_vAngle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vAngleSave=m_vAngle;

	//�����ɂ��邽�߂̉�]��
	m_vVertical = D3DXVECTOR3(0.79,0.0f,0.0f);

	//�����낵�t���O
	m_bLookingDown=false;
}

//�X�V�֐�
void CMainCamera::Update()
{

	//���_�`�F���W
	if (g_input.GetTriggerKeyPush(VK_SPACE) == true)
	{
		if (m_bLookingDown == true)
		{
			//�����낵����
			m_vAngle = m_vAngleSave;
			m_vVertical = D3DXVECTOR3(0.79f, m_vAngle.y, 0.0f);
		}
		else
		{
			//�����낵
			m_vAngleSave = m_vAngle;
			m_vVertical = D3DXVECTOR3(-4.71f,-1.57f,0.0f);
		}

		//�t���O���]
		m_bLookingDown = !(m_bLookingDown);
	}

	//�ʏ펋�_
	if (m_bLookingDown == false)
	{
		//��]
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

		//�v���C���[�̈ʒu
		CPlayer* m_pPlayer=dynamic_cast<CPlayer*>(g_Task.Get3DObj(OBJ_PLAYER));
		m_vPlayerPos = m_pPlayer->GetPos();

		//�v���C���[�̕���
		m_matRot = MakeMatRot(m_vAngle);
		D3DXVec3TransformCoord(&m_vPlayerDir, &m_vDir, &m_matRot);

		//�����_�ƃJ�����ʒu�����߂�
		m_vLook = m_vPlayerPos + m_vPlayerDir * m_fLookDis;
		m_vEye = m_vPlayerPos - m_vPlayerDir * m_fCameraDis;

		m_vEye.y += 4.0f;

		m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//�v���C���[�̐��ʌ����̃x�N�g��
		m_vFront = m_vPlayerPos - m_vEye;

		m_vFront.y = 0.0f;//�����͖���

		D3DXVec3Normalize(&m_vFront, &m_vFront);

	}

	//�����낵���_
	else
	{
		m_vEye = D3DXVECTOR3(40.0f, 48.0f, 36.0f);
		m_vLook = D3DXVECTOR3(40.0f, 0.0f, 36.0f);
		m_vUp = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
		m_vAngle = D3DXVECTOR3(0.0f, -1.55f, 0.0f);
		
	}

	//���_�V�F�[�_�p�̃}�g���b�N�X�쐬
	CreateVSMatrix(&m_vEye, &m_vLook, &m_vUp, &m_matView, &m_matProj, WINDOW_WIDTH, WINDOW_HEIGHT);
}
