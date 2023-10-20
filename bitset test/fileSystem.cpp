#include "fileSystem.h"
fileSystem* fileSystem::fSystem = nullptr;
fileSystem::fileSystem() {}

/*


*/

// binary conversion
std::vector<std::bitset<8> > fileSystem::convertToBinary(std::string data) // convert string to binary -- embedded the data list
{
	std::vector<std::bitset<8> > retBuffer;
	std::vector<char> dataList;
	for (auto i = 0; i < data.size(); i++)
		dataList.push_back(data[i]);

	for (auto i = 0; i < dataList.size(); i++)
	{
		std::bitset<8> bitsetBuffer = dataList[i];
		retBuffer.push_back(bitsetBuffer);
	}
	return retBuffer;
}

std::string fileSystem::convert_S(std::vector<std::bitset<8>> bitsetArray) // convert binary to string requires a bitset
{
	std::string bufferString;
	for (auto i = 0; i < bitsetArray.size(); i++)
	{
		char currentChar = static_cast<unsigned char>(bitsetArray[i].to_ulong());
		bufferString.push_back(currentChar);
	}
	return bufferString;
}

// file system stuff - 
fileSystem* fileSystem::getFileSystem()
{
	if (fSystem != nullptr)
		return fSystem;
	else
	{
		fSystem = new fileSystem;
		return fSystem;
	}
	return nullptr;
}


bool fileSystem::open(const char* targetFile, unsigned int flags)
{
	this->cFile = targetFile;
	if (flags == OPEN_BINARY)
	{
		// set fstream flag to binary code.
		this->fileStream.open(targetFile, std::ios::in | std::ios::out | std::ios::binary | std::ios_base::app);
		if (this->fileStream.is_open())
			return true;
		else {
			std::cout << "File cannot be found or cannot be loaded: " << targetFile << std::endl;
			return false;
		}
	}
	else {
		this->fileStream.open(targetFile);
		if (this->fileStream.is_open())
			return true;
		else {
			std::cout << "File cannot be found or cannot be loaded: " << targetFile << std::endl;
			return false;
		}
	}
}

bool fileSystem::close()
{
	if (this->fileStream.is_open())
	{
		fileStream.close();
		return false;
	}
	else {
		std::cout << "No file was open!" << std::endl;
	}
}

bool fileSystem::convertBIN()
{
	return false;
}

void fileSystem::writeData_B(std::string str)
{
	unsigned int count = 0;
	if (!fileStream.is_open())
		open(cFile);
	if (fileStream.is_open())
	{
		std::vector<std::bitset<8>> rawDataBuffer = this->convertToBinary(str);
		if (rawDataBuffer.size() > 0) // check if buffer has elements inside.
		{
			for (auto i = 0; i < rawDataBuffer.size(); i++)
			{
				if (i == count) {
					count++;
					fileStream << rawDataBuffer[i] << "\n";
				}
			}
		}
		else {
			std::cout << "No raw data!!" << std::endl;
		}
	}
	fileStream.close();
}

std::string fileSystem::readData_B(bool useSeparator)
{
	// create bitset buffer for reading bitset
	std::vector<std::bitset<8>> bitsetVecBuffer;
	std::bitset<8> bitsetBuffer;
	std::string strBuf;
	std::string totalString;
	std::vector<int> separatorPositions;
	int index = 0;
	if(!fileStream.is_open())
		open(cFile);
	while (std::getline(fileStream, strBuf))
	{
		bitsetVecBuffer.push_back(static_cast<std::bitset<8>>(strBuf));
	}
	totalString = this->convert_S(bitsetVecBuffer);
	if (useSeparator)
	{
		for (auto i = 0; i < totalString.size(); i++)
		{
			if (totalString[i] == newLineSeparator)
			{
				separatorPositions.push_back(i);
			}
		}
		for (auto INT : separatorPositions)
		{
			totalString[INT] = '\n';

		}
	}
	close();
	return totalString;
}
