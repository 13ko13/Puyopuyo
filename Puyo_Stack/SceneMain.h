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
	//�n���h���֌W
	int m_puzzleGraphHandle;		//�p�Y���̃O���t�B�b�N�n���h��

	//�C���X�^���X
	Puzzle* m_pPuzzle;
};

