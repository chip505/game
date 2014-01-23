#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"

#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void rotate(float *x, float *y, const float ang, const float mx, const float my)
{
	const float ox = *x - mx, oy = *y - my;
	*x =  ox * cos(ang) + oy * sin(ang);
	*y = -ox * sin(ang) + oy * cos(ang);
	*x += mx;
	*y += my;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 画面初期化
	SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);

	if(DxLib_Init() == -1) {
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// キー
	char key[256];
	InputKey *inputKey = InputKey::getInstance();

	// 人物モデル
	int ModelHandle = MV1LoadModel("../res/dat/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");
	int attachIndex = MV1AttachAnim(ModelHandle, 0, -1, false);
	float totalTime = MV1GetAttachAnimTotalTime(ModelHandle, attachIndex);
	float playTime = 0.0f;
	float angle = 0.0f;
	float posX = 0.0f;
	float posZ = 0.0f;
	float posY = 0.0f;
	float prevPosY = 0.0f;
	bool isJump = false;
	int jumpCount = 0;

	// 背景モデルの読み込み  
	int backGroundModelHandle = MV1LoadModel( "../res/dat/バトーキン島/batokin_island5.x" ) ;  
	MV1SetPosition( backGroundModelHandle, VGet( 0.0f, 0.0f, 0.0f ) ) ;  

	// カメラ
	float cameraX = 0.0f;
	float cameraZ = -50.0f;
	const float targetX = 0.0f;
	const float targetZ = 0.0f;
	SetCameraNearFar(0.1f, 1000.0f);

	while(ScreenFlip() == 0 && ProcessMessage() == 0
	        && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
		inputKey->updateKey(key);

		// カメラ
		if(inputKey->isOn(KEY_INPUT_J)) {
			rotate(&cameraX, &cameraZ, -DX_PI_F / 90.0f, targetX, targetZ);
		} else if(inputKey->isOn(KEY_INPUT_K)) {
			rotate(&cameraX, &cameraZ, DX_PI_F / 90.0f, targetX, targetZ);
		}

		SetCameraPositionAndTarget_UpVecY(VGet(cameraX, 50, cameraZ), VGet(targetX, 10.0f, targetZ)) ;

		// ポーズ決め
		if(inputKey->isOn(KEY_INPUT_SPACE)){
			if(!isJump){
				isJump = true;
				MV1DetachAnim(ModelHandle, attachIndex);
				attachIndex = MV1AttachAnim(ModelHandle, 2, -1, FALSE) ;
				totalTime = MV1GetAttachAnimTotalTime(ModelHandle, attachIndex) ;
				prevPosY = posY;
				posY += 3.0f;
			}
		}

		if(inputKey->isOn(KEY_INPUT_RIGHT) || inputKey->isOn(KEY_INPUT_LEFT) || inputKey->isOn(KEY_INPUT_UP) || inputKey->isOn(KEY_INPUT_DOWN)) {
			if(!isJump) {
				MV1DetachAnim(ModelHandle, attachIndex);
				attachIndex = MV1AttachAnim(ModelHandle, 1, -1, FALSE) ;
				totalTime = MV1GetAttachAnimTotalTime(ModelHandle, attachIndex) ;
			}
			playTime += 0.8f;
			if(playTime >= totalTime) {
				playTime = 0.0f;
			}

		} else {
				// なにも押されてなかったら直立
			playTime = 0.0f;
			if(!isJump){
				MV1DetachAnim(ModelHandle, attachIndex);
				attachIndex = MV1AttachAnim(ModelHandle, 0, -1, FALSE) ;
				totalTime = MV1GetAttachAnimTotalTime(ModelHandle, attachIndex) ;
			}
		}

		MV1SetAttachAnimTime(ModelHandle, attachIndex, playTime);


		// モデル位置
		if(isJump){
			float y_temp = posY;
            posY +=(posY - prevPosY) - 0.3f;
            prevPosY = y_temp;
            if(posY <= 0.0f){
				posY = 0.0f; // 誤差防止
				isJump = false;
			}
		}

		if(inputKey->isOn(KEY_INPUT_RIGHT)) {
			if(inputKey->isOn(KEY_INPUT_UP)) {
                posX += 0.8f*0.7;
				posZ += 0.8f*0.7;
				angle = -DX_PI_F * 3.0 / 4.0f;
			} else if(inputKey->isOn(KEY_INPUT_DOWN)) {
                posX += 0.8f*0.7;
				posZ -= 0.8f*0.7;
				angle = -DX_PI_F / 4.0f;
			} else {
				posX += 0.8f;
				angle = -DX_PI_F / 2.0f;
			}
		} else if(inputKey->isOn(KEY_INPUT_LEFT)) {
			if(inputKey->isOn(KEY_INPUT_UP)) {
                posX -= 0.8f*0.7;
				posZ += 0.8f*0.7;
				angle = DX_PI_F * 3.0 / 4.0f;
			} else if(inputKey->isOn(KEY_INPUT_DOWN)) {
                posX -= 0.8f*0.7;
				posZ -= 0.8f*0.7;
				angle = DX_PI_F / 4.0f;
			} else {
				posX -= 0.8f;
				angle = DX_PI_F / 2.0f;
			}
		} else {
			if(inputKey->isOn(KEY_INPUT_UP)) {
				posZ += 0.8f;
				angle = DX_PI_F;
			} else if(inputKey->isOn(KEY_INPUT_DOWN)) {
				posZ -= 0.8f;
				angle = 0.0f;
			}
		}
		MV1SetPosition(ModelHandle, VGet(posX, posY, posZ)) ;
		MV1SetRotationXYZ(ModelHandle, VGet(0.0f, angle, 0.0f)) ;

		MV1DrawModel(ModelHandle);

		// 背景描画
		MV1DrawModel( backGroundModelHandle ) ;

		if(inputKey->isOn(KEY_INPUT_ESCAPE)) break;
	}

	DxLib_End();

	return 0;
}