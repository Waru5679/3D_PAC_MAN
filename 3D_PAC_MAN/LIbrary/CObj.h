#pragma once
#include "Main.h"
#include "ObjLoader.h"

//オブジェクト　継承用クラス(ゲームオブジェクト全てに継承させる)
class CObjBase
{
public:
	virtual void Init() = 0;	//初期化
	virtual void Update() = 0;	//更新
	virtual void Draw() = 0;	//描画

	void SetId(int Id)				{ m_Id = Id; }
	void SetDelete(bool isDelete)	{ m_bDelete = isDelete; }
	int	 GetId()					{ return m_Id; }
	bool GetDelete()				{ return m_bDelete; }
protected:
	int m_Id;		//オブジェクトID
	bool m_bDelete;	//削除フラグ
};

//2Dオブジェクト　継承用クラス
class CObj2DBase :public CObjBase
{
protected:
	D3DXVECTOR2 m_ScreenPos;	//描画位置(左上)
	D3DXVECTOR2 m_Move;			//移動ベクトル
};

//3Dモデルを使用するもの　継承用クラス
class CObj3DBase :public CObjBase
{
public :
	D3DXVECTOR3 GetPos()	{ return m_vPos;	}
	D3DXVECTOR3 GetAngle()	{ return m_vAngle;	}
	D3DXVECTOR3 GetScale()	{ return m_vScale;	}
	D3DXMATRIX  GetWorld()	{ return m_matWorld;}

	MY_MESH* GetMesh() { return m_pMesh; }
protected:

	//ベクトル
	D3DXVECTOR3 m_vPos;		//位置
	D3DXVECTOR3 m_vAngle;	//回転
	D3DXVECTOR3 m_vScale;	//大きさ
	D3DXVECTOR3 m_vMin;		//最小点
	D3DXVECTOR3 m_vMax;		//最大点

	//行列
	D3DXMATRIX m_matWorld;	//ワールド
	D3DXMATRIX m_matTrans;	//移動
	D3DXMATRIX m_matRot;	//回転
	D3DXMATRIX m_matScale;	//拡大・縮小
	
	MY_MESH* m_pMesh;	//モデルのポインタ
};

