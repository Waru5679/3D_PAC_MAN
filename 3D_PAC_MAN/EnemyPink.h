#pragma once 

#include "Enemy.h"
#include "Route.h"

//敵（ピンク）
class CEnemyPink :public CEnemy
{
public:
	CEnemyPink(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CEnemyPink() {};

	//座標を渡す
	MY_Pos GetPos();

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画

	void Move();	//移動
private:


};
