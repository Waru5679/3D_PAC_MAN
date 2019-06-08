#pragma once

#include "../../Library/CObj.h"
#include "../../Library/Obb.h"
#include "../../Library/Route.h"

#include "Player.h"
#include "Map.h"

//�p���pEnemy�I�u�W�F�N�g
class CEnemy :public CObj3DBase
{
public:
	virtual void Move() = 0;	//�ړ��֐�

protected:
	D3DXVECTOR3 m_vMove;		//�ړ��x�N�g��
	D3DXVECTOR2 m_vStartPoint;	//�����ʒu
	D3DXVECTOR2 m_vRestPoint[4];//�x�e�n�_

	int m_Count;	//�J�E���^�[
	int m_RestCount;//�x�e�J�E���g
	float m_fSpeed;	//�ړ��X�s�[�h

	bool m_bRun;	//�C�W�P�t���O
	bool m_bEat;	//�H�ׂ�ꂽ
	bool m_bRest;	//�x�e�t���O
	
	MY_MESH* m_pRunMesh;	//������Ƃ��̃��b�V���f�[�^
	CPlayer* m_pPlayer;	//�v���C���[�̃|�C���^
	CMap*  m_pMap;		//�}�b�v�|�C���^
	OBB_Data m_Obb;		//OBB�f�[�^

};

//�v���C���[�Ƃ̃q�b�g�m�F
void PlayerHit(OBB_Data obb,bool run);

//�C�W�P��Ԃł̈ړ�
MY_Pos EnemyRun(MY_Pos Pos,int Start_x,int Start_y,int Goal_x,int Goal_y, CMap* pMap);

