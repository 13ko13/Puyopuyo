#pragma once
#include "Puzzle.h"

namespace
{
	constexpr int kFieldWidth = 6;	//フィールドの横幅
	constexpr int kFieldHeight = 12;	//フィールドの高さ
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
	Puzzle m_grid[kFieldHeight][kFieldWidth];	//フィールドのグリッド
};

