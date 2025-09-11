#pragma once
#include "Puzzle.h"

namespace field
{
	constexpr int kFieldWidth = 6;	//�t�B�[���h�̉���
	constexpr int kFieldHeight = 23;	//�t�B�[���h�̍���
}

class Field
{
public:
	Field();
	~Field();

	void Init();
	void End();
	void Update();
	void Draw();

	void SetPuzzle(int x, int y, const Puzzle& puzzle);
	Puzzle& GetPuzzle(int x, int y);

private:
	Puzzle m_grid[field::kFieldHeight][field::kFieldWidth];	//�t�B�[���h�̃O���b�h
};

