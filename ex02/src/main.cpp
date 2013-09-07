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
	LoadDivGraph("../res/images/knight.png", 12, 3, 4, 49, 66, gh);

	// キー配列
	char key[256];

	// x座標,y座標
	int x = 300, y = 240;
	
	// 移動量補正値
	float move = 1.0f;
	
	// 移動量変数
	int dx = 0;
	int dy = 0;

	// 横方向と縦方向のカウント数
	int xcount = 0, ycount = 0;

	// 添字用変数
	int ix = 0, iy = 0, result = 0;

	// 裏画面作成
	SetDrawScreen(DX_SCREEN_BACK);

	while(	ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		move = 0.0f;
		if(key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1){
			if(key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1){
				move = 0.71f;
			}else{
				move = 1.0f;
			}
		}else if(key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1){
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
		if(key[KEY_INPUT_UP] == 1){
			y -= (int)4 * move;
			dy = (int)-4* move;
			if(ycount > 0){
				ycount = 0;
			}
			--ycount;
		}
		if(key[KEY_INPUT_DOWN] == 1){
			y += (int)4 * move;
			dy = (int)4 * move;
			if(ycount < 0){
				ycount = 0;
			}
			++ycount;
		}
		
		// カウント数から添字を求める
		ix = abs(xcount) % 30 / 10;
		iy = abs(ycount) % 30 / 10;

		// xカウントがプラスなら右向き,マイナスなら左向き
		if(xcount > 0){
			ix += 3;
			result = ix;
		}else if(xcount < 0){
			ix += 9;
			result = ix;
		}
		// yカウントがプラスなら下向き,マイナスなら上向き
		if(ycount > 0){
			iy += 6;
			result = iy;
		}else if(ycount < 0){
			iy += 0;
			result = iy;
		}

		// 斜め移動の場合は横顔
		if(move == 0.71f){
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
			if(dy != 0){
				if(dy < 0){
					++dy;
				}
				if(dy > 0){
					--dy;
				}
			}
			x += dx;
			y += dy;
		}

		// 押されてなければカウントをゼロにする
		if(key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1){
			xcount = 0;
		}
		if(key[KEY_INPUT_UP] != 1 && key[KEY_INPUT_DOWN] != 1){
			ycount = 0;
		}

		if(key[KEY_INPUT_ESCAPE] == 1){
			break;
		}

		DrawGraph(x, y, gh[result], TRUE);
	}

	// DxLibの終了処理
	DxLib_End();
	return 0;
}
