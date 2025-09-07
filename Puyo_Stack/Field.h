#pragma once
#include "Puzzle.h"

namespace
{
	constexpr int kFieldWidth = 6;	//�t�B�[���h�̉���
	constexpr int kFieldHeight = 12;	//�t�B�[���h�̍���
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

	bool IsCellEmpty(int x, int y) const;
	void SetPuzzle(int x, int y, const Puzzle& puzzle);
	Puzzle& GetPuzzle(int x, int y);

private:
	Puzzle m_grid[kFieldHeight][kFieldWidth];	//�t�B�[���h�̃O���b�h
};

