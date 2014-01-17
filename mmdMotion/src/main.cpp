#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"

#include <string>
#include <iostream>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// 画面モードの変更
    SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	char key[256];
	InputKey* inputKey = InputKey::getInstance();

	int ModelHandle = MV1LoadModel("../res/dat/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");

	SetCameraNearFar(0.1f, 1000.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));

	while(ScreenFlip() == 0 && ProcessMessage() == 0 
		&& ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		inputKey->setKey(key);
		
		MV1DrawModel(ModelHandle);

		if( inputKey->isOn(KEY_INPUT_ESCAPE) ) break;
	}

	DxLib_End();

	return 0;
}