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

private:
	//�n���h���֌W
	int m_handle;	//�O���t�B�b�N�n���h��

	//�C���X�^���X
	Vec2 m_pos;			//�ʒu
	Vec2 m_velocity;	//���x
};

