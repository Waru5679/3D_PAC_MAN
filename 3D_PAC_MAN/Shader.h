#pragma once
#include <Windows.h>
#include <stdio.h>
#include <d3dx10.h>

//�K�v�ȃ��C�u�����t�@�C���̃��[�h
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")

#include "ObjLoader.h"
#include "Camera.h"

class CShader
{
public:
	HRESULT Init();

	void SetCamera(Camera* pCamera) { m_pCamera = pCamera; }

	//�V�F�[�_�[�̃Z�b�g
	void SetShader(D3DXMATRIX matWorld, MY_MATERIAL& material);
private:
	//�A�v�������V�F�[�_�[�˂���
	ID3D10EffectMatrixVariable* m_pShaderWorld;//���[���h�ϊ��s��
	ID3D10EffectMatrixVariable* m_pShaderWorldViewProjection;//���[���h����ˉe�܂ł̕ϊ��s��
	ID3D10EffectShaderResourceVariable* m_pShaderTexture;//�e�N�X�`���[
	ID3D10EffectVectorVariable* m_pShaderAmbient;//�A���r�G���g��
	ID3D10EffectVectorVariable* m_pShaderDiffuse;//�g�U���ːF
	ID3D10EffectVectorVariable* m_pShaderSpecular;//����
	ID3D10EffectVectorVariable* m_pShaderLightDir;//���C�g����
	ID3D10EffectVectorVariable* m_pShaderEyePos;//�J�����ʒu

	Camera* m_pCamera;

};

extern CShader g_Shader;