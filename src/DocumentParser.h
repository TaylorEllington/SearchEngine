/*!
 * \file DocumentParser.cpp
 *
 * \author Cameron Keith
 * \date 3 May 2013
 *
 * This is an over class for the Document Parsing stage of the Search Engine
 * responsible for seperating the XML files and creating the index terms used in
 * the inverted file index.
 */

/*!
* \class DocumentParser
*
* \brief The Overclass used to Parse incoming XML files and ready them for index insertion.
*
* This is an Overclass containing the XMLParser class and StopRemover class
* to keep access to the "sub classes" to a minimum.
*
* \author Cameron Keith
* \date 2 May 2013
*/
#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include <string>
#include "IndexHandler.h"

class DocumentParser
{
public:

    /*!
     * \brief Constructor for the DocumentParser class.
     *
     * Constructor which accepts an integer parameter which is the count of total
     * documents that are currently in the system as well as a string that
     * contains the file name of the XML file to be inserted into the system,
     * if no file is given the constructor will use the default file corresponding
     * to the XML file which creates the default index.
     *
     * \param count Integer which represents to the current number of files in the index.
     * \param fileName String containing the filename of the file to insert.
     * \param index An IndexHandler pointer allowing for adding of Documents into the index.
     * \warning Be careful when creating this class as it is set to chain the entire insertion process.
     */
    DocumentParser(int&, IndexHandler*&, std::string = "enwikibooks-20121016-pages-meta-current.xml");

    /*!
     * \brief Destructor for the DocumentParser class.
     *
     * \warning Do not call prematurely because it will delete all "sub classes" inside.
     */
    ~DocumentParser();

private:

    /**String which contains the name of the file to be added to the Index. */
    std::string mainFilename;

    /*!
     * \brief Calls the XML parser on the file stored in mainFileName
     *
     * This is a private function called at the end of the constructor for
     * the DocumentParser which then creates an XMLParser object with the file
     * stored in the strinng mainFileName.
     *
     * \param count Recieves the integer count from the constructor and passes it onto the XML Parser.
     * \param index An IndexHandler pointer allowing th adding of Documents.
     * \return Void
     * \sa XMlParser
     * \note This function can not be called by the user.
     */
    void parseFile(int&, IndexHandler*&);
};

#endif // DOCUMENTPARSER_H
