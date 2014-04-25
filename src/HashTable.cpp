// File:   HashTable.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "HashTable.h"

#include <iostream>
#include <sstream>

HashTable::HashTable(int buckets)
{
    bucketCount = buckets;
    Table = new Bucket[buckets];

}

void HashTable::add(string word, DocumentStorage * & document)
{

    // gets hash value for word
    int tableIndex = hash(word);


    // check table[tableIndex] for word
    for (int z = 0; z < Table[tableIndex].contents.size(); z++)
    {
        if (word == Table[tableIndex].contents[z].getWord())
        {
            // if found add document
            Table[tableIndex].contents[z].addDocument(document);
            return;
        }

    }
    // if not found add new index entry
    IndexEntry * temp;
    temp = new IndexEntry;
    temp->setWord(word);
    temp->addDocument(document);

    Table[tableIndex].contents.push_back(*temp);

}

vector<DocumentStorage> HashTable::search(string term)
{
    // use hash to look up term in structure
    int tableIndex;
    int z = -1;

    tableIndex = hash(term);

    for (int x = 0; x < Table[tableIndex].contents.size(); x++)
    {
        // if term exists return data
        if (Table[tableIndex].contents[x].getWord() == term)
            return Table[tableIndex].contents[x].getDocuments();
    }
    // if term is not there then return empyt
    vector<DocumentStorage> failcase;
    return failcase;


}

void HashTable::dumpData()
{
    // remove all data
    for(int z = 0; z <bucketCount; z++)
    {
        Table[z].contents.clear();
    }

}

void HashTable::saveData(int count)
{

    // saves information to file
    ofstream saveFile;
    saveFile.open("INDEXFILE.save");
    DateStamp tempStamp;

    for (int TableIndex = 0; TableIndex < bucketCount; TableIndex++)
    {
        for (int z = 0; z < Table[TableIndex].contents.size(); z++)
        {
            saveFile << Table[TableIndex].contents.at(z).getWord() << endl;

            for (int x = 0; x < Table[TableIndex].contents.at(z).getDocuments().size(); x++)
            {

                tempStamp = Table[TableIndex].contents.at(z).getDocuments().at(x).getDate();

                saveFile << "<" << Table[TableIndex].contents.at(z).getDocuments().at(x).getTitle();
                saveFile << "|" << Table[TableIndex].contents.at(z).getDocuments().at(x).getAuthor();
                saveFile << "|" << tempStamp;
                saveFile << "|" << Table[TableIndex].contents.at(z).getDocuments().at(x).getFileName();
                saveFile << "|" << Table[TableIndex].contents.at(z).getDocuments().at(x).count;
                saveFile << ">\n";

            }
        }




    }
    saveFile<<"FileCount For System: "<<count<<endl;

}

void HashTable::loadData(int& counter)
{


    // loads from file and uses add to fill table
    ifstream saveFile;
    saveFile.open("INDEXFILE.save");

    string temp;
    string currentWord;
    string author;
    string title;
    string filePath;
    string day;
    string month;
    string year;
    string count;

    int prePos;
    int postPos;

    while (saveFile.good())
    {
        getline(saveFile, temp);
        if (temp[0] == '<')
        {
            // extract all doc data
            prePos = 1;
            postPos = temp.find('|', prePos);
            title = temp.substr(prePos, postPos - prePos);


            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            author = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('/', prePos);
            month = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('/', prePos);
            day = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            year = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            filePath = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('>', prePos);
            count = temp.substr(prePos, postPos - prePos);

            DocumentStorage * tempDocument;
            tempDocument = new DocumentStorage(title, atoi(day.c_str()), atoi(month.c_str()),
                                               atoi(year.c_str()), author, filePath);

            for (int i = 0; i < atoi(count.c_str()); i++)
            {

                add(currentWord, tempDocument);
            };

        }
        else if (temp[0] == 'F' && temp[4] == 'C')
        {
            stringstream ss;
            ss<<temp.substr(22,15);
            ss >> counter;

        }
        else
        {

            currentWord = temp;
        }

    }



}

HashTable::~HashTable()
{

}

int HashTable::hash(string word)
{

    // generate a number that will allow for indexing of word
    int hashValue = bucketCount/2;

    for (int z = 0; z < word.size(); z++)
    {
        hashValue = hashValue + (word[z] * 250 ) + 867214;
    }

    hashValue = hashValue % bucketCount;

    if (hashValue < 0)
        hashValue = -hashValue;

    return hashValue;

}
