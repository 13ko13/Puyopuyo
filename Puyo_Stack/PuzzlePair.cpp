#include "PuzzlePair.h"
#include "Puzzle.h"
#include "Pad.h"
#include "DxLib.h"
#include "Field.h"

namespace
{
	constexpr int kPuzzleSize = 32;	//ぷよ1個の高さ
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

	if (Pad::IsTrigger(PAD_INPUT_X))
	{
		RotateRight();
	}

	if (Pad::IsTrigger(PAD_INPUT_Y) ||
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

bool PuzzlePair::CheckCollision(Field& field)
{
	for (int i = 0; i < 2; ++i)
	{
		Vec2 pos = m_puzzles[i].GetPos();
		int gridX = static_cast<int>(pos.x / kPuzzleSize);
		int gridY = static_cast<int>(pos.y / kPuzzleSize);

		//地面に到達or他のぷよがいる
		if (gridY >= field::kFieldHeight  || field.GetPuzzle(gridX, gridY).IsAlive())
		{
			return true;
		}
	}
	return false;
}

bool PuzzlePair::IsAlive() const
{
	return m_puzzles[0].IsAlive() || m_puzzles[1].IsAlive();
}

void PuzzlePair::RotateRight()	//右回転
{
	m_rotation = static_cast<Rotation>(
		(static_cast<int>(m_rotation) + 1) %	//int型に変換して0~3の範囲にする
		static_cast<int>(Rotation::Count));

	//子ぷよの位置更新
	UpdateChildPos();
}

void PuzzlePair::RotateLeft()	//左回転
{
	m_rotation = static_cast<Rotation>(
		(static_cast<int>(m_rotation) - 1 +
			static_cast<int>(Rotation::Count)) %	//int型に変換して0~3の範囲にする
		static_cast<int>(Rotation::Count));

	//子ぷよの位置更新
	UpdateChildPos();
}

void PuzzlePair::UpdateChildPos()	//2つ目のぷよの位置更新
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

void PuzzlePair::LandToField(Field& field) //フィールドに着地させる
{
	for (int i = 0; i < 2; ++i)
	{
		Vec2 pos = m_puzzles[i].GetPos();
		int gridX = static_cast<int>(pos.x / kPuzzleSize);
		int gridY = static_cast<int>(pos.y / kPuzzleSize);

		field.SetPuzzle(gridX, gridY, m_puzzles[i]);
		m_puzzles[i].SetAlive(false); //フィールドに置いたら操作ぷよは消す
	}
}

