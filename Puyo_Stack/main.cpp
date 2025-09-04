#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	//��ʂ̑傫��
	int constexpr kScreenWidth = 1280;
	int constexpr kScreenHeight = 720;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	//�E�B���h�E�̉𑜓x��ݒ�
	SetGraphMode(kScreenWidth, kScreenHeight,0);

	//�E�B���h�E���ɃQ�[������ݒ�
	SetMainWindowText("Puyo Stack");

	//�E�B���h�E�̃T�C�Y��ύX�\�ɂ���
	SetWindowSizeChangeEnableFlag(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	SceneMain* pSceneMain = new SceneMain();
	pSceneMain->Init();

	while (ProcessMessage() == 0)
	{
		//���̃t���[���̊J�n���Ԃ��擾
		LONGLONG start = GetNowHiPerformanceCount();

		//��ʂ��N���A
		ClearDrawScreen();

		//ESC�L�[�������ꂽ��E�B���h�E�����
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//�����ɃQ�[���̏����Ȃǂ�����
		pSceneMain->Update();

		//�`��
		pSceneMain->Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		//�t���[�����[�g��60�ɌŒ�
		while (GetNowHiPerformanceCount() - start < 16667)
		{

		}

		//ESC�L�[�������ꂽ��E�B���h�E�����
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//��������̃O���t�B�b�N���J��


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}