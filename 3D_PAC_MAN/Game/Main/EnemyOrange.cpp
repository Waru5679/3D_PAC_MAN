#include <stdlib.h>
#include <time.h>

#include "../../LIbrary/Math.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Obb.h"
#include "../../LIbrary/Route.h"

#include "Player.h"
#include "EnemyOrange.h"

//�R���X�g���N�^
CEnemyOrange::CEnemyOrange(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CEnemyOrange::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_pMesh = g_Loader.GetMesh(Model_Enemy_Orange);

	//�ŏ��l�E�ő�l
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//�C�W�P���f��
	m_pRunMesh = g_Loader.GetMesh(Model_Enemy_Run);
	
	//�ړ�������
	m_vMove = D3DXVECTOR3(0.0f, 0.0, 0.0f);

	//�v���C���[�̃A�h���X
	m_pPlayer = nullptr;

	//�}�b�v�̃A�h���X
	m_pMap = dynamic_cast<CMap*> (g_Task.GetObj(OBJ_MAP));

	//�x�e���
	m_bRest = true;

	//�C�W�P���
	m_bRun = false;

	//�J�E���^
	m_Count = 0;
	
	//�ړ��X�s�[�h
	m_fSpeed = 0.6f;

	//�x�e�n�_
	m_vRestPoint[0] = D3DXVECTOR2(8.0f, 19.0f);
	m_vRestPoint[1] = D3DXVECTOR2(1.0f, 19.0f);
	m_vRestPoint[2] = D3DXVECTOR2(1.0f, 13.0f);
	m_vRestPoint[3] = D3DXVECTOR2(4.0f, 13.0f);

	m_RestCount = 0;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}


//���W��n��
MY_Pos CEnemyOrange::GetPos()
{
	MY_Pos out;
	out.x = (int)m_vPos.z / 4;
	out.y = (int)m_vPos.x / 4;
	return out;
}

//�X�V
void CEnemyOrange::Update()
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
	PlayerHit(m_Obb, m_bRun);

	//�����蔻��X�V
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//�ړ��֐�
void CEnemyOrange::Move()
{
	//���S�ɂ���Ƃ������ړ������X�V
	if ((int)m_vPos.x % 4 == 0 && (int)m_vPos.z % 4 == 0)
	{
		//�ړ�������
		m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		MY_Pos next;

		//�T���p
		int Start_x, Start_y, Goal_x, Goal_y;

		//�x�e
		if (m_bRest == true)
		{
			Start_x = (int)m_vPos.z / 4;
			Start_y = (int)m_vPos.x / 4;

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

			next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
		}
		else
		{
			//�v���C���[�̈ʒu�擾
			D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

			//�v���C���[�ƓG�̈ʒu��v�f���ɂ���
			Goal_x = (int)PlayerPos.z / 4;
			Goal_y = (int)PlayerPos.x / 4;
			Start_x = (int)m_vPos.z / 4;
			Start_y = (int)m_vPos.x / 4;

			//�v���C���[��2�}�X�ȓ��ɂ���Ȃ�
			if (abs(Start_x - Goal_x) > 2 || abs(Start_y - Goal_y) > 2)
			{
				//�v���C���[�̈ʒu�ւ̍ŒZ���[�g��T��
				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());

			}
			else
			{
				//�����_���Ȓn�_�ւ̍ŒZ���[�g��T��
				int npc = 0;
				
				srand((unsigned int)time(NULL));
				npc = rand() % MAP_Z;

				Goal_x = npc;

				srand((unsigned int)time(NULL));
				npc = rand() % MAP_X;

				Goal_y = npc;

				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
			}
		}

		//�p���[���
		if (m_bRun == true)
		{
			//�v���C���[���瓦����
			next = EnemyRun(next, Start_x, Start_y, Goal_x, Goal_y, m_pMap);
		}

		//�ړ������̍X�V
		m_vMove.x = (float)next.y;
		m_vMove.z = (float)next.x;
	}
	//�ړ�
	m_vPos += m_vMove* m_fSpeed;;
}

//�`��
void CEnemyOrange::Draw()
{
	//�C�W�P���
	if (m_bRun == true)
	{
		g_Loader.Draw(m_matWorld, m_pRunMesh,NULL);
	}
	else
	{
		g_Loader.Draw(m_matWorld, m_pMesh,NULL);
	}
}
