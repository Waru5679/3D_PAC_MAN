#include "Math.h"
#include "Task.h"
#include "ObjLoader.h"
#include "Wall.h"
#include "Obb.h"

CWall::CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

void CWall::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_Mesh = g_Task.GetMesh(Model_Wall);

	//�ŏ��l�E�ő�l
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//���[���h�}�g���b�N�X
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

}

void CWall::Update()
{

}

void CWall::Draw()
{
	g_Loader.Draw(m_matWorld, &m_Mesh);
}
