#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib/DxLib.h"

int changeCharacter(){
	
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1){
		return 1;
	}
	// グラフィックハンドル
	int gh[12];
	
	// 画像読み込み
	LoadDivGraph("../res/images/shimakaze.png", 6, 3, 2, 24, 32, gh);

	// キー配列
	char key[256];

	// x座標,y座標
	int x = 300, y = 300 ,y_prev = 0, y_temp = 0;
	
	// ジャンプフラグ
	bool jflag = false;
	
	// 移動量補正値
	float move = 1.0f;
	
	// 移動量変数
	int dx = 0;

	// 横方向と縦方向のカウント数
	int xcount = 0;

	// 添字用変数
	int ix = 0, result = 0;

	// 裏画面作成
	SetDrawScreen(DX_SCREEN_BACK);

	while(	ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		move = 0.0f;
		if(key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1){
				move = 1.0f;
		}

		if(key[KEY_INPUT_LEFT] == 1){
			x -= (int)4 * move;
			dx = (int)-4* move;
			if(xcount > 0){
				xcount = 0;
			}
			--xcount;
		}
		if(key[KEY_INPUT_RIGHT] == 1){
			x += (int)4 * move;
			dx = (int)4 * move;
			if(xcount < 0){
				xcount = 0;
			}
			++xcount;
		}
		
		// ジャンプ処理
		if(jflag == true){
			y_temp = y;
			y += (y - y_prev) +1;
			y_prev = y_temp;
			if(y == 300){
				jflag = false;
			}
		}
		if(key[KEY_INPUT_SPACE] == 1 && jflag == false){
			jflag = true;
			y_prev = y;
			y -= 20;
		}
		
		// カウント数から添字を求める
		ix = abs(xcount) % 30 / 10;
		
		// xカウントがプラスなら右向き,マイナスなら左向き
		if(xcount > 0){
			ix += 0;
			result = ix;
		}else if(xcount < 0){
			ix += 3;
			result = ix;
		}

		// 滑らせる処理
		if(move == 0.0f){
			if(dx != 0){
				if(dx < 0){
					++dx;
				}
				if(dx > 0){
					--dx;
				}
			}
			x += dx;
		}

		// 押されてなければカウントをゼロにする
		if(key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1){
			xcount = 0;
		}
		
		if(key[KEY_INPUT_ESCAPE] == 1){
			break;
		}

		//DrawGraph(x, y, gh[result], TRUE);
		DrawRotaGraph(x,y, 2.0, 0.0,gh[result], TRUE);
	}

	// DxLibの終了処理
	DxLib_End();
	return 0;
}
