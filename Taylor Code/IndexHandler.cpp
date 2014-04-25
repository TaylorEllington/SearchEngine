
// File:   IndexHandler.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "IndexHandler.h"


IndexHandler::IndexHandler(bool check) {
    if(check == true){
        Index = new AVLTree;
    }else{
        //Index == new HashTable;
    }
}



IndexHandler::~IndexHandler() {
}


void IndexHandler::newFile(string title, int day, int month, int year, string author){
    currentAuthor = author;
    currentDay = day;
    currentMonth = month;
    currentYear = year;
    currentTitle = title;
    
}

void IndexHandler::addWord(string word){
    Document * temp;
    temp = new Document(currentTitle, currentDay, currentMonth, currentYear, currentAuthor);
    cout << temp->getAuthor()<< endl;
    
    Index->add(word, temp);
    
}

vector<Document> IndexHandler::search(string word){
    vector<Document> holder;
    holder = Index->search(word);
    
    return Index->search(word);
}


