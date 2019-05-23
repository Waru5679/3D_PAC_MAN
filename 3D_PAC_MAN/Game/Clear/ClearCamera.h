#pragma once

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Camera.h"

//クリアシーン用　カメラクラス
class CClearCamera :public Camera
{
public:
	void Init();	//初期化
	void Update();	//更新
private:
};

