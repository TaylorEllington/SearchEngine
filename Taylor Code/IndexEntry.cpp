
// File:   IndexEntry.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "IndexEntry.h"

IndexEntry::IndexEntry() {
}

IndexEntry::IndexEntry(const IndexEntry& orig) {
}

IndexEntry::~IndexEntry() {
}

void IndexEntry::addDocument(Document * index) {
    
    
    bool check = false;
    for (int z = 0; z < Documents.size(); z++) {

        
        if (Documents.at(z).getTitle() == index->getTitle()) {
            Documents.at(z).count++;
            check = true;
            
            break;
            
        }



    }
    if(check == false){
        cout <<"lulz"<< index->getAuthor() << endl;
    Documents.push_back(*index);
    }
}

void IndexEntry::setWord(string newWord) {
    word = newWord;
}

vector<Document> IndexEntry::getDocuments() {
    
    return Documents;
}

string IndexEntry::getWord() {
    return word;
}

