#include <string.h>
#include <stdlib.h>

#include "../../LIbrary/DirectX.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Route.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/Input.h"

#include "Map.h"
#include "Player.h"
#include "Wall.h"
#include "Food.h"
#include "EnemyBlue.h"
#include "EnemyOrange.h"
#include "EnemyPink.h"
#include "PowerFood.h"
#include "EnemyRed.h"

//初期化
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

	//マップポインタ
	m_pMap[MAP_X];
	for (int i = 0; i < MAP_X; i++)
	{
		m_pMap[i] = new int[MAP_Z];

		memcpy(m_pMap[i], m_map[1][i], sizeof(int)*MAP_Z);
	}

	m_bGameOver = false;
}

//更新
void CMap::Update()
{
	//ゲームオーバーになった時
	if (m_bGameOver == true)
	{
		//ゲームオーバーシーンへ
		g_Scene.SetScene(SceneGameOver);
	}	
	
	//餌をすべて取った時
	if (m_feedCount <= 0)
	{
		//クリアシーンへ
		g_Scene.SetScene(SceneClear);
	}
}

//描画
void CMap::Draw() 
{
	//餌のカウントを文字列に変換
	wchar_t str[10];
	 _itow_s(m_feedCount,str,10,10);

	//カウント描画
	CFont::DrawStr(L"餌残り:", 0.0f, 0.0f, 40.0f,0.0f);
	CFont::DrawStr(str, 160.0f, 0.0f, 40.0f,0.0f);

	CFont::DrawStr(L"Spaceで視点切り替え", 0.0f, WINDOW_HEIGHT-40.0f, 40.0f, 0.0f);
}

//生成関数
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
					//壁
					case WALL:
					{
						Angle= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(20.0f, 20.0f, 20.0f);
						
						CWall* wall = new CWall(Pos, Angle, Scale);
						g_Task.InsertObj(wall, OBJ_WALL);
						
						break;
					}
					//プレイヤー
					case PLAYER:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.5f,0.5f, 0.5f);
						
						CPlayer* obj = new CPlayer(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_PLAYER);

						//生成したら空にする
						m_map[y][x][z] = NONE;

						break;
					}
					
					//餌
					case FOOD:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);

						CFood* obj = new CFood(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_FOOD);

						//生成したら空にする
						m_map[y][x][z] = NONE;

						//カウント追加
						m_feedCount ++;

						break;
					}
					//パワー餌
					case POWER_FOOD:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(0.8f, 0.8f, 0.8f);

						CPowerFood* obj = new CPowerFood(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_POWER_FOOD);

						//生成したら空にする
						m_map[y][x][z] = NONE;
						
						break;
					}
					//敵(赤)
					case ENEMY_RED:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyRed* obj = new CEnemyRed(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_ENEMY_RED);
						
						//生成したら空にする
						m_map[y][x][z] = NONE;

						break;
					}
					//敵(青)
					case ENEMY_BLUE:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyBlue* obj = new CEnemyBlue(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_ENEMY_BLUE);

						//生成したら空にする
						m_map[y][x][z] = NONE;

						break;
					}
					//敵(オレンジ)
					case ENEMY_ORANGE:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyOrange* obj = new CEnemyOrange(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_ENEMY_ORANGE);

						//生成したら空にする
						m_map[y][x][z] = NONE;

						break;
					}
					//敵(ピンク)
					case ENEMY_PINK:
					{
						Angle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

						CEnemyPink* obj = new CEnemyPink(Pos, Angle, Scale);
						g_Task.InsertObj(obj, OBJ_ENEMY_PINK);

						//生成したら空にする
						m_map[y][x][z] = NONE;

						break;
					}
				}
			}
		}
	}
	
}
