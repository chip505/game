#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputKey.h"


InputKey::InputKey(){
	for(int i = 0;i < KEY_MAX;i++){
		state[i] = 0;
	}
}

void InputKey::setInput(char* _key){
	for(int i = 0;i < KEY_MAX;i++){
		if(_key[i] == 1){
			state[i]++;
		}else{
			state[i] = 0;
		}
	}
}

bool InputKey::isOn(int index){
	if(index < 0 || KEY_MAX <= index){
		return false;
	}

	if(state[index] > 0){
		return true;
	}else{
		return false;
	}
}

bool InputKey::isFirst(int index){
	if(index < 0 || KEY_MAX <= index){
		return false;
	}

	if(state[index] == 1){
		return true;
	}else{
		return false;
	}
}
