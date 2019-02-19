#pragma once
#include "CObj.h"



//マップ数値
#define NONE 0
#define WALL 1
#define ENEMY_RED 2
#define PLAYER 3
#define ENEMY_BLUE 7
#define ENEMY_ORANGE 9
#define ENEMY_PINK 8

#define FOOD 5
#define POWER_FOOD 6
class CMap :public CObj3D
{
public:
	CMap() {};
	~CMap() {};

	//初期化
	void Init();
	void Update();
	void Draw();

	//生成関数
	void Create();

	//ゲームオーバー
	//void SetGameOver() { m_bGameOver = true; }

	//カウント追加
	void CountAdd(int n) { m_feedCount += n; }

	//マップポインタ取得
	int** GetMapPointer() { return m_pMap; }

	
private:
	//餌のカウント
	int m_feedCount;

	//ゲームオーバーフラグ
	bool m_bGameOver;

	//マップポインタ
	int* m_pMap[MAP_X];

	//3Dマップ　（Y,X,Zの順）
	int m_map[MAP_Y][MAP_X][MAP_Z];

};

