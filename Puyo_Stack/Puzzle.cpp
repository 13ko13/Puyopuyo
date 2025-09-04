#include "Puzzle.h"
#include "Vec2.h"
#include "DxLib.h"

namespace
{
	//グラフィック情報
	constexpr float kPuzzleWidth = 80.0f;
	constexpr float kPuzzleHeight = 72.0f;
	//パズル情報
	const Vec2 kFirstPos = { 100.0f,100.0f }; //初期位置
	const Vec2 kVelocity = { 3.0f,3.0f };	  //速度
	//重力
	constexpr float kGravity = 3.0f;
}

Puzzle::Puzzle() :
	m_handle(-1),
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
	m_pos = kFirstPos;
	m_velocity = kVelocity;
}

void Puzzle::End()
{

}

void Puzzle::Update()
{
	m_pos.y += kGravity;
}

void Puzzle::Draw()
{
	DrawRectRotaGraph(
		static_cast<int>(m_pos.x),
		static_cast<int>(m_pos.y),
		1, 0,
		m_handle, true
	);
}