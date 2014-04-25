// File:   IndexHandler.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "IndexHandler.h"
#include <iostream>


IndexHandler::IndexHandler(bool check)
{
    // determine which structure to use
    if(check == true)
    {
        Index = new AVLTree;
    }
    else
    {
        Index = new HashTable(500000);
    }
}



IndexHandler::~IndexHandler()
{
    //Index->saveData();
}


void IndexHandler::newFile(string title, int day, int month, int year, string author, string File)
{

    // record what file you are currently on
    currentAuthor = author;
    currentDay = day;
    currentMonth = month;
    currentYear = year;
    currentTitle = title;
    currentFile = File;


}

void IndexHandler::addWord(string word)
{

    // create document and add to structure allong with word
    DocumentStorage * temp;
    temp = new DocumentStorage(currentTitle, currentDay, currentMonth, currentYear, currentAuthor, currentFile);

    Index->add(word, temp);

}

vector<DocumentStorage> IndexHandler::search(string word)
{
    // use the structures search function to find data for word
    vector<DocumentStorage> holder;
    holder = Index->search(word);

    return holder;
}

void IndexHandler::buildIndexFromFile(int& count)
{
    // call load
    Index->loadData(count);
}
void IndexHandler::clearIndex()
{
    // call dump
    Index->dumpData();
}
void IndexHandler::saveIndex(int count)
{
    // save
    Index->saveData(count);
}
