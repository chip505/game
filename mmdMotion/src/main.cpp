#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"

#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void rotate(float *x, float *y, const float ang, const float mx, const float my){
    const float ox = *x-mx, oy = *y-my;
    *x =  ox * cos(ang) + oy * sin(ang);
    *y = -ox * sin(ang) + oy * cos(ang);
    *x += mx;
    *y += my;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// ��ʏ�����
    SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// �L�[
	char key[256];
	InputKey* inputKey = InputKey::getInstance();

	// ���f��
	int ModelHandle = MV1LoadModel("../res/dat/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");
	int attachIndex = MV1AttachAnim(ModelHandle, 0, -1, false);
	float totalTime = MV1GetAttachAnimTotalTime(ModelHandle, attachIndex);
	float playTime = 0.0f;
	float angle = 0.0f;
	float posX = 0.0f;
	float posY = 0.0f;

	// �J����
	float cameraX = 0.0f;
	float cameraZ = -50.0f;
	const float targetX = 0.0f;
	const float targetZ = 0.0f;
	SetCameraNearFar(0.1f, 1000.0f);

	while(ScreenFlip() == 0 && ProcessMessage() == 0 
		&& ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		inputKey->updateKey(key);
		
		// �J����
		if(inputKey->isOn(KEY_INPUT_J)){
			rotate(&cameraX, &cameraZ,-DX_PI_F/90.0f, targetX, targetZ);
		}else if(inputKey->isOn(KEY_INPUT_K)){
			rotate(&cameraX, &cameraZ, DX_PI_F/90.0f, targetX, targetZ);
		}

		SetCameraPositionAndTarget_UpVecY( VGet( cameraX, 50, cameraZ ), VGet( targetX, 10.0f, targetZ ) ) ;

		// ���[�V�����I��
		if(inputKey->isFirst()){

		}

		// �|�[�Y����
		if(inputKey->isOn(KEY_INPUT_RIGHT) || inputKey->isOn(KEY_INPUT_LEFT)){
			playTime += 0.8f;

			if(playTime >= totalTime){
				playTime = 0.0f;
			}

			MV1DetachAnim(ModelHandle, attachIndex);
			attachIndex = MV1AttachAnim( ModelHandle, 1, -1, FALSE ) ;
			totalTime = MV1GetAttachAnimTotalTime( ModelHandle, attachIndex ) ;
			MV1SetAttachAnimTime(ModelHandle, attachIndex, playTime);
		}else{
			playTime = 0.0f;
			MV1DetachAnim(ModelHandle, attachIndex);
		}



		// ���f���p��
		if(inputKey->isOn(KEY_INPUT_RIGHT)){
			posX+=0.8f;
			angleY = -DX_PI_F/2.0f;
		}else if(inputKey->isOn(KEY_INPUT_LEFT)){
			posX-=0.8f;
			angleY = DX_PI_F/2.0f;
		}else{
			angleY = 0.0f;
		}
		MV1SetPosition( ModelHandle, VGet( posX, 0.0f, 0.0f ) ) ;
		MV1SetRotationXYZ( ModelHandle, VGet( 0.0f, angleY, 0.0f )) ;
		

		MV1DrawModel(ModelHandle);

		if( inputKey->isOn(KEY_INPUT_ESCAPE) ) break;
	}

	DxLib_End();

	return 0;
}