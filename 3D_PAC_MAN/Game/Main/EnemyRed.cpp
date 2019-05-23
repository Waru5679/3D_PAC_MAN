#include "../../LIbrary/Math.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Obb.h"
#include "../../LIbrary/Route.h"

#include "Player.h"
#include "EnemyRed.h"

//�R���X�g���N�^
CEnemyRed::CEnemyRed(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CEnemyRed::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_Mesh = g_Task.GetMesh(Model_Enemy_Red);

	//�ŏ��l�E�ő�l
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//�C�W�P���f��
	m_RunMesh = g_Task.GetMesh(Model_Enemy_Run);

	//�ړ�������
	m_vMove = D3DXVECTOR3(0.0f, 0.0, 0.0f);

	//�v���C���[�̃A�h���X
	m_pPlayer = nullptr;

	//�}�b�v�̃A�h���X
	m_pMap = dynamic_cast<CMap*> (g_Task.GetObj(OBJ_MAP));

	//�C�W�P���
	m_bRun = false;

	//�J�E���^
	m_Count = 0;

	//�ړ��X�s�[�h
	m_fSpeed = 0.6f;

	//�x�e���
	m_bRest = true;

	//�x�e�n�_
	m_vRestPoint[0] = D3DXVECTOR2(10.0f,2.0f);
	m_vRestPoint[1] = D3DXVECTOR2(16.0f,1.0f);
	m_vRestPoint[2] = D3DXVECTOR2(17.0f,5.0f);
	m_vRestPoint[3] = D3DXVECTOR2(14.0f,5.0f);

	m_RestCount = 0;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}


//���W��n��
MY_Pos CEnemyRed::GetPos()
{
	MY_Pos out;
	out.x = (int)m_vPos.z / 4;
	out.y = (int)m_vPos.x / 4;
	return out;
}

//�X�V
void CEnemyRed::Update()
{
	//�J�E���^�X�V
	m_Count++;

	//300�J�E���g�ŋx�e�ƒǂ������̐؂�ւ�
	if (m_Count > 300)
	{
		m_Count = 0;
		m_bRest = !(m_bRest);
	}
	
	//�v���C���[�̃A�h���X�擾
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.GetObj(OBJ_PLAYER));
	}

	//�v���C���[�̃p���[��Ԃ𒲂ׂ�
	m_bRun = m_pPlayer->GetPower();

	//�ړ�
	Move();	

	//�v���C���[�Ƃ̓����蔻��
	PlayerHit(m_Obb,m_bRun);
	
	//�����蔻��X�V
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//�ړ��֐�
void CEnemyRed::Move()
{
	//���S�ɂ���Ƃ������ړ������X�V
	if ((int)m_vPos.x % 4 == 0 && (int)m_vPos.z % 4 == 0)
	{
		//�ړ�������
		m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		MY_Pos next;
		
		//�T���p
		int Start_x, Start_y, Goal_x, Goal_y;

		//�ʒu��v�f���ɂ���
		Start_x = (int)m_vPos.z / 4;
		Start_y = (int)m_vPos.x / 4;

		//�X�^�[�g�n�_�ɖ߂�����
		if (Start_x == m_vStartPoint.x && Start_y == m_vStartPoint.y)
		{
			m_bEat = false;
		}

		//�H�ׂ�ꂽ��
		if (m_bEat == true)
		{
			Goal_x = (int)m_vStartPoint.x;
			Goal_y = (int)m_vStartPoint.y;

			//�X�^�[�g�n�_��ڎw��
			next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
		}
		else
		{
			//�x�e
			if (m_bRest == true)
			{
				//�x�e�n�_�ɂ��Ǝ��̒n�_��
				if (m_vRestPoint[m_RestCount].x == Start_x && m_vRestPoint[m_RestCount].y == Start_y)
				{
					if (m_RestCount == 3)
						m_RestCount = 0;
					else
						m_RestCount++;
				}
				
				Goal_x = (int)m_vRestPoint[m_RestCount].x;
				Goal_y = (int)m_vRestPoint[m_RestCount].y;

				//�x�e�n�_�ւ̍ŒZ���[�g
				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
			}
			//�ǂ�����
			else
			{
				//�v���C���[�̈ʒu�擾
				D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

				//�v���C���[�ƓG�̈ʒu��v�f���ɂ���
				Goal_x = (int)PlayerPos.z / 4;
				Goal_y = (int)PlayerPos.x / 4;

				//�v���C���[�ւ̍ŒZ���[�g
				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());

			}

			//�p���[���
			if (m_bRun == true)
			{
				//�v���C���[���瓦����
				next = EnemyRun(next, Start_x, Start_y, Goal_x, Goal_y, m_pMap);
			}
		}

		//�ړ������̍X�V
		m_vMove.x = (float)next.y;
		m_vMove.z = (float)next.x;
	}
	//�ړ�
	m_vPos += m_vMove * m_fSpeed;
}

//�`��
void CEnemyRed::Draw()
{
	//�C�W�P���
	if (m_bRun == true)
	{
		g_Loader.Draw(m_matWorld, &m_RunMesh);
	}
	else
	{
		g_Loader.Draw(m_matWorld, &m_Mesh);
	}
}
