#pragma once

//ライブラリファイル
#include "../../Library/Main.h"
#include "../../Library/Camera.h"

//タイトルシーン用　カメラクラス
class CTitleCamera:public CameraBase
{
public:
	void Init();	//初期化
	void Update();	//更新
	void Draw();	//描画
private:
};

