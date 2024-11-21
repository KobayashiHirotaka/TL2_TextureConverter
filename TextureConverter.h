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
	void ConvertTextureWICToDDS(const std::string& filePath,
		int numOptions = 0, char* options[] = nullptr);

	//�}���`�o�C�g����������C�h������ɕϊ�
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//�g�p���@���o��(�\��)����
	static void OutputUsage();

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�t�H���_�p�X�ƃt�@�C�����𕪗�����
	void SeparateFilePath(const std::wstring& filePath);

	//DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	void SaveDDSTextureToFile(int numOptions, char* options[]);

private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;

	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;

	//�t�@�C����
	std::wstring fileName_;

	//�t�@�C���g���q
	std::wstring fileExt_;
};

