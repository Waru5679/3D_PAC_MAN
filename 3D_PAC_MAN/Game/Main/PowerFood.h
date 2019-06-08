#pragma once

//ライブラリファイル
#include "../../Library/Main.h"
#include "../../Library/CObj.h" 
#include "../../Library/Obb.h"

//ゲームファイル
#include "Player.h"

//パワー餌クラス
class CPowerFood :public CObj3DBase
{
public:
	//コンストラクタ
	CPowerFood(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }

	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
	OBB_Data m_Obb;		//OBBデータ
	CPlayer* m_pPlayer;	//プレイヤーのポインタ
};

