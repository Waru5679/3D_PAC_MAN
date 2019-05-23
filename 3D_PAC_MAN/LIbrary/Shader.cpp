#pragma once
#include "Main.h"
#include "Shader.h"
#include "Camera.h"

CShader g_Shader;

//������
HRESULT CShader::Init(ID3D10Device* pDevice)
{
	//�G�t�F�N�g���쐬
	D3DX10CreateEffectFromFile(L"Library/Geometry_Material_Texture.fx", NULL, NULL, "fx_4_0",
		D3D10_SHADER_ENABLE_STRICTNESS | D3D10_SHADER_DEBUG, 0,
		pDevice, NULL, NULL, &m_pEffect, NULL, NULL);

	//�e�N�j�b�N�𓾂�
	m_pTechnique = m_pEffect->GetTechniqueByName("Render");

	//���_�C���v�b�g���C�A�E�g���`	
	D3D10_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	};
	UINT numElements = sizeof(layout) / sizeof(layout[0]);

	//���_�C���v�b�g���C�A�E�g���쐬
	D3D10_PASS_DESC PassDesc;
	m_pTechnique->GetPassByIndex(0)->GetDesc(&PassDesc);
	if (FAILED(pDevice->CreateInputLayout(layout, numElements, PassDesc.pIAInputSignature,
		PassDesc.IAInputSignatureSize, &m_pVertexLayout)))
	{
		return E_FAIL;
	}

	//���_�C���v�b�g���C�A�E�g���Z�b�g
	pDevice->IASetInputLayout(m_pVertexLayout);

	return S_OK;
}

//�V�F�[�_�[�Z�b�g
void CShader::SetShader(ID3D10ShaderResourceView* pTexture, D3DXMATRIX matWorld)
{	
	//���[���h���r���[*�v���W�F�N�V����
	m_pShaderWorldViewProjection = m_pEffect->GetVariableByName("g_mWVP")->AsMatrix();
	D3DXMATRIX objWVP = matWorld *m_pCamera->GetViewMatrix() *m_pCamera->GetProjMatrix();
	m_pShaderWorldViewProjection->SetMatrix((float*)&(objWVP));

	//�e�N�X�`����񂪂����
	if (pTexture != NULL)
	{
		m_pShaderTexture = m_pEffect->GetVariableByName("g_texDecal")->AsShaderResource();
		m_pShaderTexture->SetResource(pTexture);
	}
}


//���
void CShader::Release()
{
	m_pVertexLayout->Release();
	m_pEffect->Release();
}