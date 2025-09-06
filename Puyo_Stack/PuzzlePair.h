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

	enum class Rotation
	{
		Up,
		Right,
		Down,
		Left,

		Count
	};

private:
	Puzzle m_puzzles[2];	//2‚Â‚Ì‚Õ‚æ
	Vec2 m_offset;			//2‚Â–Ú‚Ì‚Õ‚æ‚Ì‘Š‘ÎˆÊ’u(—á:ã‚É‚ ‚é‚È‚ç)
};

