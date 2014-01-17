#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"

InputKey* InputKey::mInstance = 0;

InputKey::InputKey(){
	for(int i = 0;i < 256;i++){
		key[i] = 0;
	}
}

InputKey* InputKey::getInstance(){
	if(mInstance == 0){
		mInstance = new InputKey();
	}
	
	return mInstance;
}

bool InputKey::isOn(int keyIndex){
	if(key[keyIndex] >= 1){
		return true;
	}else{
		return false;
	}
}

bool InputKey::isFirst(int keyIndex){
	if(key[keyIndex] == 1){
		return true;
	}else{
		return false;
	}
}

void InputKey::updateKey(char* _key){
    for( int i=0; i<256; i++ ){ 
		if( _key[i] != 0 ){
			if(key[i] <= 100){	// 最大100
				key[i]++;	
			}
		} else {
			key[i] = 0;
		}
	}
}