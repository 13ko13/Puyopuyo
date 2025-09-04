#pragma once
#include "Vec2.h"

class Puzzle
{
public:
	Puzzle();
	~Puzzle();

	void Init(int handle);
	void End();
	void Update();
	void Draw();

private:
	//ハンドル関係
	int m_handle;	//グラフィックハンドル

	//インスタンス
	Vec2 m_pos;			//位置
	Vec2 m_velocity;	//速度
};

