/*
 * File:   Document.cpp
 * Author: Nick Morris
 * Part of Search Engine project
 * Created on April 18, 2013, 3:48 PM
 */

#include <string>

#include "Document.h"

using namespace std;

//Document default constructor -- sets all private variables to NULL
Document::Document()
{
    setTitle(NULL);
    setDate(NULL);
    setText(NULL);
    setAuthor(NULL);
    isForgien = false;
}

//main constructor
Document::Document(string title, string date, string text, string author, string name)
{
    setTitle(title);
    setDate(date);
    setText(text);
    setAuthor(author);
    documentName = name;
    isForgien = false;
}

Document::~Document()
{
    documentTitle.clear();
    documentDate.clear();
    documentAuthor.clear();
    documentText.clear();
    documentName.clear();
}

//sets the title of the document
void Document::setTitle(string title)
{
    documentTitle = title;
}

//sets the date the document was written
void Document::setDate(string date)
{
    documentDate = date;
}

//sets the text contained within the document
void Document::setText(string text)
{
    documentText = text;
}

//returns the title of the document

void Document::setAuthor(string author)
{
    documentAuthor = author;
}
string Document::getTitle()
{
    return documentTitle;
}

//returns the date the document was written
string Document::getDate()
{
    return documentDate;
}

//returns the text contained within the document
string Document::getText()
{
    return documentText;
}

string Document::getAuthor()
{
    return documentAuthor;
}
