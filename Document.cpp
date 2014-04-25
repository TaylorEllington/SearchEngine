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
Document::Document() {
    setTitle(NULL);
    setDate(NULL);
    setText(NULL);
}

//main constructor
Document::Document(string title, string date, string text){
    setTitle(title);
    setDate(date);
    setText(text);
}

Document::Document(const Document& orig) {
}

Document::~Document() {
}

//sets the title of the document
void Document::setTitle(string title){
    documentTitle = title;
}

//sets the date the document was written
void Document::setDate(string date){
    documentDate = date;
}

//sets the text contained within the document
void Document::setText(string text){
    documentText = text;
}

//returns the title of the document
string Document::getTitle(){
    return documentTitle;
}

//returns the date the document was written
string Document::getDate(){
    return documentDate;
}

//returns the text contained within the document
string Document::getText(){
    return documentText;
}
