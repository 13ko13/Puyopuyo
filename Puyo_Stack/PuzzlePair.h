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

	//�t�B�[���h�Ƃ̓����蔻�� 
	bool CheckCollision( Field& field);	
	bool IsAlive() const; //�ǂ��炩�̂Ղ悪�����Ă��邩
	void RotateRight();	//�E��]
	void RotateLeft();	//����]
	void LandToField(Field& field); //�t�B�[���h�ɒ��n������


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

