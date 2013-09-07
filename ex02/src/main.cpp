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
	LoadDivGraph("../res/images/knight.png", 12, 3, 4, 49, 66, gh);

	// �L�[�z��
	char key[256];

	// x���W,y���W
	int x = 300, y = 240;
	
	// �ړ��ʕ␳�l
	float move = 1.0f;
	
	// �ړ��ʕϐ�
	int dx = 0;
	int dy = 0;

	// �������Əc�����̃J�E���g��
	int xcount = 0, ycount = 0;

	// �Y���p�ϐ�
	int ix = 0, iy = 0, result = 0;

	// ����ʍ쐬
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
		
		// �J�E���g������Y�������߂�
		ix = abs(xcount) % 30 / 10;
		iy = abs(ycount) % 30 / 10;

		// x�J�E���g���v���X�Ȃ�E����,�}�C�i�X�Ȃ獶����
		if(xcount > 0){
			ix += 3;
			result = ix;
		}else if(xcount < 0){
			ix += 9;
			result = ix;
		}
		// y�J�E���g���v���X�Ȃ牺����,�}�C�i�X�Ȃ�����
		if(ycount > 0){
			iy += 6;
			result = iy;
		}else if(ycount < 0){
			iy += 0;
			result = iy;
		}

		// �΂߈ړ��̏ꍇ�͉���
		if(move == 0.71f){
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

		// ������ĂȂ���΃J�E���g���[���ɂ���
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

	// DxLib�̏I������
	DxLib_End();
	return 0;
}
