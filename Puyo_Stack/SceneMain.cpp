#include "SceneMain.h"
#include "Player.h"
#include "Puzzle.h"
#include "Game.h"
#include "DxLib.h"

//��邱��
//�p�Y���̐؂蔲�����

SceneMain::SceneMain() :
	m_pPuzzle(nullptr)
{
	
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_pPuzzle = new Puzzle();
	m_pPuzzle->Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPuzzle->Update();
}

void SceneMain::Draw()
{
	m_pPuzzle->Draw();
}
