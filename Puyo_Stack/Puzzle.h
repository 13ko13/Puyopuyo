#pragma once
#include "Vec2.h"

class Puzzle
{
public:
    Puzzle();
    ~Puzzle();

    void Init();        // �������i�ʒu��F�̐ݒ�j
    void End();         //�I������
    void Update();      // �X�V����
    void Draw();        // �`�揈��

    bool IsAlive() const { return m_alive; }
    void SetAlive(bool flag) { m_alive = flag; }
    void SetPos(const Vec2& pos);
    Vec2 GetPos() const;
	int GetGraphHandle() const { return m_graphHandle; }

private:
    //�n���h���֌W
    int m_graphHandle;    // �摜�n���h��
    
    //�A�j���[�V�����֌W
    int m_animFrame;       //�A�j���[�V�����̂ǂ̕�����
    int m_animCounter;    //���݂̃A�j���[�V�����t���[��  

    //�F�֌W
    int m_color;          // �F�i0=��, 1=��, 2=��, �c�j

    //�t���O�֌W
    bool m_alive;         // �����t���O

    //�C���X�^���X
    Vec2 m_pos;           // ���W  
};
