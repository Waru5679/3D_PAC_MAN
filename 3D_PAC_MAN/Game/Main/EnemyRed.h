#pragma once 

#include "../../LIbrary/Route.h"

#include "Enemy.h"

//�G�i�ԁj
class CEnemyRed:public CEnemy
{
public:
	//�R���X�g���N�^
	CEnemyRed(D3DXVECTOR3 Pos,D3DXVECTOR3 Angle,D3DXVECTOR3 Scale);

	//���W��n��
	MY_Pos GetPos();
	
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
	void Move();	//�ړ�

private:
};
