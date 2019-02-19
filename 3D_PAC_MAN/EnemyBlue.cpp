#include "EnemyBlue.h"
#include "Math.h"
#include "Task.h"
#include "Obb.h"
#include "Route.h"
#include "Player.h"

//コンストラクタ
CEnemyBlue::CEnemyBlue(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CEnemyBlue::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_Mesh = g_Task.GetMesh(Model_Enemy_Blue);

	//最小値・最大値
	m_vMin = m_Mesh.vMin;
	m_vMax = m_Mesh.vMax;

	//イジケモデル
	m_RunMesh = g_Task.GetMesh(Model_Enemy_Run);

	//移動初期化
	m_vMove = D3DXVECTOR3(0.0f, 0.0, 0.0f);

	//プレイヤーのアドレス
	m_pPlayer = nullptr;

	//マップのアドレス
	m_pMap = dynamic_cast<CMap*> (g_Task.Get3DObj(OBJ_MAP));

	//赤い敵のアドレス
	m_pRedEnemy = nullptr;

	//休憩状態
	m_bRest = true;
	
	//イジケ状態
	m_bRun = false;

	//カウンタ
	m_Count = 0;

	//移動スピード
	m_fSpeed=0.6f;

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);

	//休憩地点
	m_vRestPoint[0] = D3DXVECTOR2(17.0f, 13.0f);
	m_vRestPoint[1] = D3DXVECTOR2(17.0f, 19.0f);
	m_vRestPoint[2] = D3DXVECTOR2(10.0f, 19.0f);
	m_vRestPoint[3] = D3DXVECTOR2(12.0f, 15.0f);

	m_RestCount = 0;

	//復活位置
	m_vStartPoint=D3DXVECTOR2(9.0f,9.0f);

	//食べられた
	m_bEat = false;

}
//更新
void CEnemyBlue::Update()
{
	//カウンタ更新
	m_Count++;

	//300カウントで休憩と追っかけの切り替え
	if (m_Count > 300)
	{
		m_Count = 0;
		m_bRest = !(m_bRest);
	}

	//プレイヤーのアドレス取得
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.Get3DObj(OBJ_PLAYER));
	}

	//プレイヤーのパワー状態を調べる
	m_bRun = m_pPlayer->GetPower();

	//赤い敵のアドレス取得
	if (m_pRedEnemy == nullptr)
	{
		m_pRedEnemy = dynamic_cast<CEnemyRed*> (g_Task.Get3DObj(OBJ_ENEMY_RED));
	}

	//プレイヤーに触れたとき
	vector<HIT_DATA> HitData;
	HitData = g_Obb.ObjNameHit(&m_Obb, OBJ_PLAYER);

	if (HitData.size() > 0)
	{
		//食べられた
		m_bEat = true;
	}

	//移動
	Move();

	//プレイヤーとの当たり判定
	PlayerHit(m_Obb, m_bRun);

	//当たり判定更新
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//移動関数
void CEnemyBlue::Move()
{
	//中心にいるときだけ移動方向更新
	if ((int)m_vPos.x % 4 == 0 && (int)m_vPos.z % 4 == 0)
	{
		//移動初期化
		m_vMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		MY_Pos next;

		//探索用
		int Start_x, Start_y, Goal_x, Goal_y;

		//位置を要素数にする
		Start_x = (int)m_vPos.z / 4;
		Start_y = (int)m_vPos.x / 4;

		//スタート地点に戻った時
		if (Start_x == m_vStartPoint.x && Start_y == m_vStartPoint.y)
		{
			m_bEat = false;
		}

		//食べられた後
		if (m_bEat == true)
		{
			Goal_x = (int)m_vStartPoint.x;
			Goal_y = (int)m_vStartPoint.y;
			
			//スタート地点を目指す
			next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
		}
		else
		{
			//休憩
			if (m_bRest == true)
			{
				//休憩地点につくと次の地点へ
				if (m_vRestPoint[m_RestCount].x == Start_x && m_vRestPoint[m_RestCount].y == Start_y)
				{
					if (m_RestCount == 3)
						m_RestCount = 0;
					else
						m_RestCount++;
				}

				Goal_x = (int)m_vRestPoint[m_RestCount].x;
				Goal_y = (int)m_vRestPoint[m_RestCount].y;

				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());

			}
			//追いかけ
			else
			{
				//プレイヤーの位置取得
				D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

				//敵の位置を要素数にする
				Goal_x = (int)PlayerPos.z / 4;
				Goal_y = (int)PlayerPos.x / 4;
				
				//点対象位置を目指す
				next = Symmetrical(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
			}

			//パワー状態
			if (m_bRun == true)
			{
				//プレイヤーから逃げる
				next = EnemyRun(next, Start_x, Start_y, Goal_x, Goal_y, m_pMap);
			}
		}

		//移動方向の更新
		m_vMove.x = (float)next.y;
		m_vMove.z = (float)next.x;
	}
	//移動
	m_vPos += m_vMove * m_fSpeed;;
}

//最短ルート探索のスタート位置とゴール位置を変えて探索する
MY_Pos CEnemyBlue::Symmetrical(int Start_x, int Start_y, int Goal_x, int Goal_y,int** Array)//, int Size_x ,int Size_y)
{
	MY_Pos out;
	
	//動きの中心になる場所
	MY_Pos center;

	//中心点からの距離
	MY_Pos Dis;

	//赤い敵の位置を持ってくる
	MY_Pos RedEnemyPos;
	RedEnemyPos = m_pRedEnemy->GetPos();
	
	//プレイヤーと敵の中間との距離を求める
	Dis.x = abs(Goal_x - RedEnemyPos.x) / 2;
	Dis.y = abs(Goal_y - RedEnemyPos.y) / 2;

	//x,yそれぞれの座標の小さいほうを元に中心点を求める。
	if (Goal_x < RedEnemyPos.x)
		center.x = Dis.x + Goal_x;
	else
		center.x = Dis.x + RedEnemyPos.x;

	if (Goal_y < RedEnemyPos.y)
		center.y = Dis.y + Goal_y;
	else
		center.y = Dis.y + RedEnemyPos.y;

	//プレイヤーを中心点と点対称に移動させた時の中心点との距離
	Dis.x = (Goal_x - center.x)*(-1);
	Dis.y = (Goal_y - center.y)*(-1);

	Goal_x = center.x + Dis.x;
	Goal_y = center.y + Dis.y;

	//一番近いマップの位置にする
	g_Route.NearInMap(Goal_x,Goal_y);
	
	//移動ルートを求める
	out = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, Array);

	return out;
}

//描画
void CEnemyBlue::Draw()
{
	//イジケ状態
	if (m_bRun == true)
	{
		g_Loader.Draw(m_matWorld, &m_RunMesh);
	}
	else
	{
		g_Loader.Draw(m_matWorld, &m_Mesh);
	}
}
