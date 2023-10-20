#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <memory>
#include <bitset>

enum FLAGS
{
	OPEN_BINARY = 1,
	READ_WORD = 2,
	READ_WHOLEFILE = 3
};

class fileSystem
{
public:
	// constructor - destructor
	fileSystem(const fileSystem& obj) = delete;
	~fileSystem() {close();}

	// main code
	static fileSystem* getFileSystem();
	const char* defaultFile = "./serialization/info.bin";
	char newLineSeparator = ';';
	inline void clearData() {fileStream.clear();}
	// functions for r/w data
	bool open(const char* targetFile, unsigned int flags = OPEN_BINARY);
	bool close();
	bool convertBIN();
	void writeData_B(std::string str); // writes data as binary to a .bin file.
	std::string readData_B(bool useSeparator = true);  // reads data from binary file and returns it as std::string



private:
	const char* cFile = "NULL";
	// binary conversion
	std::vector<std::bitset<8> > convertToBinary(std::string data);
	std::string convert_S(std::vector<std::bitset<8>> bitsetArray);

	// FileStream
	fileSystem();
	static fileSystem* fSystem;
	std::fstream fileStream;
	std::unordered_map<std::string, std::string> output; // make a hashmap for the input and output to read from and get information from
};