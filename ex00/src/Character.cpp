#include "DxLib/DxLib.h"
#include "Character.h"
#include "InputKey.h"

#include <string>
#include <iostream>

using namespace std;
Character::Character(){
	posX = 0;
	posY = 0;
	init();
}

Character::Character(int x, int y){
	posX = x;
	posY = y;
	init();
}

void Character::init(){
	/** MEMO :
	* LoadDivGraph( char *FileName , int AllNum , int XNum , int YNum ,int XSize , int YSize , int *HandleBuf );
	* FileName 		:　分割読み込みする画像ファイル文字列のポインタ
	* AllNum		:　画像の分割総数
	* XNum ,YNum	:　画像の横向きに対する分割数と縦に対する分割数
	* SizeX ,SizeY　	:　分割された画像一つの大きさ
	* HandleBuf		:　分割読み込みして得たグラフィックハンドルを保存するint型の配列へのポインタ
	* (例)
	* int gh[12];
	* LoadDivGraph("hoge.jpg", 12, 3, 4, 30, 40, gh );
	* 画像[hoge.jpg]が横30px,縦40pxで横に3段,縦に4段で12分割される
	* 格納されるグラフィックハンドラ配列の中身は
	* | 0  1  2|
	* | 3  4  5|
	* | 6  7  8|
	* |10 11 12|
 	*/
 	witdh = 49;
 	height = 66;
 	direction = D_RIGHT;
	moveX = 0;
	moveY = 0;
	ghIndex = 0;
	moveCountX = 0;
	moveCountY = 0;
	const string imageStr = "../res/images/knight.png";
	LoadDivGraph(imageStr.c_str(), 12, 3, 4, 49, 66, gh);
}


Character::~Character(){

}

void Character::draw(){
	DrawGraph(posX, posY, gh[ghIndex], TRUE);
}


void Character::update(){
	// 移動値更新
	updateMoveValue();

	// 位置更新
	updatePosition();

	// 方向更新
	updateDirection();
}

void Character::updateMoveValue(){
	InputKey* inputKey = InputKey::getInstance();
	float moveValue = 6.0f;	// 移動量
	float moveCorrectionValue = 0.71f;	// 移動補正値
	bool xTransFlag = false;
	bool yTransFlag = false;
	int dx = 0;
	int dy = 0;
	// 横移動判定
	if(inputKey->isOn(KEY_INPUT_LEFT)){
		dx = (int) (-1)*moveValue;
		xTransFlag = true;
	}else if(inputKey->isOn(KEY_INPUT_RIGHT)){
		dx = (int) moveValue;
		xTransFlag = true;
	}

	// 縦移動判定
	if(inputKey->isOn(KEY_INPUT_UP)){
		dy = (int) (-1)*moveValue;
		yTransFlag = true;
	}else if(inputKey->isOn(KEY_INPUT_DOWN)){
		dy = (int) moveValue;
		yTransFlag = true;
	}

	// 斜め移動判定
	if(xTransFlag && yTransFlag){
		dx = (int) dx*moveCorrectionValue;
		dy = (int) dy*moveCorrectionValue;
	}

	// 滑り判定
	if(!xTransFlag && !yTransFlag){
		dx = moveX;
		dy = moveY;
		if(dx != 0){
			if(dx > 0){
				dx--;
			}else{
				dx++;
			}
		}

		if(dy != 0){
			if(dy > 0){
				dy--;
			}else{
				dy++;
			}
		}
	}

	moveX = dx;
	moveY = dy;
}


void Character::updatePosition(){
	posX += moveX;
	posY += moveY;
}


void Character::updateDirection(){
	// 斜め移動時は横向き画像が採用される
	int animationIndex = 0;		// その方向の何番目の画像を使用するか
	if(moveY > 0){
		// 下向き
		moveCountY = (moveCountY + 1) % 30;
		animationIndex = moveCountY / 10;
		direction = D_DOWN;
	}else if(moveY < 0){
		// 上向き
		moveCountY = (moveCountY - 1) % 30;
		animationIndex = moveCountY / 10;
		direction = D_UP;
	}

	if(moveX > 0){
		// 右向き
		moveCountX = (moveCountX + 1) % 30;
		animationIndex = moveCountX / 10;
		direction = D_RIGHT;
	}else if(moveX < 0){
		// 左向き
		moveCountX = (moveCountX - 1) % 30;
		animationIndex = moveCountX / 10;
		direction = D_LEFT;
	}

	int directionIndex = getDirectionIndex();	// 方向
	ghIndex = directionIndex * 3 + abs(animationIndex);
}


int Character::getDirectionIndex(){
	int result = 0;
	switch(direction){
	case D_UP:
		result = 0; break;
	case D_RIGHT:
		result = 1; break;
	case D_DOWN:
		result = 2; break;
	case D_LEFT:
		result = 3; break;
	}
	return result;
}