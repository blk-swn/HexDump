//
// Created by Imran Thompson on 8/4/18.
//

#ifndef HEXDUMPA_HEXBLOCK_H
#define HEXDUMPA_HEXBLOCK_H


#include <fstream>

class HexBlock {
private:
    unsigned char fBuffer[16];
    unsigned long fSize;

public:
    HexBlock();

    // read up to 16 bytes (i.e. raw characters) into buffer
    // records the number of characters read in size (<= 16)
    std::istream& read(std::istream& aIStream);

    unsigned long size() const;

    // formatted output operator produces a hex dump line
    friend std::ostream& operator<<( std::ostream& aOStream, const HexBlock& aObject );
};


#endif //HEXDUMPA_HEXBLOCK_H
