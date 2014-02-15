#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "Field.h"

#include <string>

Field::Field(){
	width = 384;
	height = 448;
	x = 32;
	y = 16;
	gh1 = LoadGraph("../dat/img/board/10.png");
	gh2 = LoadGraph("../dat/img/board/11.png");
	gh3 = LoadGraph("../dat/img/board/12.png");
	gh4 = LoadGraph("../dat/img/board/20.png");
}

Field::~Field(){

}

void Field::update(){
	// do nothing
}

void Field::draw(){
	DrawGraph(  0,  0, gh1,FALSE);
	DrawGraph(  0, 16, gh2,FALSE);
	DrawGraph(  0,464, gh3,FALSE);
	DrawGraph(416,  0, gh4,FALSE);
}