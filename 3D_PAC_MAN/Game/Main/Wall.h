#pragma once

//���C�u�����t�@�C��
#include "../../Library/CObj.h"
#include "../../Library/Obb.h"

//�ǃN���X
class CWall :public CObj3DBase
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