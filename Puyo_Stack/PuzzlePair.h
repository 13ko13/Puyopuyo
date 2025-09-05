#pragma once
#include "Puzzle.h"

class PuzzlePair
{
public:
	PuzzlePair();
	~PuzzlePair();

	void Init();
	void End();
	void Update();
	void Draw();

	//相方の位置をrotationに合わせて更新
	void UpdateSubPosition();

	//回転
	void RotateRight();
	void RotateLeft();

private:
	//回転
	int rotation;	//0=上, 1=右, 2 = 下, 3 = 左

	//インスタンス
	Puzzle main;	//主ぷよ
	Puzzle sub;		//相方ぷよ
	
};

