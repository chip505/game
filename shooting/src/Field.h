class Field{
private:
	// 大きさ
	int width;
	int height;
	// 左上の位置
	int x;
	int y;

	// グラフィックハンドル
	int gh1;
	int gh2;
	int gh3;
	int gh4;
public:
	Field();
	~Field();
	void update();
	void draw();
};