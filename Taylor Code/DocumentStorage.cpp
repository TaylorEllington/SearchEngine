/* 
 * File:   Document.cpp
 * Author: Nick Morris
 * Part of Search Engine project
 * Created on April 18, 2013, 3:48 PM
 */
#include <string>

#include "DocumentStorage.h"

using namespace std;

//Document default constructor -- sets all private variables to NULL
Document::Document() {
    setTitle(NULL);
    setDate(0 , 0, 0);
    count = 1;
    
}

//main constructor
Document::Document(std::string title, int day, int month, int year , std::string author){
    setTitle(title);
    setDate(day, month, year);
    setAuthor(author);
    count = 0;
   
}
void Document::setAuthor(std::string auth){
    documentAuthor = auth;
}

string Document::getAuthor(){
    cout <<"HERP " << documentAuthor << endl;
    return documentAuthor;
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
void Document::setDate(int day, int month, int year){
    date.setDate(day, month, year);
   
}
DateStamp Document::getDate(){
    return date;
}


//returns the title of the document
string Document::getTitle(){
    return documentTitle;
}


