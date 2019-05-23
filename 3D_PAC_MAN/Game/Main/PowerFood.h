#pragma once

#include "../../LIbrary/Main.h"
#include "../../LIbrary/CObj.h" 
#include "../../LIbrary/Obb.h"

#include "Player.h"

//�p���[�a�N���X
class CPowerFood :public CObj3D
{
public:
	//�R���X�g���N�^
	CPowerFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
private:
	OBB_Data m_Obb;		//OBB�f�[�^
	CPlayer* m_pPlayer;	//�v���C���[�̃|�C���^
};

