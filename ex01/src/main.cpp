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
	// �O���t�B�b�N�n���h��
	int gh;
	
	// �摜�ǂݍ���
	gh = LoadGraph("../res/images/zekausa.png");

	// �L�[�z��
	char key[256];

	// x���W,y���W
	int x = 300, y = 240;
	
	// �ړ��ʕ␳�l
	float move = 1.0f;
	
	// �ړ��ʕϐ�
	int dx = 0;
	int dy = 0;

	// ����ʍ쐬
	SetDrawScreen(DX_SCREEN_BACK);

	while(	ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0){
		move = 0.0f;

		DrawGraph(x, y, gh, TRUE);

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
			x -= (int)6 * move;
			dx = (int)-6* move;
		}
		if(key[KEY_INPUT_RIGHT] == 1){
			x += (int)6 * move;
			dx = (int)6 * move;
		}
		if(key[KEY_INPUT_UP] == 1){
			y -= (int)6 * move;
			dy = (int)-6* move;
		}
		if(key[KEY_INPUT_DOWN] == 1){
			y += (int)6 * move;
			dy = (int)6 * move;
		}
		
		// ���点�鏈��
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
		if(key[KEY_INPUT_ESCAPE] == 1){
			break;
		}
	}

	// DxLib�̏I������
	DxLib_End();
	return 0;
}
