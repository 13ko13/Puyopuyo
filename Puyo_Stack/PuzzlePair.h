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

	//�����̈ʒu��rotation�ɍ��킹�čX�V
	void UpdateSubPosition();

	//��]
	void RotateRight();
	void RotateLeft();

private:
	//��]
	int rotation;	//0=��, 1=�E, 2 = ��, 3 = ��

	//�C���X�^���X
	Puzzle main;	//��Ղ�
	Puzzle sub;		//�����Ղ�
	
};

