#include "../../LIbrary/Camera.h"
#include "../../LIbrary/Main.h"
#include "../../LIbrary/Math.h"
#include "../../LIbrary/Polygon.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Input.h"
#include "../../LIbrary/Font.h"
#include "../../LIbrary/DirectX.h"

#include "GameOverBackGround.h"

//�R���X�g���N�^
CGameOverBackGround::CGameOverBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//������
void CGameOverBackGround::Init()
{
	//�X�N���[�����W
	m_ScreenPos = D3DXVECTOR2(0.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
}

//�X�V
void CGameOverBackGround::Update()
{
	
}

//�`��
void CGameOverBackGround::Draw()
{
	CFont::DrawStr(L"Enter�Ń^�C�g����", 100, 300, 40);
	CFont::DrawStr(L"GAME_OVER", 25, 100, 64);
}