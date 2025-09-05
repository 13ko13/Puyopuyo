#include "Puzzle.h"
#include "Vec2.h"
#include "DxLib.h"

namespace
{
	//�O���t�B�b�N���
	constexpr float kPuzzleWidth = 80.0f;
	constexpr float kPuzzleHeight = 72.0f;
	constexpr float kPuzzleExRate = 2;
	//�p�Y�����
	const Vec2 kFirstPos = { 100.0f,100.0f }; //�����ʒu
	const Vec2 kVelocity = { 3.0f,3.0f };	  //���x
	//�d��
	constexpr float kGravity = 3.0f;
	//�A�j���[�V�������
	constexpr int kAnimWaitFrame = 5;	//�A�j���[�V�����̑��x
	constexpr int kAnimMax = 7;			//�A�j���[�V�����̖���
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
	//�A�j���[�V�������X�V
	m_animFrame++;
	if (m_animFrame >= kAnimMax * kAnimWaitFrame)
	{
		m_animFrame = 0;
	}
	
	//�d�͂�ǉ�
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