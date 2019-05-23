#include "Polygon.h"
#include "DirectX.h"
#include "Task.h"
#include "Shader.h"
#include "Camera.h"
#include "Math.h"

CDraw g_Draw;

//������
void CDraw::Init()
{
	//���_���
	MY_VERTEX ver[]=
	{
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DXVECTOR2(0.0f,0.0f),
		D3DXVECTOR3(0.0f, -0.1f, 0.0f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DXVECTOR2(0.0f,1.0f),
		D3DXVECTOR3(0.1f, 0.0f, 0.0f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DXVECTOR2(1.0f,0.0f),
		D3DXVECTOR3(0.1f, -0.1f, 0.0f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DXVECTOR2(1.0f,1.0f)
	};
	m_Vertex = ver;

	//�o�[�e�b�N�X�o�b�t�@�쐬
	CreateBartex();
}

//�`�� ���p
void CDraw::Draw3D(int TexId, D3DXMATRIX matWorld) 
{	
	Draw3D(g_Task.GetTex(TexId), matWorld);
}

//�`��
void CDraw::Draw3D(ID3D10ShaderResourceView* pResView, D3DXMATRIX matWorld)
{
	//�V�F�[�_�[�̃Z�b�g
	g_Shader.SetShader(pResView,matWorld);

	//�|���S���̕`��
	DrawPolygon();
}

//2D�`�� ���p
void CDraw::Draw2D(int TexId, RECT_F* Out)
{
	Draw2D(g_Task.GetTex(TexId),Out);
}

//2D�`��
void CDraw::Draw2D(ID3D10ShaderResourceView* pResView, RECT_F*Out)
{
	
	//�X�N���[�����W����ʒu���擾
	CalcScreenToWorld(&m_vPos, Out->m_left, Out->m_top, 0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, &m_pCamera->GetViewMatrix(), &m_pCamera->GetProjMatrix());
	
	//�X�P�[��
	m_vScale.x = (Out->m_right  - Out->m_left) / 240.0f;
	m_vScale.y = (Out->m_bottom - Out->m_top)/ 240.0f;
	m_vScale.z = 0.0f;
	 
	//�J�����̌������擾
	m_vAngle = m_pCamera->GetVertical();

	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
	   
	//�V�F�[�_�[�̃Z�b�g
	g_Shader.SetShader(pResView,m_matWorld);

	//�|���S���̕`��
	DrawPolygon();
}

//�o�[�e�b�N�X�o�b�t�@�[�쐬
HRESULT CDraw::CreateBartex()
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(MY_VERTEX) * 4;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D10_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = m_Vertex;
	if (FAILED(dx.m_pDevice->CreateBuffer(&bd, &InitData, &m_pBuffer)))
		return FALSE;

	return S_OK;
}

//�|���S���̕`��
void CDraw::DrawPolygon()
{
	//�o�[�e�b�N�X�o�b�t�@�[���Z�b�g
	UINT stride = sizeof(MY_VERTEX);
	UINT offset = 0;
	dx.m_pDevice->IASetVertexBuffers(0, 1, &m_pBuffer, &stride, &offset);

	//�v���~�e�B�u�E�g�|���W�[���Z�b�g
	//�l�p�`
	dx.m_pDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//�v���~�e�B�u�������_�����O
	D3D10_TECHNIQUE_DESC dc;
	g_Shader.m_pTechnique->GetDesc(&dc);
	for (UINT p = 0; p < dc.Passes; ++p)
	{
		g_Shader.m_pTechnique->GetPassByIndex(p)->Apply(0);
		dx.m_pDevice->Draw(4, 0);
	}
}

//�e�N�X�`���ǂݍ���
void CDraw::LoadTexture(int Id,const char* Name)
{
	ID3D10ShaderResourceView* pTex;
	//�e�N�X�`���[���쐬
	D3DX10CreateShaderResourceViewFromFileA(dx.m_pDevice, Name, NULL, NULL, &pTex, NULL);

	//�o�^
	g_Task.Insert(pTex, Id);
}

//���
void CDraw::Release()
{
	m_pBuffer->Release();
}