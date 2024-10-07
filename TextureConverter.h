#pragma once
#include <string>

class TextureConverter
{
public:
	TextureConverter();

	~TextureConverter();

	void ConvertTextureWICToDDS(const std::string& filePath);

private:

};

