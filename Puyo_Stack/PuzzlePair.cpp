#include "PuzzlePair.h"
#include "Puzzle.h"
#include "Pad.h"
#include "DxLib.h"

namespace
{
	constexpr int kPuzzleSize = 25;	//�Ղ�1�̍���
}

PuzzlePair::PuzzlePair() :
	m_offset(0.0f, -kPuzzleSize)
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

	if(Pad::IsTrigger(PAD_INPUT_X))
	{
		RotateRight();
	}
	
	if(Pad::IsTrigger(PAD_INPUT_Y) || 
		Pad::IsTrigger(PAD_INPUT_1))
	{
		RotateLeft();
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

void PuzzlePair::RotateRight()	//�E��]
{
	m_rotation = static_cast<Rotation>(
		(static_cast<int>(m_rotation) + 1) %	//int�^�ɕϊ�����0~3�͈̔͂ɂ���
		static_cast<int>(Rotation::Count));

	//�q�Ղ�̈ʒu�X�V
	UpdateChildPos();
}

void PuzzlePair::RotateLeft()	//����]
{
	m_rotation = static_cast<Rotation>(
		(static_cast<int>(m_rotation) - 1 +
			static_cast<int>(Rotation::Count)) %	//int�^�ɕϊ�����0~3�͈̔͂ɂ���
		static_cast<int>(Rotation::Count));

	//�q�Ղ�̈ʒu�X�V
	UpdateChildPos();
}

void PuzzlePair::UpdateChildPos()	//2�ڂ̂Ղ�̈ʒu�X�V
{
	static const Vec2 offsets[] = {
		{ 0.0f, -kPuzzleSize},	//Up
		{ kPuzzleSize, 0.0f },	//Right
		{ 0.0f, kPuzzleSize },	//Down
		{ -kPuzzleSize, 0.0f}		//Left
	};

	Vec2 parentPos = m_puzzles[0].GetPos();
	Vec2 offset = offsets[static_cast<int>(m_rotation)];
	m_puzzles[1].SetPos(parentPos + offset);
}

