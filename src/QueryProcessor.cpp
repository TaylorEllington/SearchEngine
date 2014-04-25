// AUTHOR: Nick Morris
//         30632229
// FILENAME: QueryProcessor.cpp
// PURPOSE:
// FUNCTION:
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstring>
#include "DateStamp.h"
#include "QueryProcessor.hpp"
#include "IndexHandler.h"
#include "porter2_stemmer.h"

using namespace std;

QueryProcessor::QueryProcessor(string query, IndexHandler* i)
{
    //set the inQuery to the value of query

    setQuery(query);

    queryCapacity = 10;
    queryDocs = new vector<DocumentStorage>[queryCapacity];

    iHandler = i;

    queryCounter = 0;


    ss << inQuery;
}

QueryProcessor::~QueryProcessor()
{
    delete [] iHandler;
    delete [] queryDocs;
}

void QueryProcessor::setQuery(string query)
{
    inQuery = query;
}

vector<DocumentStorage> QueryProcessor::parseQuery()
{
    string temp;
    ss >> temp;
    if(temp == "AND")
    {
        return AND();
    }
    else if(temp == "OR")
    {
        return OR();
    }

    else if(temp == "USERNAME")
    {
        return USERNAME();
    }

    else if(temp == "DATEGT")
    {
        return DATEGT();
    }
    else if(temp == "DATELT")
    {
        return DATELT();
    }
    else
    {
        //simple search
        queries.push_back(temp);
        queryCounter++;
        return iHandler->search(Porter2Stemmer::stem(temp));

    }
}

vector<DocumentStorage> QueryProcessor::AND()
{
    string word;
    vector<DocumentStorage> tempVector;

    while(ss.good())
    {
        ss >> word;

        if((word!= "NOT") && (word != "DATEGT") && (word != "DATELT"))
        {
            queries.push_back(word);
            queryCounter++;
            queryDocs[queryCounter-1] = (iHandler->search(Porter2Stemmer::stem(word)));
        }
        else
        {
            break;
        }
        if(queryCounter == queryCapacity)
            resize();
    }
    for(int i = 0; i < queryCounter-1; i++)
    {
        for(int first = 0; first < queryDocs[i].size(); first++ )
        {
            for(int second = 0; second < queryDocs[i+1].size(); second++)
            {
                if(queryDocs[i][first].getFileName() == queryDocs[i+1][second].getFileName())
                {
                    tempVector.push_back(queryDocs[i][second]);
                }
            }
        }
        queryDocs[i+1].clear();
        queryDocs[i+1] = tempVector;
        tempVector.clear();
    }
    queryDocs->erase(queryDocs->begin(), queryDocs->begin()+ (queryCounter-1));
    if (word == "NOT")
    {
        return ANDNOT();
    }
    else if(word == "DATEGT")
    {
        return DATEGT();
    }
    else if(word == "DATELT")
    {
        return DATELT();
    }
    else
    {
        return queryDocs[queryCounter-1];
    }
}

vector<DocumentStorage> QueryProcessor::OR()
{
    vector<DocumentStorage> tempVector;

    string word;
    while(ss.good())
    {
        ss >> word;
        cout<<word<<endl;
        if((word != "AND") && (word != "OR") && (word!= "NOT") && (word != "DATEGT")
                && (word != "DATELT"))
        {
            queries.push_back(word);
            queryCounter++;
            queryDocs[queryCounter-1] = (iHandler->search(Porter2Stemmer::stem(word)));
        }
        else
            break;
        if(queryCounter == queryCapacity)
            resize();
    }
    for(int i = 0; i < queryCounter-1; i++)
    {
        for(int first = 0; first < queryDocs[i].size(); first++ )
        {
            for(int second = 0; second < queryDocs[i+1].size(); second++)
            {
                if(queryDocs[i][first].getFileName() != queryDocs[i+1][second].getFileName())
                {
                    tempVector.push_back(queryDocs[i][first]);
                }
            }
        }
        for(int second = 0; second < queryDocs[i+1].size(); second++)
        {
            tempVector.push_back(queryDocs[i+1][second]);
        }
        queryDocs[i+1].clear();
        queryDocs[i+1] = tempVector;
        tempVector.clear();
    }

    queryDocs->erase(queryDocs->begin(), queryDocs->begin()+ (queryCounter-1));

    if(word == "AND")
    {
        return AND();
    }

    if(word == "OR")
    {
        return OR();
    }

    if(word == "NOT")
    {
        return ANDNOT();
    }

    if(word == "DATEGT")
    {
        return DATEGT();
    }
    else if(word == "DATELT")
    {
        return DATELT();
    }
    else
    {
        return queryDocs[queryCounter-1];
    }
}

vector<DocumentStorage> QueryProcessor::ANDNOT()
{
    int currentQuery = queryCounter-1;
    string word;
    vector<DocumentStorage> tempVector;
    while(ss.good())
    {
        ss >> word;
        if((word != "AND") && (word != "OR") && (word!= "NOT") && (word != "DATEGT")
                && (word != "DATELT"))
        {
            queries.push_back(word);
            queryCounter++;
            queryDocs[queryCounter-1] = (iHandler->search(Porter2Stemmer::stem(word)));
        }

        else
            break;
        if(queryCounter == queryCapacity)
            resize();
    }
    for(int i = currentQuery; i < queryCounter - 1; i++)
    {
        for(int first = 0; first < queryDocs[i].size(); first++ )
        {
            for(int second = 0; second < queryDocs[i+1].size(); second++)
            {
                if(queryDocs[i][first].getFileName() != queryDocs[i+1][second].getFileName())
                {
                    tempVector.push_back(queryDocs[i][first]);
                }
            }
        }
        queryDocs[i+1].clear();
        queryDocs[i+1] = tempVector;
        tempVector.clear();
    }
    queryDocs->erase(queryDocs->begin(), queryDocs->begin()+ (queryCounter-1));
    if(word == "AND")
    {
        return AND();
    }
    if(word == "OR")
    {
        return OR();
    }
    if(word == "DATELT")
    {
        return DATELT();
    }
    else if(word == "DATEGT")
    {
        return DATEGT();
    }
    else
    {
        return queryDocs[queryCounter-1];
    }
}

vector<DocumentStorage> QueryProcessor::DATELT()
{
    int currentQuery = queryCounter -1;
    string word;
    ss >> word;
    cout<< word<<endl;
    string date;
    ss >> date;
    int month;
    int day;
    int year;
    stringstream dd;
    for (int a = 0; a < word.length(); a++)
    {
        if (!isdigit(word.at(a)))
        {
            word.replace(a,1," ");
        }
    }
    dd << word;
    cout<<word<<endl;
    dd >> month;
    dd >> day;
    dd >> year;

    vector<DocumentStorage> tempVector;
    for(int i = currentQuery; i < queryCounter; i++)
    {
        for(int first = 0; first < queryDocs[i].size(); first++)
        {
            if(queryDocs[i][first].getDate().getYear() < year)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
            else if(queryDocs[i][first].getDate().getYear() == year &&
                    queryDocs[i][first].getDate().getMonth() < month)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
            else if(queryDocs[i][first].getDate().getDay() < day &&
                    queryDocs[i][first].getDate().getYear() == year &&
                    queryDocs[i][first].getDate().getMonth() == month)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
        }
        queryDocs[i+1].clear();
        queryDocs[i+1] = tempVector;
        tempVector.clear();
    }

    if(date == "AND")
    {
        return AND();
    }
    if(date == "OR")
    {
        return OR();
    }
    if(date == "NOT")
    {
        return ANDNOT();
    }
    if(date == "DATEGT")
    {
        queryCounter++;
        return DATEGT();
    }
    if(date == "DATELT")
    {
        return DATELT();
    }
    else
    {
        return queryDocs[queryCounter];
    }

}

vector<DocumentStorage> QueryProcessor::DATEGT()
{
    int currentQuery = queryCounter -1;
    string word;
    ss >> word;
    string date;
    ss >> date;
    int month;
    int day;
    int year;
    stringstream dd;
    for (int a = 0; a < word.length(); a++)
    {
        if (!isdigit(word.at(a)))
        {
            word.replace(a,1," ");
        }
    }
    dd << word;
    cout<<word;
    dd >> month;
    dd >> day;
    dd >> year;

    vector<DocumentStorage> tempVector;
    for(int i = currentQuery; i < queryCounter; i++)
    {
        for(int first = 0; first < queryDocs[i].size(); first++)
        {
            if(queryDocs[i][first].getDate().getYear() > year)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
            else if(queryDocs[i][first].getDate().getYear() == year &&
                    queryDocs[i][first].getDate().getMonth() > month)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
            else if(queryDocs[i][first].getDate().getDay() > day &&
                    queryDocs[i][first].getDate().getYear() == year &&
                    queryDocs[i][first].getDate().getMonth() == month)
            {
                tempVector.push_back(queryDocs[i][first]);
            }
        }
        queryDocs[i+1].clear();
        queryDocs[i+1] = tempVector;
        tempVector.clear();
    }

    if(date == "AND")
    {
        return AND();
    }
    if(date == "OR")
    {
        return OR();
    }
    if(date == "NOT")
    {
        return ANDNOT();
    }
    if(date == "DATEGT")
    {
        return DATEGT();
    }
    if(date == "DATELT")
    {
        queryCounter++;
        return DATELT();
    }
    else
    {
        return queryDocs[queryCounter];
    }
}

vector<DocumentStorage> QueryProcessor::USERNAME()
{
    string word;
    ss >> word;
    return iHandler->search(word);
}

vector<DocumentStorage>* QueryProcessor::resize()
{
    queryCapacity += 10;
    vector<DocumentStorage>* tempArray;
    tempArray->resize(queryCapacity);
    tempArray = queryDocs;
    queryDocs->clear();
    queryDocs = tempArray;
    delete tempArray;
    return queryDocs;

}


