#include "SceneMain.h"
#include "Player.h"
#include "Puzzle.h"
#include "Game.h"
#include "DxLib.h"

//��邱��
//�p�Y���̐؂蔲�����

SceneMain::SceneMain() :
	m_pPuzzle(nullptr),
	m_pPuzzlePair(nullptr)
{
}

SceneMain::~SceneMain()
{
	delete m_pPuzzle;
	delete m_pPuzzlePair;
}

void SceneMain::Init()
{
	m_pPuzzle = new Puzzle();
	m_pPuzzlePair = new PuzzlePair();
	m_pPuzzle->Init();
	m_pPuzzlePair->Init();
	m_field.Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPuzzle->Update();
	m_pPuzzlePair->Update();
	m_field.Update();

	//�Ղ�̓����蔻��
	if (m_pPuzzlePair->CheckCollision(m_field))
	{
		m_pPuzzlePair->LandToField(m_field);
		//m_pPuzzlePair->Init(); //�V�����y�A�𐶐�
	}
	
}

void SceneMain::Draw()
{
	m_pPuzzle->Draw();
	m_field.Draw();
	m_pPuzzlePair->Draw();
}
