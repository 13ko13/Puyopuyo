#pragma once
#include "Vec2.h"

class Puzzle
{
public:
	Puzzle();
	~Puzzle();

	void Init(int handle);
	void End();
	void Update();
	void Draw();

	void SetPosition(int nx, int ny);	//�Ղ�̃|�W�V�������L��

private:
	//�n���h���֌W
	int m_handle;	//�O���t�B�b�N�n���h��
	
	//�Ղ�̐F
	int m_color;		//�FID(0 = ��,1 = ��, 2 = ��, 3 = ��)

	//�A�j���[�V�����֌W
	int m_animFrame;	//���݂̃A�j���[�V�������

	//�t���O�֌W
	bool m_alive;			//���݂��Ă��邩

	//�C���X�^���X
	Vec2 m_pos;			//�ʒu
	Vec2 m_velocity;	//���x
};

