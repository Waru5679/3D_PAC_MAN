#pragma once 

#include "Enemy.h"
#include "../../LIbrary/Route.h"

//�G�i�I�����W�j
class CEnemyOrange :public CEnemy
{
public:
	//�R���X�g���N�^
	CEnemyOrange(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	//���W��n��
	MY_Pos GetPos();
	
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
	void Move();	//�ړ�
private:

};
