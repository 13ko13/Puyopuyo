#include "Puzzle.h"
#include "Vec2.h"
#include "DxLib.h"

namespace
{
	//グラフィック情報
	constexpr float kPuzzleWidth = 80.0f;
	constexpr float kPuzzleHeight = 72.0f;
	constexpr float kPuzzleExRate = 2;
	//パズル情報
	const Vec2 kFirstPos = { 100.0f,100.0f }; //初期位置
	const Vec2 kVelocity = { 3.0f,3.0f };	  //速度
	//重力
	constexpr float kGravity = 3.0f;
	//アニメーション情報
	constexpr int kAnimWaitFrame = 5;	//アニメーションの速度
	constexpr int kAnimMax = 7;			//アニメーションの枚数
}

Puzzle::Puzzle() :
	m_handle(-1),
	m_color(0),
	m_animFrame(0),
	m_alive(true),
	m_pos({ 0.0f,0.0f }),
	m_velocity({ 0.0f,0.0f })
{
}

Puzzle::~Puzzle()
{
}

void Puzzle::Init(int handle)
{
	m_handle = handle;
	m_animFrame = 0;
	m_pos = kFirstPos;
	m_velocity = kVelocity;
}

void Puzzle::End()
{

}

void Puzzle::Update()
{
	//アニメーションを更新
	m_animFrame++;
	if (m_animFrame >= kAnimMax * kAnimWaitFrame)
	{
		m_animFrame = 0;
	}
	
	//重力を追加
	m_pos.y += kGravity;
}

void Puzzle::Draw()
{
}

void Puzzle::SetPosition(int nx, int ny)
{
	m_pos.x = nx;
	m_pos.y = ny;
}