#pragma once
#include <string>
#include "externals/DirectXTex/DirectXTex.h"

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

private:
	//画像の情報
	DirectX::TexMetadata metaData_;

	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
};

