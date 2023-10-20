// bitset test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fileSystem.h"
int main()
{
    //const char* c = "Hello world";

    const char* data = "./data.bin";
    std::vector<std::string> a = { "Width = 100;","Height = 100;","Size = 100;" };

    fileSystem::getFileSystem()->open(data);


    for (auto str : a)
    {
        fileSystem::getFileSystem()->writeData_B(str);
    }
            
    std::cout << fileSystem::getFileSystem()->readData_B(true) << std::endl;


    return 0;
}