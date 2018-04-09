//
// Created by Imran Thompson on 8/4/18.
//
#include <iomanip>
#include "HexBlock.h"

using namespace std;

HexBlock::HexBlock() : fBuffer(), fSize(0) {}

// file read function
istream& HexBlock::read(istream &aIStream)
{

    aIStream.read( (char*)this->fBuffer, 16);

    this->fSize = aIStream.gcount();
    return aIStream;
}

// returns size of last "block"
unsigned long HexBlock::size() const { return fSize; }

// overloaded output stream for printing the raw contents of the file
ostream &operator<<(ostream &aOStream, const HexBlock &aObject)
{
    // Part 2 of the output.
    for(int i = 0; i < aObject.size(); i++)
    {
        // if we're halfway, add the pipe-character-symbol thingy...
        if (i == 8) aOStream << " | ";

        // each character is manipulated and printed here.
        aOStream << setw(2) << setfill('0') << uppercase << hex << (int) aObject.fBuffer[i];

        // add space character between objects.
        if (i < aObject.size() && i != 7) aOStream << " ";
    }

    // Attempted getting the output to line up... not so great over different files
    aOStream << setfill(' ');
    aOStream << (aObject.size() == 16 ? setw(4) : setw(16 * 3 - aObject.size() - 2));

    // Part 3 of the output
    for(int i = 0; i < aObject.size(); i++)
        aOStream << (isgraph((int)aObject.fBuffer[i]) ? (char) aObject.fBuffer[i] : '.');

    return aOStream;
}
