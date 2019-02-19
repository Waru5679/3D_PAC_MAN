#pragma once 

#include "Enemy.h"
#include "EnemyRed.h"
//敵（青）
class CEnemyBlue :public CEnemy
{
public:
	CEnemyBlue(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CEnemyBlue() {};

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画

	void Move();	//移動
private:

	//最短ルート探索のスタート位置とゴール位置を変えて探索する
	MY_Pos Symmetrical(int Start_x, int Start_y, int Goal_x, int Goal_y, int** Array);// , int Size_x, int Size_y);

	//赤い敵のポインタ
	CEnemyRed* m_pRedEnemy;
	   
};
