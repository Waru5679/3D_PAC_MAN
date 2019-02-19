#include "ClearBackGround.h"
#include "Camera.h"
#include "Main.h"
#include "Math.h"
#include "Polygon.h"
#include "Task.h"
#include "Input.h"
#include "Font.h"
#include "DirectX.h"

CClearBackGround::CClearBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

void CClearBackGround::Init()
{
	//ÉXÉNÉäÅ[Éìç¿ïW
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

void CClearBackGround::Update()
{
	if (g_input.GetKeyPush(VK_RIGHT) == true)
	{
		m_ScreenPos.x += 1.0f;
	}
	if (g_input.GetKeyPush(VK_LEFT) == true)
	{
		m_ScreenPos.x -= 1.0f;
	}
	if (g_input.GetKeyPush(VK_UP) == true)
	{
		m_ScreenPos.y -= 1.0f;
	}
	if (g_input.GetKeyPush(VK_DOWN) == true)
	{
		m_ScreenPos.y += 1.0f;
	}

}

void CClearBackGround::Draw()
{
	RECT_F Out;

	Out.m_left = m_ScreenPos.x;
	Out.m_top = m_ScreenPos.y;
	Out.m_right = Out.m_left + WINDOW_WIDTH;
	Out.m_bottom = Out.m_top + WINDOW_HEIGHT;

	//îwåiï`âÊ
//	g_Draw.Draw2D(0, &Out);

	CFont::DrawStr(L"CLEAR", 100, 100, 64);

}