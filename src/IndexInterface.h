/*!
 * \file IndexInterface.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class IndexInterface
*
* \brief Virtual Class.
*
* Pure Virtual Class to allow AVLTree and Hash Table to have the same
* public interface.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef INDEXINTERFACE_H
#define	INDEXINTERFACE_H

#include <vector>
#include <iostream>
#include "DocumentStorage.h"

using std::string;
using std::vector;

class  IndexInterface
{
public:

    /*!
     * \brief Destructor for IndexInterface Class.
     *
     * \warning Pure Virtual.
     */
    virtual ~IndexInterface() = 0;

    /*!
     * \brief Add to Index.
     *
     * \param word Word to add to Index.
     * \param document Document that the Word is found in.
     * \return Void
     */
    virtual void add( string word, DocumentStorage * & document) = 0;

    /*!
     * \brief Search for if the word is in the Index.
     *
     * \param term String to search if it can be found in the Index.
     * \return Vector of documents that the Word is found in.
     */
    virtual vector<DocumentStorage> search(string term) = 0;

    /*!
     * \brief Delete Index.
     *
     * \return Void
     */
    virtual void dumpData() = 0;

    /*!
     * \brief Write Index to file on HardDisk.
     *
     * \param count Count of Documents in the Index.
     * \return Void
     */
    virtual void saveData(int) = 0;

    /*!
     * \brief Loads Index from a file on the HardDisk.
     *
     * \param counter Count of documents that are being loaded into the Index.
     * \return Void
\
     */
    virtual void loadData(int&) = 0;


};



#endif	/* INDEXINTERFACE_H */

