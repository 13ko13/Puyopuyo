#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	//画面の大きさ
	int constexpr kScreenWidth = 1280;
	int constexpr kScreenHeight = 720;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	//ウィンドウの解像度を設定
	SetGraphMode(kScreenWidth, kScreenHeight,0);

	//ウィンドウ名にゲーム名を設定
	SetMainWindowText("Puyo Stack");

	//ウィンドウのサイズを変更可能にする
	SetWindowSizeChangeEnableFlag(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	SceneMain* pSceneMain = new SceneMain();
	pSceneMain->Init();

	while (ProcessMessage() == 0)
	{
		//このフレームの開始時間を取得
		LONGLONG start = GetNowHiPerformanceCount();

		//画面をクリア
		ClearDrawScreen();

		//ESCキーが押されたらウィンドウを閉じる
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//ここにゲームの処理などを書く
		pSceneMain->Update();

		//描画
		pSceneMain->Draw();

		//裏画面の内容を表画面に反映
		ScreenFlip();

		//フレームレートを60に固定
		while (GetNowHiPerformanceCount() - start < 16667)
		{

		}

		//ESCキーが押されたらウィンドウを閉じる
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//メモリ上のグラフィックを開放


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}