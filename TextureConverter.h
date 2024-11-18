#pragma once
#include <string>
#include "externals/DirectXTex/DirectXTex.h"

class TextureConverter
{
public:
	//�R���X�g���N�^
	TextureConverter();

	//�f�X�g���N�^
	~TextureConverter();

	//�e�N�X�`����WIC����DDS�ɕϊ�����
	void ConvertTextureWICToDDS(const std::string& filePath);

	//�}���`�o�C�g����������C�h������ɕϊ�
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	//�摜�̏��
	DirectX::TexMetadata metaData_;

	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
};

