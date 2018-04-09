//
// Created by Imran Thompson on 8/4/18.
//

#include <iomanip>
#include <iostream>

#include "HexDump.h"

// Process the file
void HexDump::processInput()
{
    // local variable to maintain position (offset) in file.
    int lPosition = 0;
    // do while loops through each 16 byte block and prints the hex dump to the screen
    do {
        this->fData.read(fInput);

        std::cout << std::setw(8) << std::setfill('0') << std::hex << lPosition << ":\t";

        std::cout << this->fData << std::endl;

        lPosition += this->fData.size();

    } while ( this->fData.size() == 16 );

    this->close();
}

// overloaded () operator
bool HexDump::operator()(const std::string& aInputFileName)
{
    if(this->open(aInputFileName))
    {
        this->processInput();
        this->close();
        return true;
    }

    this->close();
    return false;
}

// file open function
bool HexDump::open(const std::string& aInputFileName)
{
    fInput.open(aInputFileName, std::ios_base::binary | std::ios_base::in);

    if(!fInput.is_open())
    {
        std::cerr << aInputFileName << " could not be opened..." << std::endl;
        this->close();
        return false;
    }

    return true;
}

// file close function
void HexDump::close()
{
    this->fInput.clear();
    this->fInput.close();
}
