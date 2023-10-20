#include "serialization.h"
#include <string>
#include <bitset>

std::vector<std::bitset<8> > serialization::convertToBinary(std::string data)
{
	std::vector<std::bitset<8> > retBuffer;
	// set data list
	this->setDataList(data);

	for (auto i = 0; i < this->sz_List.size(); i++)
	{
		std::bitset<8> bitsetBuffer = sz_List[i];
		retBuffer.push_back(bitsetBuffer);
	}
	return retBuffer;
}

std::string serialization::convert_S(std::vector<std::bitset<8>> bitsetArray)
{
	std::string bufferString;
	for (auto i = 0; i < bitsetArray.size(); i++)
	{
		char currentChar = this->bitsetToChar(bitsetArray[i]);
		bufferString.push_back(currentChar);
	}
	return bufferString;
}
