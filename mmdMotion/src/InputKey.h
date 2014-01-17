#ifndef INCLUDED_INPUT_KEY_H
#define INCLUDED_INPUT_KEY_H

// singleton
class InputKey{
private:
	static InputKey* mInstance;
	char* key;
private:
	InputKey(){}
	InputKey(const InputKey& rhs);
	InputKey& operator=(const InputKey& rhs);
public:
	static InputKey* getInstance();
	bool isOn(int keyIndex);
	char* getKey(){	return key; }
	void setKey(char* _key){ key = _key; }
};

#endif