#include "TextureConverter.h"
#include <Windows.h>

TextureConverter::TextureConverter()
{

}

TextureConverter::~TextureConverter()
{

}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	LoadWICTextureFromFile(filePath);
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド文字列に変換する
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);

	//WICテクスチャのロード
	HRESULT result = LoadFromWICFile(wFilePath.c_str(), DirectX::WIC_FLAGS_NONE, &metaData_, scratchImage_);
	assert(SUCCEEDED(result));
}