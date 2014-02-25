#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "InputPad.h"

InputPad::InputPad(){
	for(int i = 0;i < PAD_MAX;i++){
		state[i] = 0;
	}
}

void InputPad::setInput(int input){
	int mul = 1;
	for(int i = 0;i < PAD_MAX;i++){
		if(input & mul){
			state[i]++;
		}else{
			state[i] = 0;
		}
		mul *= 2;
	}
}

bool InputPad::isOn(int index){
	if(index < 0 || PAD_MAX <= index){
		return false;
	}

	if(state[index] > 0){
		return true;
	}else{
		return false;
	}
}

bool InputPad::isFirst(int index){
	if(index < 0 || PAD_MAX <= index){
		return false;
	}

	if(state[index] == 1){
		return true;
	}else{
		return false;
	}
}