#pragma once
#include "../../LIbrary/CObj.h"

//�Q�[���I�[�o�[�@�w�i�@�N���X
class CGameOverBackGround :public CObj2D
{
public:
	//�R���X�g���N�^
	CGameOverBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
private:
};