#pragma once

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Camera.h"

//ゲームオーバーシーン　カメラクラス
class CGameOverCamera :public Camera
{
public:
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
};

