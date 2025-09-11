#include "Field.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	// 定数定義
	constexpr int kGridSize = 32;		  //グリッド1マスの大きさ
	constexpr int kPuzzleSize = 32;		  //ぷよ1個の大きさ
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
			m_grid[y][x].SetAlive(false); //最初は全て空にする
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
			int px =( x * kGridSize ) + Game::kScreenWidth * 0.4;
			int py = y * kGridSize - 35 ;

			//グリッド枠線を描画
			//グリッド枠線を描画
			DrawBox(px, py, px +kGridSize, py + kGridSize, GetColor(200, 200, 200), false);

			Vec2 drawPos = Vec2(x * kPuzzleSize, y * kPuzzleSize); //ぷよサイズに合わせて調整
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
	return m_grid[y][x];	//範囲外アクセスは呼び出し元で注意
}

