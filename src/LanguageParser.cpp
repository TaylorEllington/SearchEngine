#include "LanguageParser.h"

#include <cstring>
#include <string>
#include <cstdlib>

#include <algorithm>

#include <iostream>
#include <sstream>

using namespace std;

LanguageParser::LanguageParser(Document*& file)
{
    testLanguage(file);
}

LanguageParser::~LanguageParser()
{

}

void
LanguageParser::testLanguage(Document*& file)
{
    int length = file->documentText.length();
    int loc;

    string text = file->documentText;

    // Checks to see if the Text string has a non-zero length.
    if (length!= 0)
    {
        // Checks 20 random characters in the text of the document
        // to see if the character is a non-ASCII character.
        for (int a = 0; a < 20; a++)
        {
            loc = rand() % length;
            if (int(text.at(loc)) < 0)
                file->isForgien = true;
        }
    }
    else
    {
        file->isForgien = true;
    }

    stringstream ss;
    string title = file->documentTitle;
    string compareWord;
    int titleLength = title.length();

    // seperates the title into seperate words.
    for (int a = 0; a < titleLength; a++)
    {
        if (!isalpha(title.at(a)))
        {
            title.replace(a, 1, " ");
        }
    }
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    ss << title;

    // While loop to check each word of the title is a known forgien language
    // identifier or a file known to now have useful text.
    while (ss.good())
    {
        compareWord.clear();
        ss >> compareWord;
        if (compareWord == "file" || compareWord == "german" || compareWord ==
                "dutch" || compareWord == "spanish" || compareWord == "french" ||
                compareWord == "vietnamese" || compareWord == "portuguese"
                || compareWord == "japanese" || compareWord == "polish" ||
                compareWord == "chinese" || compareWord == "mediawiki" ||
                compareWord == "norwegian"|| compareWord == "template" ||
                compareWord == "latin" || compareWord == "russian")
        {
            file->isForgien = true;
        }

    }
}
