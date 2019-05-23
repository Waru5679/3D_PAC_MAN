#pragma once 

#include "Enemy.h"
#include "../../LIbrary/Route.h"

//敵（オレンジ）
class CEnemyOrange :public CEnemy
{
public:
	//コンストラクタ
	CEnemyOrange(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	//座標を渡す
	MY_Pos GetPos();
	
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
	void Move();	//移動
private:

};
