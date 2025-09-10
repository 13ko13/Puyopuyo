#pragma once
#include "Puzzle.h"
#include "Field.h"

class PuzzlePair
{
public:
	PuzzlePair();
	~PuzzlePair();

	void Init();
	void End();
	void Update();
	void Draw();

	//フィールドとの当たり判定 
	bool CheckCollision( Field& field);	
	bool IsAlive() const; //どちらかのぷよが生きているか
	void RotateRight();	//右回転
	void RotateLeft();	//左回転
	void LandToField(Field& field); //フィールドに着地させる


	enum class Rotation
	{
		Up,
		Right,
		Down,
		Left,

		Count
	};

private:
	Puzzle m_puzzles[2];	//2つのぷよ
	Vec2 m_offset;			//2つ目のぷよの相対位置(例:上にあるなら)
	Rotation m_rotation;	//回転状態
	void UpdateChildPos();	//2つ目のぷよの位置更新
};

