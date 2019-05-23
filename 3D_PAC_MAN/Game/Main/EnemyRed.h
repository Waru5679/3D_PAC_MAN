#pragma once 

#include "../../LIbrary/Route.h"

#include "Enemy.h"

//敵（赤）
class CEnemyRed:public CEnemy
{
public:
	//コンストラクタ
	CEnemyRed(D3DXVECTOR3 Pos,D3DXVECTOR3 Angle,D3DXVECTOR3 Scale);

	//座標を渡す
	MY_Pos GetPos();
	
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
	void Move();	//移動

private:
};
