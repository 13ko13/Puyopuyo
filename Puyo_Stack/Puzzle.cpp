#include "Puzzle.h"
#include "DxLib.h"
#include "Game.h"
#include "Pad.h"

namespace
{
	// 定数定義
	constexpr int kPuzzleWidth = 80;		  //ぷよ1個の横幅
	constexpr int kPuzzleHeight = 72;		  //ぷよ1個の高さ
	constexpr float kPuzzleSize = 1.5f;		  //ぷよサイズ
	constexpr int kAnimNum = 7;			      //アニメーション個数
	constexpr int kAnimWaitFrame = 6;	      //アニメーションの速度
	constexpr int kColors = 4;			      //色の数
	constexpr float kGravity = 2.0f;	      //重力
	constexpr float kMoveHorizontal = 32.0f;  //横の移動量
	const Vec2 kFirstPos = { 200.0f,100.0f }; //初期位置
	const Vec2 kAccel = { 0.0f, 3.0f };    //加速度
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
	
}

void Puzzle::Init()
{
	m_pos = kFirstPos;
	m_color = GetRand(kColors - 1);	//ランダム色
	m_alive = true;

	//グラフィックのロード
	m_graphHandle = LoadGraph("data/Graphic/Slime_Idle.png");
}

void Puzzle::End()
{
	//グラフィックの開放
	DeleteGraph(m_graphHandle);
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

	//左右移動処理
	if (Pad::IsTrigger(PAD_INPUT_LEFT))
	{
		m_pos.x -= kMoveHorizontal;
	}
	else if (Pad::IsTrigger(PAD_INPUT_RIGHT))
	{
		m_pos.x += kMoveHorizontal;
	}

	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		m_pos.y += kAccel.y;
	}
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
		kPuzzleWidth,
		kPuzzleHeight,
		kPuzzleSize, 0,
		m_graphHandle, true
	);
}

void Puzzle::SetPos(const Vec2& pos)
{
	m_pos = pos;
}

Vec2 Puzzle::GetPos() const
{
	return m_pos;
}
