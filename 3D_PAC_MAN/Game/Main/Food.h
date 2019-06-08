#pragma once

//�K�v�ȃ��C�u�����t�@�C���̃��[�h
#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

//�a�N���X
class CFood :public CObj3DBase
{
public:
	//�R���X�g���N�^
	CFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CFood() {};

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
private:
	OBB_Data m_Obb;	//OBB�f�[�^
};

