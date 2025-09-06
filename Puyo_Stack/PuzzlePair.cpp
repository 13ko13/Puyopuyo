#include "PuzzlePair.h"
#include "Puzzle.h"

namespace
{
	constexpr int kPuzzleHeight = 25;	//ぷよ1個の高さ
}

PuzzlePair::PuzzlePair() :
	m_offset(0.0f, -kPuzzleHeight)
{
}

PuzzlePair::~PuzzlePair()
{
}

void PuzzlePair::Init()
{
	m_puzzles[0].Init();	//一つ目のぷよ
	m_puzzles[1].Init();	//二つ目のぷよ

	//二つ目のぷよの位置を一つ目に対してオフセット
	m_puzzles[1].SetPos(m_puzzles[0].GetPos() + m_offset);
}

void PuzzlePair::Update()
{
	for (int i = 0; i < 2; ++i)
	{
		m_puzzles[i].Update();
	}
}

void PuzzlePair::Draw()
{
	for (int i = 0; i < 2; ++i)
	{
		m_puzzles[i].Draw();
	}
}

bool PuzzlePair::IsAlive() const
{
	return m_puzzles[0].IsAlive() || m_puzzles[1].IsAlive();
}

