#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include <Windows.h>

//�R�}���h���C������
enum Argument
{
	kApplicationPath,
	kFilePath,
	NumArgument
};

int main(int argc, char* argv[])
{
	//�R�}���h���C�������w��Ȃ�
	if (argc < NumArgument)
	{
		//�g������\������
		TextureConverter::OutputUsage();
		return 0;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//�e�N�X�`���R���o�[�^�[
	TextureConverter converter;

	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;

	//�I�v�V�����z��(�_�u���|�C���^)
	char** options = argv + NumArgument;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();

	//system("pause");

	return 0;
}