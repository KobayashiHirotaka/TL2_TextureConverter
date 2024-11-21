#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include <Windows.h>

//コマンドライン引数
enum Argument
{
	kApplicationPath,
	kFilePath,
	NumArgument
};

int main(int argc, char* argv[])
{
	//コマンドライン引数指定なし
	if (argc < NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//テクスチャコンバーター
	TextureConverter converter;

	//オプションの数
	int numOptions = argc - NumArgument;

	//オプション配列(ダブルポインタ)
	char** options = argv + NumArgument;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();

	//system("pause");

	return 0;
}