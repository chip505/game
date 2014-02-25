#ifndef INCLUDED_INPUT_KEY_H
#define INCLUDED_INPUT_KEY_H

// singleton
class InputKey{
private:
	static const int KEY_MAX = 256;
	int state[KEY_MAX];
public:
	InputKey();
	bool isOn(int keyIndex);
	bool isFirst(int keyIndex);
	void setInput(char* _key);
};

#endif