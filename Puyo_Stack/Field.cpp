#include "Field.h"
#include "DxLib.h"

Field::Field()
{
}

Field::~Field()
{
}

void Field::Init()
{
	for (int y = 0; y < kFieldHeight; ++y)
	{
		for (int x = 0; x < kFieldWidth; ++x)
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
	for(int y = 0; y < kFieldHeight; ++y)
	{
		for(int x = 0; x < kFieldWidth; ++x)
		{
			m_grid[y][x].Update();
		}
	}
}

void Field::Draw()
{
	for (int y = 0; y < kFieldHeight; ++y)
	{
		for(int x = 0; x < kFieldWidth; ++x)
		{
			Vec2 drawPos = Vec2(x * 25.0f, y + 25.0f); //�Ղ�T�C�Y�ɍ��킹�Ē���
			m_grid[y][x].SetPos(drawPos);
			m_grid[y][x].Draw();
		}
	}
}

void Field::SetPuzzle(int x, int y, const Puzzle& puzzle)
{
	if(x < 0 || x >= kFieldWidth || y < 0 || y >= kFieldHeight)
	{
		return;
	}

	m_grid[y][x] = puzzle;
}

Puzzle& Field::GetPuzzle(int x, int y)
{
	return m_grid[y][x];	//�͈͊O�A�N�Z�X�͌Ăяo�����Œ���
}

