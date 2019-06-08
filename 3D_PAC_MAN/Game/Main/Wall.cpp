//���C�u�����t�@�C��
#include "../../Library/Math.h"
#include "../../Library/Task.h"
#include "../../Library/ObjLoader.h"
#include "../../Library/Obb.h"

//�Q�[���t�@�C��
#include "Wall.h"

//�R���X�g���N�^
CWall::CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CWall::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_pMesh = g_Loader.GetMesh(Model_Wall);

	//�ŏ��l�E�ő�l
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//���[���h�}�g���b�N�X
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);
}

//�X�V
void CWall::Update()
{
}

//�`��
void CWall::Draw()
{
	g_Loader.Draw(m_matWorld, m_pMesh,NULL);
}
