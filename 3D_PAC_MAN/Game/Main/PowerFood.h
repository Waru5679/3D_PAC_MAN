#pragma once

//���C�u�����t�@�C��
#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

//�Q�[���t�@�C��
#include "Player.h"

//�p���[�a�N���X
class CPowerFood :public CObj3DBase
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

