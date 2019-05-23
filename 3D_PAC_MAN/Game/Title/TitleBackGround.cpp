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
	D3DXMatrixIdentity(&m_matWorld);
}

//�X�V
void CTitleBackGround::Update()
{

}

//�`��
void CTitleBackGround::Draw()
{
	float Color[4] = { 1.0f,1.0f,1.0f,1.0f };
	CFont::DrawStr(L"Enter�ŃX�^�[�g", 150.0f, 430.0f, 40.0f,0.0f);

	RECT_F Src,Out;

	RectSet(0.0f, 0.0f, 512.0f, 512.0f, &Src);

	RectSet(0.0f, 0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, &Out);

	//�w�i�`��
	g_Draw.Draw2D(0, &Src, &Out, Color, 0.0f);
}