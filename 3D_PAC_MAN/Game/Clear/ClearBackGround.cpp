#include "../Clear/ClearBackGround.h"
#include "../Clear/ClearCamera.h"

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Math.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/DirectX.h"

//コンストラクタ
CClearBackGround::CClearBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CClearBackGround::Init()
{
	//スクリーン座標
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

//更新
void CClearBackGround::Update()
{
}

//描画
void CClearBackGround::Draw()
{
	CFont::DrawStr(L"CLEAR", 100, 100, 64);
	CFont::DrawStr(L"Enterでタイトルへ", 100, 400, 40);
}