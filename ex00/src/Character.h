#ifndef INCLUDED_CHARACTER_H
#define INCLUDED_CHARACTER_H

class Character{
private:
	// 画像情報
	int witdh;
	int height;
	// 現在位置(中心座標)
	int posX;
	int posY;
	// 移動値
	int moveX;
	int moveY;
	// 向いている方向
	enum Direction{ D_UP, D_RIGHT, D_LEFT, D_DOWN,};
	Direction direction;
	// 移動カウンタ
	int moveCountX;
	int moveCountY;
	// 描画対象へのインデクス
	int ghIndex;
	// グラフィックハンドラ
	int gh[12];
public:
	Character();
	Character(int x, int y);
	~Character();
	void init();
	void draw();	// 現在位置に描画
	void update();
	void updateMoveValue();
	void updatePosition();	// 移動値に従って移動
	void updateDirection();

	void setPosX(int x){posX = x;}
	void setPosY(int y){posY = y;}
	void setMoveX(int x){moveX = x;}
	void setMoveY(int y){moveY = y;}
	int getPosX(){return posX;}
	int getPosY(){return posY;}
	int getMoveX(){return moveX;}
	int getMoveY(){return moveY;}
	int getDirectionIndex();
};

#endif