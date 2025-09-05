#include "SceneMain.h"
#include "Player.h"
#include "Puzzle.h"
#include "Game.h"
#include "DxLib.h"

//‚â‚é‚±‚Æ
//ƒpƒYƒ‹‚ÌØ‚è”²‚«ì‹Æ

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
