#pragma once

#include "../../LIbrary/CObj.h"

//�}�b�v���l
#define NONE 0
#define WALL 1
#define ENEMY_RED 2
#define PLAYER 3
#define FOOD 5
#define POWER_FOOD 6
#define ENEMY_BLUE 7
#define ENEMY_ORANGE 9
#define ENEMY_PINK 8

//�}�b�v�N���X
class CMap :public CObj3D
{
public:
	//������
	void Init();
	void Update();
	void Draw();

	//�����֐�
	void Create();

	//�J�E���g�ǉ�
	void CountAdd(int n) { m_feedCount += n; }

	//�}�b�v�|�C���^�擾
	int** GetMapPointer() { return m_pMap; }
		
private:
	//�a�̃J�E���g
	int m_feedCount;

	//�Q�[���I�[�o�[�t���O
	bool m_bGameOver;

	//�}�b�v�|�C���^
	int* m_pMap[MAP_X];

	//3D�}�b�v�@�iY,X,Z�̏��j
	int m_map[MAP_Y][MAP_X][MAP_Z];
};
