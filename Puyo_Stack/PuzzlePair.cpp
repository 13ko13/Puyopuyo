#include "PuzzlePair.h"
#include "Puzzle.h"

namespace
{
	constexpr int kPuzzleHeight = 25;	//�Ղ�1�̍���
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
	m_puzzles[0].Init();	//��ڂ̂Ղ�
	m_puzzles[1].Init();	//��ڂ̂Ղ�

	//��ڂ̂Ղ�̈ʒu����ڂɑ΂��ăI�t�Z�b�g
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

