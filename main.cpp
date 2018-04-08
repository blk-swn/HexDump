#include <iostream>
#include "HexDump.h"

using namespace std;

int main(int argc, char* argv)
{
    if ( argc != 2 )
    {
        cerr << "Error: Argument missing!" << endl;
        cerr << "Usage: HexDump filename" << endl;
        return 1;
    }
    HexDump lProcessor;
    // return 0 if success, otherwise 2 (could not open input file)
    return lProcessor( argv[1] ) ? 0 : 2;
}