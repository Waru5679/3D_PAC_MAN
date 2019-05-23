#include "../../LIbrary/Input.h"
#include "../../LIbrary/DirectX.h"
#include "../../LIbrary/CObj.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Math.h"

#include "GameOverCamera.h"

//������
void CGameOverCamera::Init()
{
	//�����J�����̈ʒu
	m_vEye = D3DXVECTOR3(0.0f, 5.0f, -2.0f);
	m_vLook = D3DXVECTOR3(0.0f, 10.0f, 10.0f);
	m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
}

//�X�V�֐�
void CGameOverCamera::Update()
{
	CreateVSMatrix(&m_vEye, &m_vLook, &m_vUp, &m_matView, &m_matProj, WINDOW_WIDTH, WINDOW_HEIGHT);
}

//�`��
void CGameOverCamera::Draw()
{

}
