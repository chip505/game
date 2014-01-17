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

bool InputKey::isOn(int keyIndex){
	if(key[keyIndex]){
		return true;
	}else{
		return false;
	}
}
