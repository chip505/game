#ifndef INCLUDED_GAME_H
#define INCLUDED_GAME_H

class Character;
class Field;

class Game{
private:
	int windowWitdh;
	int windowHeight;
	Character* chara;
	Field* field;
	bool endFlag;
public:
	Game();
	~Game();
	void update();
	void draw();
	bool getEndFlag(){return endFlag;};
};

#endif