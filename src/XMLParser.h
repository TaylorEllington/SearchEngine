/*!
 * \file XMLParser.cpp
 *
 * \author Cameron Keith
 * \date 3 May 2013
 *
 *  This file is used to parse the input XML file, seperate it into the individual
 *  pages that make up the XML and then send them to the Stop Word Remover to
 *  under the needed modifications before being stored in the Index.
 */

/*!
* \class XMLParser
*
* \brief Class to seperate the XML file in to seperate pages to be further processed.
*
* The XMLParser recives a single string representing the filename for a XML
* file that is to be inserted into the Index by seperating the XML file into
* its seperate pages and packing them into the Document Class before passing them
* on to the StopRemover class.
*
* \author Cameron Keith
* \date 2 May 2013
*/
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include "IndexHandler.h"

class XMLParser
{
public:

    /*!
     * \brief Constructor for the XML parser class.
     *
     * Main constructor accepting two parameters, a string with the filename
     * to parse and an integer representing the current number of documents
     * that are located inside of the Index.
     *
     * \param filename String containing the name of the file to Parse.
     * \param count Integer representing the current number of documents in the Index.
     * \param index An IndexHandler pointer allowing insertion of Documents.
     * \sa StopRemover
     * \note Not accessible by the User.
     */
    XMLParser(std::string, int&, IndexHandler*&);
    /*!
     * \brief Destructor for the XMLParser class.
     *
     * \warning Do not call unless necessary.
     */
    ~XMLParser();

private:

    /** String containing the name of the File to be parsed. */
    std::string fileToParse;

    /** String containing the Author of the current document being parsed. */
    std::string author;

    /** String containing the creation date of the current document being parsed. */
    std::string timestamp;

    /** String containing the main body of the current document being parsed. */
    std::string text;

    /** String containing the title of the current document being parsed. */
    std::string title;

    /** String containing the unique name for the location where the Document info
    * while be written to memory. */
    std::string outFile;

    /*!
     * \brief Function to seperate the XML file to individual pages.
     *
     * Goes through the XML file with the help of PUGIXML seperating the XML
     * based on that each XML node named "PAGE" as a seperate document pulling
     * the title of the XML "PAGE" node, the timestamp it has, the author, and
     * the text node, it then writes all of this to a new file in a seperate
     * folder named EditedXML as well as creates a Document Object containing
     * the same information that was written to the file and passes the Document
     * object onto the StopRemover class. It also calls a funciton in the
     * IndexHandler class beginning the insertion of words by setting the
     * document that the following words are coming from.
     *
     * \param count Integer representing the current count of all documents in the Index.
     * \param index An IndexHandler pointer allowing insertion of Documents.
     * \return Void
     * \sa StopRemover
     * \note Not accessable by the User.
     */
    void parseFile(int&, IndexHandler*&);
};

#endif // XMLPARSER_H
