//���C�u�����t�@�C��
#include "../../Library/Math.h"
#include "../../Library/Task.h"
#include "../../Library/ObjLoader.h"

//�Q�[���t�@�C��
#include "PowerFood.h"

//�R���X�g���N�^
CPowerFood::CPowerFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CPowerFood::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_pMesh = g_Loader.GetMesh(Model_Power_Food);

	//�ŏ��l�E�ő�l
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);

	//�v���C���[�̃|�C���g
	m_pPlayer = nullptr;

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//�X�V
void CPowerFood::Update()
{
	//�v���C���[�̃A�h���X�擾
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.GetObj(OBJ_PLAYER));
	}

	//�v���C���[�ɐG�ꂽ�Ƃ�
	if(g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER)==true)
	{
		//�v���C���[���p���[��Ԃɂ���
		m_pPlayer->SetPower();

		//���g���폜
		SetDelete(true);
	}
}

//�`��
void CPowerFood::Draw()
{
	g_Loader.Draw(m_matWorld, m_pMesh,NULL);
}
