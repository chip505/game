#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#define GLOBAL_INSTANCE
#include "DxLib/DxLib.h"
#include "Game.h"
#include "Input.h"

#include <string>
#include <iostream>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// 画面モードの変更
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1){
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	char key[256];
	Input* input = Input::getInstance();

	Game* game = new Game();
	while(ScreenFlip() == 0 && ProcessMessage() == 0 
		&& ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		int padInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
		input->setInput(key, padInput);
		game -> update();
		game -> draw();
		if( input->isKeyOn(KEY_INPUT_ESCAPE) ) break;
	}

	delete game;

	DxLib_End();

	return 0;
}