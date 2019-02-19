#include "TitleBackGround.h"
#include "Camera.h"
#include "Main.h"
#include "Math.h"
#include "Polygon.h"
#include "Task.h"
#include "Input.h"
#include "Font.h"
#include "DirectX.h"

CTitleBackGround::CTitleBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

void CTitleBackGround::Init()
{
	//ÉXÉNÉäÅ[Éìç¿ïW
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

void CTitleBackGround::Update()
{

}

void CTitleBackGround::Draw()
{

	CFont::DrawStr(L"Push_Enter", 150, 430, 40);

	RECT_F Out;
	Out.m_left = m_ScreenPos.x;
	Out.m_top = m_ScreenPos.y;
	Out.m_right = Out.m_left + WINDOW_WIDTH;
	Out.m_bottom = Out.m_top + WINDOW_HEIGHT;

	//îwåiï`âÊ
	g_Draw.Draw2D(0, &Out);
}