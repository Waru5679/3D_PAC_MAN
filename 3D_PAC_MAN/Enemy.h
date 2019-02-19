#pragma once

#include "CObj.h"
#include "Player.h"
#include "Obb.h"
#include "Map.h"
#include "Route.h"

//�p���pEnemy�I�u�W�F�N�g
class CEnemy :public CObj3D
{
public:
	virtual void Move() = 0;	//�ړ��֐�

protected:
	OBB_Data m_Obb;		//OBB�f�[�^
	D3DXVECTOR3 m_vMove;//�ړ��x�N�g��
	CPlayer* m_pPlayer;	//�v���C���[�̃|�C���^
	CMap*  m_pMap;		//�}�b�v�|�C���^

	bool m_bRest; //�x�e�t���O
	int m_Count;//�J�E���^�[

	D3DXVECTOR2 m_vRestPoint[4];//�x�e�n�_
	int m_RestCount;//�x�e�J�E���g
	
	float m_fSpeed;//�ړ��X�s�[�h

	bool m_bRun;//�C�W�P�t���O

	MY_MESH m_RunMesh;
	D3DXVECTOR2 m_vStartPoint;	//�����ʒu
	bool m_bEat;//�H�ׂ�ꂽ
};

void PlayerHit(OBB_Data obb,bool run);

//�C�W�P��Ԃł̈ړ�
MY_Pos EnemyRun(MY_Pos Pos,int Start_x,int Start_y,int Goal_x,int Goal_y, CMap* pMap);

