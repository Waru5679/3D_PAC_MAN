#pragma once

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Camera.h"

//タイトルシーン用　カメラクラス
class CTitleCamera:public Camera
{
public:
	void Init();	//初期化
	void Update();	//更新
private:
};

