#pragma once
#include "../../LIbrary/CObj.h"

//�^�C�g���w�i�@�N���X
class CTitleBackGround :public CObj2D
{
public:
	//�R���X�g���N�^
	CTitleBackGround(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);
	
	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
private:
};