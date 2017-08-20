#pragma once

#include <string>

//Header para InputFile
class InputFile {
public:
	bool Read(std::string filename);
	std::string GetContents();
private:
	std::string _contents;
};