#pragma once
#include <string>

class TextureConverter
{
public:
	//コンストラクタ
	TextureConverter();

	//デストラクタ
	~TextureConverter();

	//テクスチャをWICからDDSに変換する
	void ConvertTextureWICToDDS(const std::string& filePath);

	//マルチバイト文字列をワイド文字列に変換
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const std::string& filePath);
};

