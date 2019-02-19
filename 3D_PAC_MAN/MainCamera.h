#pragma once

#include "Main.h"
#include "Player.h"
#include "Camera.h"

class CMainCamera :public Camera
{
public:
	void Init();	//初期化
	void Update();	//更新
	
	D3DXVECTOR3 GetFront(){ return m_vFront; }

private:
	
	D3DXVECTOR3 m_vPlayerPos;	//プレイヤーの位置
	D3DXVECTOR3 m_vPlayerDir;		//プレイヤーの方向
	D3DXVECTOR3 m_vFront;		//プレイヤーの正面方向
	
	float m_fCameraDis;		//プレイヤーとカメラの距離
	float m_fLookDis;		//プレイヤーと注視点の距離

	D3DXVECTOR3 m_vAngleSave;//角度保存用

	D3DXVECTOR3 m_vDir;
	D3DXMATRIX m_matRot;

	bool m_bLookingDown;//見下ろしフラグ
};