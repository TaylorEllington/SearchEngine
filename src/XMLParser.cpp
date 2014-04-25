#include <fstream>
#include <iostream>
#include <sstream>


#include "XMLParser.h"
#include "pugixml.hpp"
#include "Document.h"
#include "StopRemover.h"
#include "LanguageParser.h"

using namespace std;
XMLParser::XMLParser(string filename, int& count, IndexHandler*& index)
{
    fileToParse = filename;
    parseFile(count, index);
}

XMLParser::~XMLParser()
{
    fileToParse.clear();
}

void
XMLParser::parseFile(int& count, IndexHandler*& index)
{
    Document* page;
    // Create a pugixml document object.
    pugi::xml_document doc;

    // Boolean esk value for if the XML file can be opened with pugi's load file function.
    pugi::xml_parse_result result = doc.load_file(fileToParse.c_str());
    if (!result)
    {
        cerr<<"File could not be opened."<<endl;
        return ;
    }

    // Sets the first node.
    pugi::xml_node beginningNode = doc.child("mediawiki");

    /*
    * Loop that begins at the first child node of the mediawiki node and iterates
    * through the XML file until it reaches the last child node of mediawiki.
    */
    for (pugi::xml_node nodeA = beginningNode.first_child(); nodeA; nodeA = nodeA.next_sibling())
    {

        stringstream ss;
        ss<<"EditedXML/Document" << count;
        outFile = ss.str();

        /*
        * Seperates off the unique IDname that will be attached to the document
        * from where its corresponding file will be written.
        */
        string nameOfDoc = outFile.substr(10,20);
        ofstream fout (outFile.c_str());

        // Checks for the title node and pulls the value from the node.
        if (nodeA.child("title"))
        {
            title = nodeA.child_value("title");
            fout<<"Title: "<<title<<endl;
        }

        /*
        * Loop to go through each child node of nodeA while nodeA has a
        * nonvisited child node.
        */
        for (pugi::xml_node nodeB = nodeA.first_child(); nodeB; nodeB = nodeB.next_sibling())
        {
            // Checks for the contributor node and pulls the value.
            if (nodeB.child("contributor"))
            {
                /*
                * Pulls the value from constibutor's child node where the child
                * nodes name is username, which is the Author.
                */
                author = nodeB.child("contributor").child_value("username");
                fout<<"Author: "<<author<<endl;
            }

            //Checks for the timestamp node and pulls the value.
            if (nodeB.child("timestamp"))
            {
                timestamp = nodeB.child_value("timestamp");
                fout<<"TimeStamp: "<<timestamp<<endl;
            }

            //Checks for the text node and pulls the value.
            if (nodeB.child("text"))
            {
                text = nodeB.child_value("text");
                fout<<text<<endl;
            }

        }

        // Creates a new Document object with specific parameters.
        page = new Document(title, timestamp, text, author, nameOfDoc);

        ss.str("");
        for (int a = 0; a < timestamp.length(); a++)
        {
            if (!isdigit(timestamp.at(a)))
            {
                timestamp.replace(a, 1, " ");
            }
        }
        ss << timestamp;
        int year;
        int month;
        int day;
        ss>> year;
        ss>>month;
        ss>>day;
        ss.str("");
        // Sets the file for where the Following words will come from.
        index->newFile(title, day, month, year, author, outFile);
        // Parses the file to Determine if the Document is not in English.
        LanguageParser lang(page);

        // If statement to catch files that talk about User BIO.
        if(!(title.substr(0,4) == "User"))
        {

            // Calls the StopRemover class, passing the new Document object along with it.
            if (!page->isForgien)
            {
                cout<<outFile<<endl;
                StopRemover stopClear(page, index);
            }

        }

        count++;
        outFile.clear();
        fout.close();
        delete page;
    }
    return ;
}
