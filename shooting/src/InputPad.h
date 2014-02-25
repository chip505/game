#ifndef INCLUDED_INPUT_PAD_H
#define INCLUDED_INPUT_PAD_H

class InputPad{
private:
	static const int PAD_MAX = 16;
	int state[PAD_MAX];
public:
	InputPad();
	~InputPad(){}
	void setInput(int input);
	bool isOn(int index);
	bool isFirst(int index);
};

#endif