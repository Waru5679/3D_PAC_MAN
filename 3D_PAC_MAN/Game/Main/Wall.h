#pragma once

//ライブラリファイル
#include "../../Library/CObj.h"
#include "../../Library/Obb.h"

//壁クラス
class CWall :public CObj3DBase
{
public:
	//コンストラクタ
	CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:	
	OBB_Data m_Obb;	//OBBデータ
};