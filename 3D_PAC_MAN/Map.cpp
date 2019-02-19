#include <string.h>
#include "Map.h"
#include "Task.h"
#include "Player.h"
#include "Wall.h"
#include "Food.h"
#include "DirectX.h"
#include "EnemyRed.h"
#include "Route.h"
#include "EnemyBlue.h"
#include "EnemyOrange.h"
#include "EnemyPink.h"
#include "PowerFood.h"
#include "Font.h"
#include <stdlib.h>

#include "Input.h"

void CMap::Init()
{
	int map[MAP_Y][MAP_X][MAP_Z] =
	{
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		},
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,1},
			{1,6,1,1,5,1,1,1,5,1,5,1,1,1,5,1,1,6,1},
			{1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1},
			{1,5,1,1,5,1,5,1,1,1,1,1,5,1,5,1,1,5,1},
			{1,5,5,5,5,1,5,5,5,1,5,5,5,1,5,5,5,5,1},
			{1,1,1,1,5,1,1,1,5,1,5,1,1,1,5,1,1,1,1},
			{0,0,0,1,5,1,0,0,0,2,0,0,0,1,5,1,0,0,0},
			{1,1,1,1,5,1,0,1,1,0,1,1,0,1,5,1,1,1,1},
			{0,0,0,0,5,0,0,1,7,8,9,1,0,0,5,0,0,0,0},
			{1,1,1,1,5,1,0,1,1,1,1,1,0,1,5,1,1,1,1},
			{0,0,0,1,5,1,0,0,0,0,0,0,0,1,5,1,0,0,0},
			{1,1,1,1,5,1,0,1,1,1,1,1,0,1,5,1,1,1,1},
			{1,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,1},
			{1,5,1,1,5,1,1,1,5,1,5,1,1,1,5,1,1,5,1},
			{1,6,5,1,5,5,5,5,5,3,5,5,5,5,5,1,5,6,1},
			{1,1,5,1,5,1,5,1,1,1,1,1,5,1,5,1,5,1,1},
			{1,5,5,5,5,1,5,5,5,1,5,5,5,1,5,5,5,5,1},
			{1,5,1,1,1,1,1,1,5,1,5,1,1,1,1,1,1,5,1},
			{1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		}
	};
	memcpy(m_map, map, sizeof(int)*MAP_ARRAY_NUM);

	m_feedCount = 0;

	D3DXMatrixIdentity(&m_matWorld);

	//�}�b�v�|�C���^
	m_pMap[MAP_X];
	for (int i = 0; i < MAP_X; i++)
	{
		m_pMap[i] = new int[MAP_Z];

		memcpy(m_pMap[i], m_map[1][i], sizeof(int)*MAP_Z);
	}

	m_bGameOver = false;
}


void CMap::Update()
{
	//�Q�[���I�[�o�[�ɂȂ�����
	if (m_bGameOver == true)
	{
		//�Q�[���I�[�o�[�V�[����
		g_Scene.SetScene(SceneGameOver);
	}	
	
	//�a�����ׂĎ������
	if (m_feedCount <= 0)
	{
		//�N���A�V�[����
		g_Scene.SetScene(SceneClear);
	}
}

void CMap::Draw() 
{
	//�a�̃J�E���g�𕶎���ɕϊ�
	wchar_t str[10];
	 _itow_s(m_feedCount,str,10,10);

	//�J�E���g�`��
	CFont::DrawStr(L"�a�c��:", 0.0f, 0.0f, 40.0f);
	CFont::DrawStr(str, 160.0f, 0.0f, 40.0f);

}

//�����֐�
void CMap::Create()
{

	D3DXVECTOR3 Pos, Angle, Scale;

	for(int y=0;y<MAP_Y;y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			for (int z = 0; z < MAP_Z; z++)
			{
				Pos = D3DXVECTOR3(x * 4.0f, y * 4.0f, z * 4.0f);

				switch (m_map[y][x][z])
				{
					//��
					case WALL:
					{
						Angle= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(20.0f, 20.0f, 20.0f);
						
						CWall* wall = new CWall(Pos, Angle, Scale);
						g_Task.Insert3DObj(wall, OBJ_WALL);
						
						break;
					}
					//�v���C���[
					case PLAYER:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.5f,0.5f, 0.5f);
						
						CPlayer* obj = new CPlayer(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_PLAYER);

						//�����������ɂ���
						m_map[y][x][z] = NONE;

						break;
					}
					
					//�a
					case FOOD:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);

						CFood* obj = new CFood(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_FOOD);

						//�����������ɂ���
						m_map[y][x][z] = NONE;

						//�J�E���g�ǉ�
						m_feedCount ++;

						break;
					}
					//�p���[�a
					case POWER_FOOD:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.8f, 0.8f, 0.8f);

						CPowerFood* obj = new CPowerFood(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_POWER_FOOD);

						//�����������ɂ���
						m_map[y][x][z] = NONE;
						
						break;
					}
					//�G(��)
					case ENEMY_RED:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyRed* obj = new CEnemyRed(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_ENEMY_RED);
						
						//�����������ɂ���
						m_map[y][x][z] = NONE;

						break;
					}
					//�G(��)
					case ENEMY_BLUE:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyBlue* obj = new CEnemyBlue(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_ENEMY_BLUE);

						//�����������ɂ���
						m_map[y][x][z] = NONE;

						break;
					}
					//�G(�I�����W)
					case ENEMY_ORANGE:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyOrange* obj = new CEnemyOrange(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_ENEMY_ORANGE);

						//�����������ɂ���
						m_map[y][x][z] = NONE;

						break;
					}
					//�G(�s���N)
					case ENEMY_PINK:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyPink* obj = new CEnemyPink(Pos, Angle, Scale);
						g_Task.Insert3DObj(obj, OBJ_ENEMY_PINK);

						//�����������ɂ���
						m_map[y][x][z] = NONE;

						break;
					}
				}
			}
		}
	}
	
}
