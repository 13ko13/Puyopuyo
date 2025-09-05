#include "Puzzle.h"
#include "DxLib.h"

namespace
{
	// �萔��`
	constexpr int kPuzzleWidth = 80;	//�Ղ�1�̉���
	constexpr int kPuzzleHeight = 72;	//�Ղ�1�̍���
	constexpr float kPuzzleSize = 1.5f;
	constexpr int kAnimNum = 7;		//�A�j���[�V������
	constexpr int kAnimWaitFrame = 6;	//�A�j���[�V�����̑��x
	constexpr int kColors = 4;			//�F�̐�
	constexpr float kGravity = 2.0f;		//�d��
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
	// �K�v�Ȃ烊�\�[�X���
}

void Puzzle::Init()
{
	m_pos = kFirstPos;
	m_color = GetRand(kColors - 1);	//�����_���F
	m_alive = true;

	//�O���t�B�b�N�̃��[�h
	m_graphHandle = LoadGraph("data/Slime_Idle.png");
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
		kPuzzleWidth, kPuzzleHeight,
		kPuzzleSize, 0,
		m_graphHandle, true
	);
}
