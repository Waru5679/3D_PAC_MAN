#pragma once


#include "../../LIbrary/Main.h"
#include "../../LIbrary/Camera.h"

//�V�[�����C���@�J�����N���X
class CMainCamera :public Camera
{
public:
	void Init();	//������
	void Update();	//�X�V
private:
	
	D3DXVECTOR3 m_vPlayerPos;	//�v���C���[�̈ʒu
	D3DXVECTOR3 m_vPlayerDir;	//�v���C���[�̕���
	D3DXVECTOR3 m_vFront;		//�v���C���[�̐��ʕ���
	D3DXVECTOR3 m_vAngleSave;	//�p�x�ۑ��p
	D3DXVECTOR3 m_vDir;			//����

	float m_fCameraDis;		//�v���C���[�ƃJ�����̋���
	float m_fLookDis;		//�v���C���[�ƒ����_�̋���

	D3DXMATRIX m_matRot;	//��]�s��

	bool m_bLookingDown;	//�����낵�t���O
};