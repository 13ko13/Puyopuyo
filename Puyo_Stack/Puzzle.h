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

	void SetPosition(int nx, int ny);	//ぷよのポジションを記憶

private:
	//ハンドル関係
	int m_handle;	//グラフィックハンドル
	
	//ぷよの色
	int m_color;		//色ID(0 = 赤,1 = 青, 2 = 緑, 3 = 黄)

	//アニメーション関係
	int m_animFrame;	//現在のアニメーション状態

	//フラグ関係
	bool m_alive;			//存在しているか

	//インスタンス
	Vec2 m_pos;			//位置
	Vec2 m_velocity;	//速度
};

