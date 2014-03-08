#ifndef INCLUDED_ENEMY_H
#define INCLUDED_ENEMY_H

class Enemy{
private:
	bool flag;
	int cnt;
	int pattern;
	int muki;
	int type;
	int HPMax;
	int item[6];
	int ghIndex;

	double posX;
	double posY;
	double vx;
	double vy;
	double speed;
	double angle;

	int shotTime;	// 弾幕開始時間
	int shotType;	// 弾幕の種類
	int bulletType;	// 弾の種類
	int color;		// 色
	int state;		// 状態
	int waitTime;	// 待機時間
	int wait;		// 停滞時間

};

#endif