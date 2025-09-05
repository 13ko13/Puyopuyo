#include "Puzzle.h"
#include "DxLib.h"

namespace
{
	// 定数定義
	constexpr int kPuzzleWidth = 80;	//ぷよ1個の横幅
	constexpr int kPuzzleHeight = 72;	//ぷよ1個の高さ
	constexpr float kPuzzleSize = 1.5f;
	constexpr int kAnimNum = 7;		//アニメーション個数
	constexpr int kAnimWaitFrame = 6;	//アニメーションの速度
	constexpr int kColors = 4;			//色の数
	constexpr float kGravity = 2.0f;		//重力
	const Vec2 kFirstPos = { 200.0f,100.0f };
}

Puzzle::Puzzle() :
	m_graphHandle(-1),
	m_pos(0.0f, 0.0f),
	m_color(0),
	m_alive(false),
	m_animFrame(0),
	m_animCounter(0)
{
}

Puzzle::~Puzzle()
{
	// 必要ならリソース解放
}

void Puzzle::Init()
{
	m_pos = kFirstPos;
	m_color = GetRand(kColors - 1);	//ランダム色
	m_alive = true;

	//グラフィックのロード
	m_graphHandle = LoadGraph("data/Slime_Idle.png");
}

void Puzzle::Update()
{
	if (!m_alive) return;

	//アニメーション制御
	m_animFrame++;
	if (m_animFrame >= kAnimNum * kAnimWaitFrame)
	{
		m_animFrame = 0;
	}

	// 落下処理
	m_pos.y += kGravity;  // 下に落ちていく
}

void Puzzle::Draw()
{
	if (!m_alive) return;

	//表示したいコマ番号を計算
	int animNo = m_animFrame / kAnimWaitFrame;

	//グラフィックの切り取り位置を変更
	int srcX = kPuzzleWidth * animNo;
	int srcY = kPuzzleHeight * m_color;

	//ぷよの描画
	DrawRectRotaGraph(
		static_cast<int>(m_pos.x),
		static_cast<int>(m_pos.y),
		srcX, srcY,
		kPuzzleWidth, kPuzzleHeight,
		kPuzzleSize, 0,
		m_graphHandle, true
	);
}
