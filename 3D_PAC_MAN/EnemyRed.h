#pragma once 

#include "Enemy.h"
#include "Route.h"

//�G�i�ԁj
class CEnemyRed:public CEnemy
{
public:
	CEnemyRed(D3DXVECTOR3 Pos,D3DXVECTOR3 Angle,D3DXVECTOR3 Scale);
	~CEnemyRed(){};

	//���W��n��
	MY_Pos GetPos();
	
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��

	void Move();	//�ړ�

private:

};
