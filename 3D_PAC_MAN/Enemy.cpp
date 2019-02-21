#include "Enemy.h"
#include "Map.h"
#include "Task.h"
#include "Audio.h"

//イジケ状態での移動
MY_Pos EnemyRun(MY_Pos next, int Start_x, int Start_y, int Goal_x, int Goal_y,CMap* pMap)
{
	//プレイヤーへの最短ルート
	next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, pMap->GetMapPointer());

	//移動反転
	next.x *= (-1);
	next.y *= (-1);

	//移動できるか調べる
	bool bMove = true;
	bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

	//移動できないとき
	if (bMove == false)
	{
		//x,yのベクトルを入れ替える
		int tmp;
		tmp = next.x;
		next.x = next.y;
		next.y = tmp;

		//移動できるか調べる
		bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

		//それでも移動できないとき
		if (bMove == false)
		{
			//移動方向を反転する
			next.x *= (-1);
			next.y *= (-1);
		}
	}

	//移動できるか確認
	bMove = g_Route.PosCheck(Start_x + next.x, Start_y + next.y);

	//移動できない時
	if (bMove == false)
	{
		next.x = 0;
		next.y = 0;
	}

	return next;
}

void PlayerHit(OBB_Data obb,  bool run)
{
	//イジケ状態でないとき
	if (run == false)
	{
		//プレイヤーに当たったならゲームオーバーシーンへ
		vector<HIT_DATA> HitData;
		HitData = g_Obb.ObjNameHit(&obb, OBJ_PLAYER);

		if (HitData.size() > 0)
		{
			//ダメージ音
			g_Audio.StartMusic(Audio_Damage);
			
			g_Scene.SetScene(SceneGameOver);
		}
	}
}
