#pragma once
#include <string>

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
};

