#pragma once

#include "../../LIbrary/CObj.h"
#include "../../LIbrary/Obb.h"

//�ǃN���X
class CWall :public CObj3D
{
public:
	//�R���X�g���N�^
	CWall(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale);

	void Init();	//������
	void Update();	//�X�V
	void Draw();	//�`��
private:	
	OBB_Data m_Obb;	//OBB�f�[�^
};