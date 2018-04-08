//
// Created by Imran Thompson on 8/4/18.
//
#include <iomanip>
#include "HexBlock.h"
HexBlock::HexBlock() : fBuffer(), fSize(0) {}

std::istream& HexBlock::read(std::istream &aIStream)
{
    aIStream.read((char*) fBuffer, 16);
    fSize = aIStream.gcount();
}

unsigned long HexBlock::size() const
{
    return fSize;
}