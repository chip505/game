#ifndef INCLUDED_INPUT_H
#define INCLUDED_INPUT_H

class InputKey;
class InputPad;

// シングルトンで作成
class Input{
private:
	static Input* mInstance;
	InputKey* inputKey;
	InputPad* inputPad;
private:
	Input();
	Input(const Input& rhs);
	Input& operator=(const Input& rhs);
public:
	static Input* getInstance();
private:
	static const int INPUT_MAX = 12;
	int configPad[INPUT_MAX];
	int configKey[INPUT_MAX];
public:
	enum INPUT_BUTTON{
		INPUT_DOWN,
		INPUT_LEFT,
		INPUT_RIGHT,
		INPUT_UP,
		INPUT_A,
		INPUT_B,
		INPUT_C,
		INPUT_D,
		INPUT_R,
		INPUT_L,
		INPUT_START,
		INPUT_SELECT,

		INPUT_NONE,
	};

	bool isOn(INPUT_BUTTON _input);
	bool isFirst(INPUT_BUTTON _input);
	bool isKeyOn(int _index);
	void setInput(char* _key, int _pad);
};

#endif