#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"

InputKey* InputKey::mInstance = 0;

InputKey* InputKey::getInstance(){
	if(mInstance == 0){
		mInstance = new InputKey();
	}

	return mInstance;
}

InputKey::InputKey(){
	for(int i = 0;i < 256;i++){
		stateKey[i] = 0;
	}
}

void InputKey::setKey(char* _key){
	for(int i = 0;i < 256;i++){
		if(_key[i] == 1){
			stateKey[i]++;
		}else{
			stateKey[i] = 0;
		}
	}
}

bool InputKey::isOn(int keyIndex){
	if(stateKey[keyIndex] > 0){
		return true;
	}else{
		return false;
	}
}

bool InputKey::isFirst(int keyIndex){
	if(stateKey[keyIndex] == 1){
		return true;
	}else{
		return false;
	}
}
