#include "Field.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	// �萔��`
	constexpr int kGridSize = 32;		  //�O���b�h1�}�X�̑傫��
	constexpr int kPuzzleSize = 32;		  //�Ղ�1�̑傫��
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
        for (int x = 0; x < field::kFieldWidth; ++x)
        {
            int px = (x * kGridSize) + Game::kScreenWidth * 0.4;
            int py = y * kGridSize - 35;

            // �O���b�h�g����`��
            DrawBox(px, py, px + kGridSize, py + kGridSize, GetColor(200, 200, 200), false);

            // �Ղ悪�����Ă���Ȃ�`��
            if (m_grid[y][x].IsAlive())
            {
				DrawGraph(x * kPuzzleSize, y * kPuzzleSize, m_grid[y][x].GetGraphHandle(), TRUE);
            }
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

