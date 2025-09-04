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
	//ハンドル関係
	int m_puzzleGraphHandle;		//パズルのグラフィックハンドル

	//インスタンス
	Puzzle* m_pPuzzle;
};

