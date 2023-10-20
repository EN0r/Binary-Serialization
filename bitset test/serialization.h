#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

// binary serialization
class serialization
{
public:
	
	std::vector<std::bitset<8> > convertToBinary(std::string data);
	std::string convert_S(std::vector<std::bitset<8>> bitsetArray);
private:
	std::vector<char> sz_List;
	inline void setDataList(std::string data) {
		for (auto i = 0; i < data.size(); i++)
			this->sz_List.push_back(data[i]);
	}
	inline char bitsetToChar(std::bitset<8> character) {return static_cast<unsigned char>(character.to_ulong());}
};
