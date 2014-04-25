/*!
 * \file IndexEntry.h
 *
 * \author Cameron
 * \date 5 May 2013
 *
 */

/*!
* \class IndexEntry
*
* \brief Primary Container class for the inverted file index.
*
* Holds a string word and a Vecotor of documents that contain the Word.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef INDEXENTRY_H
#define	INDEXENTRY_H

#include <iostream>
#include <vector>
#include "DocumentStorage.h"
using namespace std;

class IndexEntry
{
public:

    /*!
     * \brief Default Constructor for the IndexEntry class.
     *
     * Sets all values to NULL.
     *
     * \warning Try not to use if possible.
     */
    IndexEntry();

    /*!
     * \brief Constructor taking parameters for makinga new entry.
     *
     * \param newWord String containing the word to be stored in this structure.
     */
    IndexEntry(string newWord);

    /*!
     * \brief Sets the Word to a new Word.
     *
     * \param newWord String containing the word to be stored in this structure.
     * \return Void
     */
    void setWord(string newWord);

    /*!
     * \brief Returns the Word stored.
     *
     * \return Returns a string containing the word stored in this structure.
     */
    string getWord();

    /*!
     * \brief Returns the documents that are stored in the structure
     *
     * \return Returns a vector of DocumentStorage objects.
     */
    vector<DocumentStorage>getDocuments();

    /*!
     * \brief Adds a document to the vector in the structure.
     *
     * \param index A pointer to the Document that is to be stored.
     * \return Void
     */
    void addDocument(DocumentStorage * & index);

    /*!
     * \brief Destructor for the Index Entry Class.
     *
     * \warning Do not call unless needed.
     */
    virtual ~IndexEntry();


private:

    /// Word that is being stored.
    string word;

    /**
    * Vector of documentStorage objects that contain the word also stored in
    * in the structure.
    **/
    vector<DocumentStorage> documents;

};

#endif	/* INDEXENTRY_H */

