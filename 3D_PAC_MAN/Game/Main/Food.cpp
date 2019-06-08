#include "../../LIbrary/Task.h"
#include "../../LIbrary/ObjLoader.h"
#include "../../LIbrary/Audio.h"
#include "../../LIbrary/Math.h"

#include "Food.h"
#include "Map.h"

//�R���X�g���N�^
CFood::CFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CFood::Init()
{
	//�s�񏉊���
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//���f��
	m_pMesh = g_Loader.GetMesh(Model_Food);

	//�ŏ��l�E�ő�l
	m_vMin = m_pMesh->vMin;
	m_vMax = m_pMesh->vMax;

	//�����蔻��Z�b�g
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, GetId(), this);
	g_Obb.Insert(&m_Obb);

	//���[���h�s��쐬
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//�X�V
void CFood::Update()
{
	//�v���C���[�ɐG�ꂽ�Ƃ�
	if (g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER)==true)
	{
		//�a�擾��
		g_Audio.StartMusic(Audio_Food_Get);

		//�a�̃J�E���g���炷
		CMap* map = dynamic_cast<CMap*>(g_Task.GetObj(OBJ_MAP));
		map->CountAdd(-1);
		
		//���g���폜
		SetDelete(true);
	}
}

//�`��
void CFood::Draw()
{
	g_Loader.Draw(m_matWorld, m_pMesh,NULL);
}
