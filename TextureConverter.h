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

	//フォルダパスとファイル名を分離する
	void SeparateFilePath(const std::wstring& filePath);

	//DDSテクスチャとしてファイル書き出し
	void SaveDDSTextureToFile();

private:
	//画像の情報
	DirectX::TexMetadata metadata_;

	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	//ディレクトリパス
	std::wstring directoryPath_;

	//ファイル名
	std::wstring fileName_;

	//ファイル拡張子
	std::wstring fileExt_;
};

