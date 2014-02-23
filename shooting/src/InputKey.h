#ifndef INCLUDED_INPUT_KEY_H
#define INCLUDED_INPUT_KEY_H

// singleton
class InputKey{
private:
	static InputKey* mInstance;
	int stateKey[256];
private:
	InputKey();
	InputKey(const InputKey& rhs);
	InputKey& operator=(const InputKey& rhs);
public:
	static InputKey* getInstance();
	bool isOn(int keyIndex);
	bool isFirst(int keyIndex);
	void setKey(char* _key);
};

#endif