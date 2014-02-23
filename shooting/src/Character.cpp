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
 	witdh = 73;
 	height = 73;
 	ghIndex = 0;
	const string imageStr = "../dat/img/char/0.png";
	LoadDivGraph(imageStr.c_str(), 12, 4, 3, 73, 73, gh);
}


Character::~Character(){

}

void Character::draw(){
	DrawGraph(posX, posY, gh[ghIndex], TRUE);
}


void Character::update(){
	cnt++;
	ghIndex = (cnt % 24) / 6;
}