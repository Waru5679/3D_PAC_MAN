#include "EnemyBlue.h"
#include "Math.h"
#include "Task.h"
#include "Obb.h"
#include "Route.h"
#include "Player.h"

//�R���X�g���N�^
CEnemyBlue::CEnemyBlue(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CEnemyBlue::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_Mesh = g_Task.GetMesh(Model_Enemy_Blue);

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
	m_pMap = dynamic_cast<CMap*> (g_Task.Get3DObj(OBJ_MAP));

	//�Ԃ��G�̃A�h���X
	m_pRedEnemy = nullptr;

	//�x�e���
	m_bRest = true;
	
	//�C�W�P���
	m_bRun = false;

	//�J�E���^
	m_Count = 0;

	//�ړ��X�s�[�h
	m_fSpeed=0.6f;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//�x�e�n�_
	m_vRestPoint[0] = D3DXVECTOR2(17.0f, 13.0f);
	m_vRestPoint[1] = D3DXVECTOR2(17.0f, 19.0f);
	m_vRestPoint[2] = D3DXVECTOR2(10.0f, 19.0f);
	m_vRestPoint[3] = D3DXVECTOR2(12.0f, 15.0f);

	m_RestCount = 0;

	//�����ʒu
	m_vStartPoint=D3DXVECTOR2(9.0f,9.0f);

	//�H�ׂ�ꂽ
	m_bEat = false;

}
//�X�V
void CEnemyBlue::Update()
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
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.Get3DObj(OBJ_PLAYER));
	}

	//�v���C���[�̃p���[��Ԃ𒲂ׂ�
	m_bRun = m_pPlayer->GetPower();

	//�Ԃ��G�̃A�h���X�擾
	if (m_pRedEnemy == nullptr)
	{
		m_pRedEnemy = dynamic_cast<CEnemyRed*> (g_Task.Get3DObj(OBJ_ENEMY_RED));
	}

	//�v���C���[�ɐG�ꂽ�Ƃ�
	vector<HIT_DATA> HitData;
	HitData = g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER);

	if (HitData.size() > 0)
	{
		//�H�ׂ�ꂽ
		m_bEat = true;
	}

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
void CEnemyBlue::Move()
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

				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());

			}
			//�ǂ�����
			else
			{
				//�v���C���[�̈ʒu�擾
				D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

				//�G�̈ʒu��v�f���ɂ���
				Goal_x = (int)PlayerPos.z / 4;
				Goal_y = (int)PlayerPos.x / 4;
				
				//�_�Ώۈʒu��ڎw��
				next = Symmetrical(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
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
	m_vPos += m_vMove * m_fSpeed;;
}

//�ŒZ���[�g�T���̃X�^�[�g�ʒu�ƃS�[���ʒu��ς��ĒT������
MY_Pos CEnemyBlue::Symmetrical(int Start_x, int Start_y, int Goal_x, int Goal_y,int** Array)//, int Size_x ,int Size_y)
{
	MY_Pos out;
	
	//�����̒��S�ɂȂ�ꏊ
	MY_Pos center;

	//���S�_����̋���
	MY_Pos Dis;

	//�Ԃ��G�̈ʒu�������Ă���
	MY_Pos RedEnemyPos;
	RedEnemyPos = m_pRedEnemy->GetPos();
	
	//�v���C���[�ƓG�̒��ԂƂ̋��������߂�
	Dis.x = abs(Goal_x - RedEnemyPos.x) / 2;
	Dis.y = abs(Goal_y - RedEnemyPos.y) / 2;

	//x,y���ꂼ��̍��W�̏������ق������ɒ��S�_�����߂�B
	if (Goal_x < RedEnemyPos.x)
		center.x = Dis.x + Goal_x;
	else
		center.x = Dis.x + RedEnemyPos.x;

	if (Goal_y < RedEnemyPos.y)
		center.y = Dis.y + Goal_y;
	else
		center.y = Dis.y + RedEnemyPos.y;

	//�v���C���[�𒆐S�_�Ɠ_�Ώ̂Ɉړ����������̒��S�_�Ƃ̋���
	Dis.x = (Goal_x - center.x)*(-1);
	Dis.y = (Goal_y - center.y)*(-1);

	Goal_x = center.x + Dis.x;
	Goal_y = center.y + Dis.y;

	//��ԋ߂��}�b�v�̈ʒu�ɂ���
	g_Route.NearInMap(Goal_x,Goal_y);
	
	//�ړ����[�g�����߂�
	out = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, Array);

	return out;
}

//�`��
void CEnemyBlue::Draw()
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
