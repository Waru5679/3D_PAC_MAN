#include "../../LIbrary/Camera.h"
#include "../../LIbrary/Main.h"
#include "../../LIbrary/Math.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/DirectX.h"

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
	//スクリーン座標
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

//更新
void CTitleBackGround::Update()
{

}

//描画
void CTitleBackGround::Draw()
{

	CFont::DrawStr(L"Enterでスタート", 150, 430, 40);

	RECT_F Out;
	Out.m_left = m_ScreenPos.x;
	Out.m_top = m_ScreenPos.y;
	Out.m_right = Out.m_left + WINDOW_WIDTH;
	Out.m_bottom = Out.m_top + WINDOW_HEIGHT;

	//背景描画
	g_Draw.Draw2D(0, &Out);
}