#pragma once

//継承用　カメラクラス
class Camera
{
public:
	virtual void Init()=0;	//初期化
	virtual void Update()=0;	//更新

	D3DXMATRIX GetWorldMatrix() { return m_matWorld; }
	D3DXMATRIX GetViewMatrix() { return m_matView; }
	D3DXMATRIX GetProjMatrix() { return m_matProj; }
	D3DXVECTOR3 GetEye() { return m_vEye; }
	D3DXVECTOR3 GetAngle() { return m_vAngle; }
	D3DXVECTOR3 GetVertical() { return m_vVertical; }

protected:
	D3DXVECTOR3 m_vEye;	//視点
	D3DXVECTOR3 m_vLook;//注視点
	D3DXVECTOR3 m_vUp;	//カメラの向き
	
	D3DXVECTOR3 m_vAngle;	//角度
	D3DXVECTOR3 m_vVertical;//カメラにに垂直になる角度(２D描画用)

	D3DXMATRIX m_matView;	//ビューマトリックス
	D3DXMATRIX m_matProj;	//プロジェクションマトリックス
	D3DXMATRIX m_matWorld;	//ワールドマトリックス
};