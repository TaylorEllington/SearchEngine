
// File:   IndexEntry.h
// Author: taylor
// Id:     36679283
// Contents:
//


/*!
 * \file [filename]
 *
 * \author [your name]
 * \date
 *
 * [your comment here]
 */

 /*!
 * \class [class name]
 *
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \author [your name]
 * \date
 */
#ifndef INDEXENTRY_H
#define	INDEXENTRY_H

#include <iostream>
#include <vector>
#include "DocumentStorage.h"
using namespace std;

class IndexEntry {
public:

    /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    IndexEntry();

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    IndexEntry(string newWord);

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    void setWord(string newWord);

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    string getWord();

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    vector<Document>getDocuments();

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    void addDocument(Document * index);

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    IndexEntry(const IndexEntry& orig);

        /*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
    virtual ~IndexEntry();
    
    
private:

    /**
    *
    *
    */
    string word;

    /** 
    * Text goes here
    *
    */
    vector<Document> Documents;

};

#endif	/* INDEXENTRY_H */

