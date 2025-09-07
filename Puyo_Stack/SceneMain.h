#pragma once
#include "PuzzlePair.h"
#include "Field.h"

class Puzzle;

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	//�C���X�^���X
	Puzzle* m_pPuzzle;
	PuzzlePair m_puzzlePair;
	Field m_field;
};

