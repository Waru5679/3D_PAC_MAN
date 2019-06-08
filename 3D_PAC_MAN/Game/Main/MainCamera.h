#pragma once

#include "../../Library/Main.h"
#include "../../LIbrary/Camera.h"

//シーンメイン　カメラクラス
class CMainCamera :public CameraBase
{
public:
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
	
	D3DXVECTOR3 m_vPlayerPos;	//プレイヤーの位置
	D3DXVECTOR3 m_vPlayerDir;	//プレイヤーの方向
	D3DXVECTOR3 m_vFront;		//プレイヤーの正面方向
	D3DXVECTOR3 m_vAngleSave;	//角度保存用
	D3DXVECTOR3 m_vDir;			//方向

	float m_fCameraDis;		//プレイヤーとカメラの距離
	float m_fLookDis;		//プレイヤーと注視点の距離

	D3DXMATRIX m_matRot;	//回転行列

	bool m_bLookingDown;	//見下ろしフラグ
};