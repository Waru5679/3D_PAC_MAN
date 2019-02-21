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
	//スクリーン座標
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

void CClearBackGround::Update()
{
}

void CClearBackGround::Draw()
{

	CFont::DrawStr(L"CLEAR", 100, 100, 64);
	CFont::DrawStr(L"Enterでタイトルへ", 100, 400, 40);

}