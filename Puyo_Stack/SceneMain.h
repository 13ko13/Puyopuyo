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
	//�C���X�^���X
	Puzzle* m_pPuzzle;
};

