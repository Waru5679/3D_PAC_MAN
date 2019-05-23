#include "../Clear/ClearBackGround.h"
#include "../Clear/ClearCamera.h"

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Math.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/DirectX.h"

//�R���X�g���N�^
CClearBackGround::CClearBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CClearBackGround::Init()
{
	//�X�N���[�����W
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

//�X�V
void CClearBackGround::Update()
{
}

//�`��
void CClearBackGround::Draw()
{
	CFont::DrawStr(L"CLEAR", 100, 100, 64);
	CFont::DrawStr(L"Enter�Ń^�C�g����", 100, 400, 40);
}