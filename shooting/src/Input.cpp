#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "Input.h"
#include "InputKey.h"
#include "InputPad.h"

Input* Input::mInstance = 0;

Input* Input::getInstance(){
	if(mInstance == 0){
		mInstance = new Input();
	}

	return mInstance;
}

Input::Input(){
	inputKey = new InputKey();
	inputPad = new InputPad();

	// キー割り当ての設定
	// Todo:外部ファイルから読み込むようにする
	for(int i = 0;i < INPUT_MAX;i++){
		configPad[i] = -1;
		configKey[i] = -1;
	}
	configPad[INPUT_DOWN] 	= PAD_INPUT_DOWN;	configKey[INPUT_DOWN] 	= KEY_INPUT_DOWN;
	configPad[INPUT_LEFT] 	= PAD_INPUT_LEFT;	configKey[INPUT_LEFT] 	= KEY_INPUT_LEFT;
	configPad[INPUT_RIGHT] 	= PAD_INPUT_RIGHT;	configKey[INPUT_RIGHT] 	= KEY_INPUT_RIGHT;
	configPad[INPUT_UP] 	= PAD_INPUT_UP;		configKey[INPUT_UP] 	= KEY_INPUT_UP;
	configPad[INPUT_A] 		= PAD_INPUT_1;		configKey[INPUT_A] 		= KEY_INPUT_A;
	configPad[INPUT_B] 		= PAD_INPUT_2;		configKey[INPUT_B] 		= KEY_INPUT_S;
	configPad[INPUT_C] 		= PAD_INPUT_3;		configKey[INPUT_C] 		= KEY_INPUT_D;
	configPad[INPUT_D] 		= PAD_INPUT_4;		configKey[INPUT_D] 		= KEY_INPUT_F;
	configPad[INPUT_START] 	= PAD_INPUT_5;		configKey[INPUT_START] 	= KEY_INPUT_SPACE;
}

bool Input::isOn(INPUT_BUTTON _input){
	bool keyFlag = inputKey->isOn(configKey[_input]);
	bool padFlag = inputPad->isOn(configPad[_input]);

	return keyFlag | padFlag;
}

bool Input::isFirst(INPUT_BUTTON _input){
	bool keyFlag = inputKey->isFirst(configKey[_input]);
	bool padFlag = inputPad->isFirst(configPad[_input]);

	return keyFlag | padFlag;
}

bool Input::isKeyOn(int _index){
	return inputKey->isOn(_index);
}

void Input::setInput(char* _key, int _pad){
	inputKey->setInput(_key);
	inputPad->setInput(_pad);
}