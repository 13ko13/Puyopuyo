#pragma once
#include "Puzzle.h"

namespace field
{
	constexpr int kFieldWidth = 6;	//フィールドの横幅
	constexpr int kFieldHeight = 23;	//フィールドの高さ
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
	Puzzle m_grid[field::kFieldHeight][field::kFieldWidth];	//フィールドのグリッド
};

