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
	bool IsAlive() const;
	void RotateRight();	//�E��]
	void RotateLeft();	//����]

	enum class Rotation
	{
		Up,
		Right,
		Down,
		Left,

		Count
	};

private:
	Puzzle m_puzzles[2];	//2�̂Ղ�
	Vec2 m_offset;			//2�ڂ̂Ղ�̑��Έʒu(��:��ɂ���Ȃ�)
	Rotation m_rotation;	//��]���
	void UpdateChildPos();	//2�ڂ̂Ղ�̈ʒu�X�V
};

