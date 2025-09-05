#pragma once

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
	//インスタンス
	Puzzle* m_pPuzzle;
};

