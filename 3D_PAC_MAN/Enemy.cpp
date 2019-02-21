#include "Enemy.h"
#include "Map.h"
#include "Task.h"
#include "Audio.h"

//�C�W�P��Ԃł̈ړ�
MY_Pos EnemyRun(MY_Pos next, int Start_x, int Start_y, int Goal_x, int Goal_y,CMap* pMap)
{
	//�v���C���[�ւ̍ŒZ���[�g
	next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, pMap->GetMapPointer());

	//�ړ����]
	next.x *= (-1);
	next.y *= (-1);

	//�ړ��ł��邩���ׂ�
	bool bMove = true;
	bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

	//�ړ��ł��Ȃ��Ƃ�
	if (bMove == false)
	{
		//x,y�̃x�N�g�������ւ���
		int tmp;
		tmp = next.x;
		next.x = next.y;
		next.y = tmp;

		//�ړ��ł��邩���ׂ�
		bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

		//����ł��ړ��ł��Ȃ��Ƃ�
		if (bMove == false)
		{
			//�ړ������𔽓]����
			next.x *= (-1);
			next.y *= (-1);
		}
	}

	//�ړ��ł��邩�m�F
	bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

	//�ړ��ł��Ȃ���
	if (bMove == false)
	{
		next.x = 0;
		next.y = 0;
	}

	return next;
}

void PlayerHit(OBB_Data obb,  bool run)
{
	//�C�W�P��ԂłȂ��Ƃ�
	if (run == false)
	{
		//�v���C���[�ɓ��������Ȃ�Q�[���I�[�o�[�V�[����
		vector<HIT_DATA> HitData;
		HitData = g_Obb.ObjNameHit(&obb, OBJ_PLAYER);

		if (HitData.size() > 0)
		{
			//�_���[�W��
			g_Audio.StartMusic(Audio_Damage);
			
			g_Scene.SetScene(SceneGameOver);
		}
	}
}
