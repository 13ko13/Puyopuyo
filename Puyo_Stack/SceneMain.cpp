#include "SceneMain.h"
#include "Player.h"
#include "Puzzle.h"
#include "Game.h"
#include "DxLib.h"

//やること
//パズルの切り抜き作業

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

	//ぷよの当たり判定
	if (m_pPuzzlePair->CheckCollision(m_field))
	{
		m_pPuzzlePair->LandToField(m_field);
		//m_pPuzzlePair->Init(); //新しいペアを生成
	}
	
}

void SceneMain::Draw()
{
	m_pPuzzle->Draw();
	m_field.Draw();
	m_pPuzzlePair->Draw();
}
