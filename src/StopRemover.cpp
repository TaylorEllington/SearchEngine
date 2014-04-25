#include <cstring>

#include <algorithm>

#include <fstream>
#include <iostream>
#include <sstream>

#include "porter2_stemmer.h"
#include "StopRemover.h"


using namespace std;
StopRemover::StopRemover(Document*& file, IndexHandler*& index)
{
    stopWordsFilename = "StopWords_List.txt";
    ifstream fin (stopWordsFilename.c_str());
    arrayMax = 660;
    stopArray = new string[arrayMax];

    // Loop for getting each word out of the file.
    for (int a = 0; a < arrayMax; a++)
    {
        getline(fin, stopArray[a]);
    }

    remove(file, index);
}

StopRemover::~StopRemover()
{
    delete[] stopArray;
    stopWordsFilename.clear();
}

void
StopRemover::remove(Document*& file, IndexHandler*& index)
{
    stringstream ss, dd;

    string stopWord;
    string compareWord;
    string stemmedWord;
    string completedRemovalTitle = "";
    string completedRemovalText = "";

    int titleLength = file->getTitle().length();
    int textLength = file->getText().length();

    // Loop for going through the title of the document and changing all non
    // letters into spaces.
    for (int a = 0; a < titleLength; a++)
    {
        if (!isalpha(file->documentTitle.at(a)))
        {
            file->documentTitle.replace(a, 1, " ");
        }
    }

    // Loop for going through the text of the document and changing all non
    // letters into spaces.
    for (int a = 0; a < textLength; a++)
    {
        if (!isalpha(file->documentText.at(a)))
        {
            file->documentText.replace(a, 1, " ");
        }
    }

    // Changes all letters in both documentText and documentTitle into lowercase letters.
    transform(file->documentTitle.begin(), file->documentTitle.end(), file->documentTitle.begin(), ::tolower);
    transform(file->documentText.begin(), file->documentText.end(), file->documentText.begin(), ::tolower);

    // Moves the two strings to a secondary location to preserve their original integrety.
    completedRemovalTitle = file->documentTitle;
    completedRemovalText = file->documentText;

    /*
    * This loop is for taking each word in the title and comapring it to each
    * stop word that is found in the stopArray. If it is a word in the stop
    * array, it sets a boolean value to true and then proceeds on. If the word
    * is not a stop word, it is then stemmed using the Porter Stemmer and sent
    * over to the index to be added.
    */
    ss << completedRemovalTitle;
    completedRemovalTitle.clear();
    bool isStopWord = false;
    while (ss.good())
    {
        compareWord.clear();
        ss >> compareWord;
        isStopWord = false;
        for (int a = 0; a < arrayMax; a++)
        {
            if (compareWord == stopArray[a])
            {
                isStopWord = true;
            }
        }
        if (!isStopWord)
        {
            stemmedWord = Porter2Stemmer::stem(compareWord);

            if (stemmedWord.length() > 2)
            {
                index->addWord(stemmedWord);
            }

        }

    }

    /*
        * This loop is for taking each word in the text and comapring it to each
        * stop word that is found in the stopArray. If it is a word in the stop
        * array, it sets a boolean value to true and then proceeds on. If the word
        * is not a stop word, it is then stemmed using the Porter Stemmer and sent
        * over to the index to be added.
        */
    dd << completedRemovalText;
    completedRemovalText.clear();
    while (dd.good())
    {
        compareWord.clear();
        dd >> compareWord;
        isStopWord = false;
        for (int a = 0; a < arrayMax; a++)
        {
            if (compareWord == stopArray[a])
            {
                isStopWord = true;
            }
        }
        if (!isStopWord)
        {
            stemmedWord = Porter2Stemmer::stem(compareWord);

            if (stemmedWord.length() > 2)
            {
                index->addWord(stemmedWord);
            }
        }

    }
    if (file->documentAuthor != "")
    {
        index->addWord(file->documentAuthor);
    }
}
