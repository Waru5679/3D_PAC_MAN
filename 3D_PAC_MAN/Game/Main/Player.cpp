#include "../../LIbrary/Task.h"
#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Camera.h"
#include "../../LIbrary/Math.h"

#include "Player.h"

//�R���X�g���N�^
CPlayer::CPlayer(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CPlayer::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);
	
	//���f��
	m_Mesh = g_Task.GetMesh(Model_Player);

	//�ŏ��l�E�ő�l
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//�ړ��x�N�g��
	m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_vLastMove=m_vMove;

	//�ړ��X�s�[�h
	m_fSpeed=0.8f;

	//�J�E���^
	m_Count = 0;	

	//�p���[�J�E���^
	m_PowerCount=0;	
	
	//�p���[�t���O
	m_bPower = false;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);
}

//�X�V
void CPlayer::Update()
{
	//�J�E���^�X�V
	m_Count++;
	if (m_Count > 10000)
		m_Count = 0;

	//�p���[���
	if (m_bPower == true)
	{
		m_PowerCount--;

		//�J�E���g�O�Ńp���[��ԉ���
		if (m_PowerCount <= 0)
			m_bPower = false;
	}

	//����
	Input();

	//���K��
	D3DXVec3Normalize(&m_vMove, &m_vMove);

	CMainCamera* m_pCamera=dynamic_cast<CMainCamera*> (g_Task.GetObj(OBJ_MAIN_CAMERA));

	//�J�����̌�������ړ��x�N�g����ϊ�
	m_matRot = MakeMatRot(m_pCamera->GetAngle());
	D3DXVec3TransformCoord(&m_vMove, &m_vMove, &m_matRot);

	//�ړ�
	m_vPos += m_vMove*m_fSpeed;
	
	//�����蔻��X�V
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//�ǂɓ���������
	vector<HIT_DATA> HitData;
	HitData = g_Obb.ObjNameHit(&m_Obb, OBJ_WALL);

	if (HitData.size() > 0)
	{
		//�ړ����߂�
		m_vPos -= m_vMove*m_fSpeed;
	}

	//���E�̒n�_���Ȃ�
	if (m_vPos.z < 0.0f)
		m_vPos.z = MAP_Z * 4.0f;

	if ( MAP_Z * 4.0f < m_vPos.z )
		m_vPos.z = 0.0f;
	   
	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	m_vLastMove = m_vMove;
	m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//����
void CPlayer::Input()
{
	//�ړ�
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

//�`��
void CPlayer::Draw()
{
	g_Loader.Draw(m_matWorld, &m_Mesh);
}
