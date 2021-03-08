#include "StaticLib.h"

#include <fstream>
#include <iostream>

const char* _TempText1 = "ABCDEFG";
const char* _TempText2 = "ABCDEFGH";

int __stdcall WriteText(const char* fileName, const char* text)
{
	std::ofstream stream(fileName, std::ios::binary);

	if (!stream.is_open())
	{
		std::cout << fileName << " 파일을 생성하는데 실패했습니다." << std::endl;
		return -1;
	}

	stream << text;
	stream.close();

	std::cout << fileName << " 파일을 성공적으로 저장하였습니다." << std::endl;
	return 0;
}


// basic stream open mode 정리
// https://en.cppreference.com/w/cpp/io/ios_base/openmode

// app		seek to the end of stream before each write
// binary	open in binary mode
// in		open for reading
// out		open for writing
// trunc	discard the contents of the stream when opening
// ate		seek to the end of stream immediately after open


int __stdcall ReadText(const char* fileName, char* text)
{
	std::ifstream stream(fileName, std::ios::binary | std::ios::ate);
	__int64 fileSize = stream.tellg();
	stream.seekg(0, std::ios::beg);

	if (!stream.is_open())
	{
		std::cout << fileName << " 파일을 여는데 실패했습니다." << std::endl;
		return -1;
	}

	while (!stream.eof())
		stream.read(text++, 1);
	stream.close();

	std::cout << fileName << " 파일을 성공적으로 읽었습니다." << std::endl;
	return 0;

}