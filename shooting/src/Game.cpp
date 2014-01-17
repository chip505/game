#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"
#include "Character.h"
#include "Game.h"
#include "InputKey.h"

#include <string>
#include <iostream>

using namespace std;

Game::Game(){
	chara = new Character(200, 0);
	endFlag = false;
}

Game::~Game(){
	delete chara;
}

void Game::update(){
	InputKey* inputKey = InputKey::getInstance();
	chara->update();
	// 終了判定
	if(inputKey->isOn(KEY_INPUT_ESCAPE)){
		endFlag = true;
	}
}

void Game::draw(){
	chara->draw();
}