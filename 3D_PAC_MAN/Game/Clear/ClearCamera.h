#pragma once

#include "../../LIbrary/Main.h"
#include "../../LIbrary/Camera.h"

//クリアシーン用　カメラクラス
class CClearCamera :public CameraBase
{
public:
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
};

