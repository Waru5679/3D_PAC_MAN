#include "../../LIbrary/Camera.h"
#include "../../LIbrary/Main.h"
#include "../../LIbrary/Math.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/DirectX.h"

#include "TitleBackGround.h"

//�R���X�g���N�^
CTitleBackGround::CTitleBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CTitleBackGround::Init()
{
	//�X�N���[�����W
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

//�X�V
void CTitleBackGround::Update()
{

}

//�`��
void CTitleBackGround::Draw()
{

	CFont::DrawStr(L"Enter�ŃX�^�[�g", 150, 430, 40);

	RECT_F Out;
	Out.m_left = m_ScreenPos.x;
	Out.m_top = m_ScreenPos.y;
	Out.m_right = Out.m_left + WINDOW_WIDTH;
	Out.m_bottom = Out.m_top + WINDOW_HEIGHT;

	//�w�i�`��
	g_Draw.Draw2D(0, &Out);
}