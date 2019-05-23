#pragma once
#include "../../LIbrary/CObj.h"

//ゲームオーバー　背景　クラス
class CGameOverBackGround :public CObj2D
{
public:
	//コンストラクタ
	CGameOverBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
};