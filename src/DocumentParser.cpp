#include <fstream>
#include <iostream>

#include "DocumentParser.h"
#include "XMLParser.h"

using namespace std;
DocumentParser::DocumentParser( int& count, IndexHandler*& index, string iFile)
{
    mainFilename = iFile;
    parseFile(count, index);
}

DocumentParser::~DocumentParser()
{
    mainFilename.clear();
}

void
DocumentParser::parseFile(int& count, IndexHandler*& index)
{
    // Creates an XMLParser object.
    XMLParser document (mainFilename, count, index);
}
