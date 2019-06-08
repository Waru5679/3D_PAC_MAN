#pragma once

//必要なライブラリファイルのロード
#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

//餌クラス
class CFood :public CObj3DBase
{
public:
	//コンストラクタ
	CFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	~CFood() {};

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
	OBB_Data m_Obb;	//OBBデータ
};

