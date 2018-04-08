//
// Created by Imran Thompson on 8/4/18.
//

#include <iostream>
#include <iomanip>
#include "HexDump.h"

using namespace std;

bool HexDump::open(const std::string& aInputFileName)
{
    fInput.open(aInputFileName, std::ios_base::binary | std::ios_base::in);
    if(!fInput.is_open())
    {
        cerr << aInputFileName << " could not be opened..." << endl;
        this->close();
        return false;
    }

    return true;
}

void HexDump::close()
{
    fInput.clear();
    fInput.close();
}

void HexDump::processInput()
{
    int position = 0;
    do {

        fData.read(fInput);
        cout << setw(8) << setfill('0') << setbase(16) << position;
        cout << fData << endl;

        position += fData.size();

    } while(fData.size() == 16);
}

bool HexDump::operator()(const std::string& aInputFileName)
{
    if(open(aInputFileName))
    {
        processInput();
        return true;
    }
    return false;
}