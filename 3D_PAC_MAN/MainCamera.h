#pragma once

#include "Main.h"
#include "Player.h"
#include "Camera.h"

class CMainCamera :public Camera
{
public:
	void Init();	//������
	void Update();	//�X�V
	
	D3DXVECTOR3 GetFront(){ return m_vFront; }

private:
	
	D3DXVECTOR3 m_vPlayerPos;	//�v���C���[�̈ʒu
	D3DXVECTOR3 m_vPlayerDir;		//�v���C���[�̕���
	D3DXVECTOR3 m_vFront;		//�v���C���[�̐��ʕ���
	
	float m_fCameraDis;		//�v���C���[�ƃJ�����̋���
	float m_fLookDis;		//�v���C���[�ƒ����_�̋���

	D3DXVECTOR3 m_vAngleSave;//�p�x�ۑ��p

	D3DXVECTOR3 m_vDir;
	D3DXMATRIX m_matRot;

	bool m_bLookingDown;//�����낵�t���O
};