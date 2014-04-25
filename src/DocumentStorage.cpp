/*
 * File:   Document.cpp
 * Author: Nick Morris
 * Part of Search Engine project
 * Created on April 18, 2013, 3:48 PM
 */
#include <string>

#include <iostream>

#include "DocumentStorage.h"

using namespace std;

//Document default constructor -- sets all private variables to NULL
DocumentStorage::DocumentStorage()
{
    setTitle(NULL);
    setDate(0 , 0, 0);
    count = 1;

}

//main constructor
DocumentStorage::DocumentStorage(std::string title, int day, int month, int year , std::string author, std::string fileName)
{
    setTitle(title);
    setDate(day, month, year);
    setAuthor(author);
    setFileName(fileName);
    count = 0;

}
void
DocumentStorage::setAuthor(std::string auth)
{
    documentAuthor = auth;
}

string
DocumentStorage::getAuthor()
{

    return documentAuthor;
}



DocumentStorage::~DocumentStorage()
{

}

//sets the title of the document
void
DocumentStorage::setTitle(string title)
{
    documentTitle = title;
}

//sets the date the document was written
void
DocumentStorage::setDate(int day, int month, int year)
{
    date.setDate(day, month, year);

}

DateStamp
DocumentStorage::getDate()
{
    return date;
}


//returns the title of the document
string
DocumentStorage::getTitle()
{
    return documentTitle;
}

void
DocumentStorage::setFileName(std::string a)
{
    fileName = a;
}

string
DocumentStorage::getFileName()
{
    return fileName;
}

void
DocumentStorage::display()
{
    cout<<"Title:\t"<<documentTitle<<endl;
    cout<<"Author:\t"<<documentAuthor<<endl;
    cout<<"Date:\t"<<date;
    cout<<endl;
}
