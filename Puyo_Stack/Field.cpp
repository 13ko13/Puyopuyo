#include "Field.h"
#include "DxLib.h"

namespace
{
	// �萔��`
	constexpr int kGridSize = 26;		  //�O���b�h1�}�X�̑傫��
}

Field::Field()
{
}

Field::~Field()
{
}

void Field::Init()
{
	for (int y = 0; y < field::kFieldHeight; ++y)
	{
		for (int x = 0; x < field::kFieldWidth; ++x)
		{
			m_grid[y][x].Init();
			m_grid[y][x].SetAlive(false); //�ŏ��͑S�ċ�ɂ���
		}
	}
}

void Field::End()
{
}

void Field::Update()
{
	for(int y = 0; y < field::kFieldHeight; ++y)
	{
		for(int x = 0; x < field::kFieldWidth; ++x)
		{
			m_grid[y][x].Update();
		}
	}
}

void Field::Draw()
{
	for (int y = 0; y < field::kFieldHeight; ++y)
	{
		for(int x = 0; x < field::kFieldWidth; ++x)
		{
			int px = x * kGridSize;
			int py = y * kGridSize;

			//�O���b�h�g����`��
			DrawBox(px, py, px +kGridSize, py + kGridSize, GetColor(200, 200, 200), false);

			Vec2 drawPos = Vec2(x * 25.0f, y + 25.0f); //�Ղ�T�C�Y�ɍ��킹�Ē���
			m_grid[y][x].SetPos(drawPos);
			m_grid[y][x].Draw();
		}
	}
}

void Field::SetPuzzle(int x, int y, const Puzzle& puzzle)
{
	if(x < 0 || x >= field::kFieldWidth || y < 0 || y >= field::kFieldHeight)
	{
		return;
	}

	m_grid[y][x] = puzzle;
}

Puzzle& Field::GetPuzzle(int x, int y)
{
	return m_grid[y][x];	//�͈͊O�A�N�Z�X�͌Ăяo�����Œ���
}

