// File:   IndexEntry.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "IndexEntry.h"

IndexEntry::IndexEntry()
{
}



IndexEntry::~IndexEntry()
{
}

void IndexEntry::addDocument(DocumentStorage * & index)
{

    bool check = false;
    for (int z = 0; z < documents.size(); z++)
    {

        if (documents.at(z).getTitle() == index->getTitle())
        {
            documents.at(z).count++;
            check = true;

            break;

        }
    }
    if(check == false)
    {
        index->count = 1;
        documents.push_back(*index);

    }
}

void IndexEntry::setWord(string newWord)
{
    word = newWord;
}

vector<DocumentStorage> IndexEntry::getDocuments()
{

    return documents;
}

string IndexEntry::getWord()
{
    return word;
}

