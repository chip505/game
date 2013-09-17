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
	int gh[12];
	
	// �摜�ǂݍ���
	LoadDivGraph("../res/images/shimakaze.png", 6, 3, 2, 24, 32, gh);

	// �L�[�z��
	char key[256];

	// x���W,y���W
	int x = 300, y = 300 ,y_prev = 0, y_temp = 0;
	
	// �W�����v�t���O
	bool jflag = false;
	
	// �ړ��ʕ␳�l
	float move = 1.0f;
	
	// �ړ��ʕϐ�
	int dx = 0;

	// �������Əc�����̃J�E���g��
	int xcount = 0;

	// �Y���p�ϐ�
	int ix = 0, result = 0;

	// ����ʍ쐬
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
		
		// �W�����v����
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
		
		// �J�E���g������Y�������߂�
		ix = abs(xcount) % 30 / 10;
		
		// x�J�E���g���v���X�Ȃ�E����,�}�C�i�X�Ȃ獶����
		if(xcount > 0){
			ix += 0;
			result = ix;
		}else if(xcount < 0){
			ix += 3;
			result = ix;
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
			x += dx;
		}

		// ������ĂȂ���΃J�E���g���[���ɂ���
		if(key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1){
			xcount = 0;
		}
		
		if(key[KEY_INPUT_ESCAPE] == 1){
			break;
		}

		//DrawGraph(x, y, gh[result], TRUE);
		DrawRotaGraph(x,y, 2.0, 0.0,gh[result], TRUE);
	}

	// DxLib�̏I������
	DxLib_End();
	return 0;
}
