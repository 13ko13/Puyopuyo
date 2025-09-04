#include "SceneMain.h"
#include "Player.h"
#include "Puzzle.h"
#include "Game.h"
#include "DxLib.h"

//やること
//パズルの切り抜き作業

SceneMain::SceneMain() :
	m_puzzleGraphHandle(-1),
	m_pPuzzle(nullptr)
{
	
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	//グラフィックのロード
	m_puzzleGraphHandle = LoadGraph("data/Slime_Idle.png");

	m_pPuzzle = new Puzzle();
	m_pPuzzle->Init(m_puzzleGraphHandle);
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
