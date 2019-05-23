#include "../../LIbrary/Math.h"
#include "../../LIbrary/Task.h"
#include "../../LIbrary/Obb.h"
#include "../../LIbrary/Route.h"

#include "Player.h"
#include "EnemyRed.h"

//コンストラクタ
CEnemyRed::CEnemyRed(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle, D3DXVECTOR3 Scale)
{
	m_vPos = Pos;
	m_vAngle = Angle;
	m_vScale = Scale;
}

//初期化
void CEnemyRed::Init()
{
	//行列初期化
	D3DXMatrixIdentity(&m_matRot);
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matWorld);

	//モデル
	m_Mesh = g_Task.GetMesh(Model_Enemy_Red);

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
	m_pMap = dynamic_cast<CMap*> (g_Task.GetObj(OBJ_MAP));

	//イジケ状態
	m_bRun = false;

	//カウンタ
	m_Count = 0;

	//移動スピード
	m_fSpeed = 0.6f;

	//休憩状態
	m_bRest = true;

	//休憩地点
	m_vRestPoint[0] = D3DXVECTOR2(10.0f,2.0f);
	m_vRestPoint[1] = D3DXVECTOR2(16.0f,1.0f);
	m_vRestPoint[2] = D3DXVECTOR2(17.0f,5.0f);
	m_vRestPoint[3] = D3DXVECTOR2(14.0f,5.0f);

	m_RestCount = 0;

	//当たり判定セット
	m_Obb = g_Obb.SetOBB(m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax, m_id, this);
	g_Obb.Insert(&m_Obb);

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}


//座標を渡す
MY_Pos CEnemyRed::GetPos()
{
	MY_Pos out;
	out.x = (int)m_vPos.z / 4;
	out.y = (int)m_vPos.x / 4;
	return out;
}

//更新
void CEnemyRed::Update()
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
		m_pPlayer = dynamic_cast<CPlayer*> (g_Task.GetObj(OBJ_PLAYER));
	}

	//プレイヤーのパワー状態を調べる
	m_bRun = m_pPlayer->GetPower();

	//移動
	Move();	

	//プレイヤーとの当たり判定
	PlayerHit(m_Obb,m_bRun);
	
	//当たり判定更新
	g_Obb.Update(&m_Obb, m_vPos, m_vAngle, m_vScale, m_vMin, m_vMax);

	//ワールド行列作成
	m_matWorld = MakeMatWorld(m_vPos, m_vAngle, m_vScale);
}

//移動関数
void CEnemyRed::Move()
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

				//休憩地点への最短ルート
				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());
			}
			//追いかけ
			else
			{
				//プレイヤーの位置取得
				D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

				//プレイヤーと敵の位置を要素数にする
				Goal_x = (int)PlayerPos.z / 4;
				Goal_y = (int)PlayerPos.x / 4;

				//プレイヤーへの最短ルート
				next = g_Route.RouteSearch(Start_x, Start_y, Goal_x, Goal_y, m_pMap->GetMapPointer());

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
	m_vPos += m_vMove * m_fSpeed;
}

//描画
void CEnemyRed::Draw()
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
