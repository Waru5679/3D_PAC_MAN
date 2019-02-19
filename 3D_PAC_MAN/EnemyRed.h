#pragma once 

#include "Enemy.h"
#include "Route.h"

//敵（赤）
class CEnemyRed:public CEnemy
{
public:
	CEnemyRed(D3DXVECTOR3 Pos,D3DXVECTOR3 Angle,D3DXVECTOR3 Scale);
	~CEnemyRed(){};

	//座標を渡す
	MY_Pos GetPos();
	
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画

	void Move();	//移動

private:

};
