#pragma once
#include "PuzzlePair.h"
#include "Field.h"

class Puzzle;
class PuzzlePair;

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
	//インスタンス
	Puzzle* m_pPuzzle;
	PuzzlePair* m_pPuzzlePair;
	Field m_field;
};

