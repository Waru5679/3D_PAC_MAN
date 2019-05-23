#pragma once
#include <d3dx10.h>
#include <D3D10.h>
#include <vector>
#include <windef.h>

#include "CObj.h"
#include "Scene.h"
#include "Camera.h"
using namespace std;

//テクスチャ管理用
struct MY_TEXTURE
{
	//テクスチャ
	ID3D10ShaderResourceView* m_pTex;
	int m_Width;	//幅
	int m_Height;	//高さ
	int m_Id;		//管理用ID

};

//シーン管理用
struct MY_SCENE
{
	CScene* m_pScene;	//シーン
	int m_Id;			//管理用ID
};

//メッシュ管理用
struct Mesh_Data
{
	MY_MESH m_Mesh;	//メッシュデータ
	int m_Id;		//管理用ID

};

//管理用　クラス
class CTask
{
public:
	void Update();	//更新
	void Draw();	//描画
	void Release();	//解放
		
	//登録
	void InsertObj(CObj* pObj, int Id);
	void InsertScene(CScene* pScene, int Id);
	void Insert(ID3D10ShaderResourceView* pTex, int Id, int Width, int Height);
	void Insert(MY_MESH Mesh, int Id);

	//取得	
	CObj* GetObj(int Id);
	CScene* GetScene(int Id);
	MY_TEXTURE* GetTex(int Id);
	MY_MESH GetMesh(int Id);
	
	//OBJリストデータ削除
	void ObjDelete();
private:
	vector<MY_SCENE> m_Scene;	//シーン
	vector<CObj*> m_Obj;		//オブジェクト
	vector<MY_TEXTURE> m_Tex;	//テクスチャ
	vector<Mesh_Data> m_Mesh;		//メッシュ
};

extern CTask g_Task;
