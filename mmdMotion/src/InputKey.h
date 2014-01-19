#ifndef INCLUDED_INPUT_KEY_H
#define INCLUDED_INPUT_KEY_H

// singleton
class InputKey{
private:
	static InputKey* mInstance;
	int key[256];
private:
	InputKey();
	InputKey(const InputKey& rhs);
	InputKey& operator=(const InputKey& rhs);
public:
	static InputKey* getInstance();
	bool isOn(int keyIndex);
	bool isFirst(int keyIndex);
	void updateKey(char* _key);
};

#endif