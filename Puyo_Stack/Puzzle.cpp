#include "Puzzle.h"
#include "DxLib.h"
#include "Game.h"
#include "Pad.h"

namespace
{
	// �萔��`
	constexpr int kPuzzleWidth = 80;		  //�Ղ�1�̉���
	constexpr int kPuzzleHeight = 72;		  //�Ղ�1�̍���
	constexpr float kPuzzleSize = 1.5f;		  //�Ղ�T�C�Y
	constexpr int kAnimNum = 7;			      //�A�j���[�V������
	constexpr int kAnimWaitFrame = 6;	      //�A�j���[�V�����̑��x
	constexpr int kColors = 4;			      //�F�̐�
	constexpr float kGravity = 2.0f;	      //�d��
	constexpr float kMoveHorizontal = 32.0f;  //���̈ړ���
	const Vec2 kFirstPos = { 200.0f,100.0f }; //�����ʒu
	const Vec2 kAccel = { 0.0f, 3.0f };    //�����x
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
	m_color = GetRand(kColors - 1);	//�����_���F
	m_alive = true;

	//�O���t�B�b�N�̃��[�h
	m_graphHandle = LoadGraph("data/Graphic/Slime_Idle.png");
}

void Puzzle::End()
{
	//�O���t�B�b�N�̊J��
	DeleteGraph(m_graphHandle);
}

void Puzzle::Update()
{
	if (!m_alive) return;

	//�A�j���[�V��������
	m_animFrame++;
	if (m_animFrame >= kAnimNum * kAnimWaitFrame)
	{
		m_animFrame = 0;
	}

	// ��������
	m_pos.y += kGravity;  // ���ɗ����Ă���

	//���E�ړ�����
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

	//�\���������R�}�ԍ����v�Z
	int animNo = m_animFrame / kAnimWaitFrame;

	//�O���t�B�b�N�̐؂���ʒu��ύX
	int srcX = kPuzzleWidth * animNo;
	int srcY = kPuzzleHeight * m_color;

	//�Ղ�̕`��
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
