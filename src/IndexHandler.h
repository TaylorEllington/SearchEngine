/*!
 * \file IndexHandler.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
 * \class IndexHandler
 *
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \author Taylor Ellington
 * \date 4 May 2013
 */

#ifndef INDEXHANDLER_H
#define	INDEXHANDLER_H

#include "IndexInterface.h"
#include "AVLTree.h"
#include "HashTable.h"

class IndexHandler
{
public:

    /*!
     * \brief Constructor for the IndexHandler class.
     *
     * Accepts a boolean that if passed true will create an AVLTree Inverted
     * file Index, if False will create a Hash Table Inverted File Index.
     *
     * \param check Boolean to determine which Storage method will be used.
     */
    IndexHandler(bool);

    /*!
     * \brief Destructor for the IndexHandler Class.
     *
     * \warning Do not call unless needed.
     */
    ~IndexHandler();

    /*!
     * \brief Adds the Word to the Inverted File Index.
     *
     * \param word Word to be added to the Inverted File Index.
     * \return Void
     */
    void addWord(string word);

    /*!
     * \brief Sets up what file all following words will come from.
     *
     * Sets the infomation needed to create the DocumentStorage object of the
     * IndexEntry class.
     *
     * \param title Title of the Document.
     * \param day Day of creation of the Document.
     * \param month Moth of creation of the Document.
     * \param year Year of creation of the Document.
     * \param author Author of the Document.
     * \param currentFIle Path to the Document on the HardDisk.
     * \return Void
     */
    void newFile(string title, int day, int month, int year, string author, string currentFile);

    /*!
     * \brief Looks to see if the Word is stored in the Index.
     *
     * \param word String that is going to be searched in the Inverted File Index.
     * \return A vector of DocumentStorage objects that are the result of the search.
     */
    vector<DocumentStorage> search(string word);

    /*!
     * \brief Construct the Inverted File Index froma Stored Index save file.
     *
     * \param counter Count of documents that are being added into the Inverted File Index.
     * \return void
     */
    void buildIndexFromFile(int&);

    /*!
     * \brief Delete the Inverted File Index.
     *
     * \return Void
     */
    void clearIndex();

    /*!
     * \brief Save the Inverted File Index to the HardDisk.
     *
     * \param count Count of Documents in the Index.
     * \return Void
     */
    void saveIndex(int);






private:

    /// Pointer to the what will become the Inverted File Index.
    IndexInterface * Index;

    /// Title of the current Document being parsed.
    string currentTitle;

    /// Day of creation of the current Document being parsed.
    int currentDay;

    /// Month of creation of the current Document being parsed.
    int currentMonth;

    /// Year of creation of the current Document being parsed.
    int currentYear;

    /// Author of the current Document being parsed.
    string currentAuthor;

    /// Path to file on disk of the Document being parsed.
    string currentFile;



};

#endif	/* INDEXHANDLER_H */

