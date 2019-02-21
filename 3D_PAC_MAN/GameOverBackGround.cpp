#include "GameOverBackGround.h"
#include "Camera.h"
#include "Main.h"
#include "Math.h"
#include "Polygon.h"
#include "Task.h"
#include "Input.h"
#include "Font.h"
#include "DirectX.h"

CGameOverBackGround::CGameOverBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

void CGameOverBackGround::Init()
{
	//スクリーン座標
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

void CGameOverBackGround::Update()
{
	
}

void CGameOverBackGround::Draw()
{
	CFont::DrawStr(L"Enterでタイトルへ", 100, 300, 40);
	CFont::DrawStr(L"GAME_OVER", 25, 100, 64);
}