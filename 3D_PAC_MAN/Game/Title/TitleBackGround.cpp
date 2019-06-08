//ライブラリファイル
#include "../../Library/Camera.h"
#include "../../Library/Main.h"
#include "../../Library/Math.h"
#include "../../Library/Polygon.h"
#include "../../Library/Task.h"
#include "../../Library/Input.h"
#include "../../Library/Font.h"
#include "../../Library/DirectX.h"
#include "../../Library/Struct.h"
#include "../../Library/Struct.h"

//ゲームファイル
#include "TitleBackGround.h"

//コンストラクタ
CTitleBackGround::CTitleBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CTitleBackGround::Init()
{
	D3DXMatrixIdentity(&m_matWorld);
}

//更新
void CTitleBackGround::Update()
{

}

//描画
void CTitleBackGround::Draw()
{
	ColorData Color(1.0f,1.0f,1.0f,1.0f);

	g_Font.DrawStr(L"Enterでスタート", 150.0f, 430.0f, 40.0f,0.0f);

	//切り取り位置
	RECT_F Src(0.0f, 0.0f, 512.0f, 512.0f);

	//描画位置
	RECT_F Out(0.0f, 0.0f, WINDOW_WIDTH, WINDOW_HEIGHT);

	//背景描画
	g_Draw.DrawTexture(0, &Src, &Out, &Color ,0.0f);
	
}