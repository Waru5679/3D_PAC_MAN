#pragma once

#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

#include "MainCamera.h"

//���G����
#define POWER_TIME 100

//�v���C���[�N���X
class CPlayer:public CObj3D
{
public:
	CPlayer(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CPlayer() {};

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
	void Input();	//����

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }
	D3DXVECTOR3 GetDir() { return m_vLastMove; }

	bool GetPower() { return m_bPower; }

	//�p���[���
	void SetPower() 
	{
		m_bPower = true; 
		m_PowerCount = POWER_TIME;
	}

private:
	D3DXVECTOR3 m_vMove;	//�ړ�
	D3DXVECTOR3 m_vLastMove;//�Ō�̈ړ�
	OBB_Data m_Obb;			//OBB���
	float m_fSpeed;			//�ړ��X�s�[�h
	int m_Count;			//�J�E���^
	int m_PowerCount;		//�p���[�J�E���^
	bool m_bPower;			//�p���[�t���O
};

