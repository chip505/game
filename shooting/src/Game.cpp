#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "Character.h"
#include "Game.h"
#include "Field.h"
#include "Input.h"

#include <string>
#include <iostream>

using namespace std;

Game::Game(){
	chara = new Character(200, 300);
	field = new Field();
	endFlag = false;
}

Game::~Game(){
	delete chara;
	delete field;
}

void Game::update(){
	Input* input = Input::getInstance();
	// キャラクターの移動制御
	chara->update(384, 448);
	
	field->update();
	// 終了判定
	//if(input->isKeyOn(KEY_INPUT_ESCAPE)){
	//	endFlag = true;
	//}
}

void Game::draw(){
	chara->draw();
	field->draw();
}