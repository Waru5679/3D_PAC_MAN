#pragma once 

#include "Enemy.h"
#include "Route.h"

//�G�i�s���N�j
class CEnemyPink :public CEnemy
{
public:
	CEnemyPink(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CEnemyPink() {};

	//���W��n��
	MY_Pos GetPos();

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��

	void Move();	//�ړ�
private:


};
