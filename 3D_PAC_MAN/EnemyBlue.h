#pragma once 

#include "Enemy.h"
#include "EnemyRed.h"
//�G�i�j
class CEnemyBlue :public CEnemy
{
public:
	CEnemyBlue(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CEnemyBlue() {};

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��

	void Move();	//�ړ�
private:

	//�ŒZ���[�g�T���̃X�^�[�g�ʒu�ƃS�[���ʒu��ς��ĒT������
	MY_Pos Symmetrical(int Start_x, int Start_y, int Goal_x, int Goal_y, int** Array);// , int Size_x, int Size_y);

	//�Ԃ��G�̃|�C���^
	CEnemyRed* m_pRedEnemy;
	   
};
