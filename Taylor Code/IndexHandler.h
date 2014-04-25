
// File:   IndexHandler.h
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
#ifndef INDEXHANDLER_H
#define	INDEXHANDLER_H

#include "IndexInterface.h"
#include "AVLTree.h"


class IndexHandler {
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
    IndexHandler(bool);
    
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
    ~IndexHandler();
    
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
    void addWord(string word);

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
    void newFile(string title, int day, int month, int year, string author);
    
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
    vector<Document> search(string word);
    
    
   
    
    
    
private:

    /**
    *
    **/
    IndexInterface * Index;
    //DoublyLinkedList * DateOrderList;
    //AuthorLookUp * authorLookup;

    /**
    *
    *
    */
    string currentTitle;

    /**
    *
    *
    */
    int currentDay;

    /**
    *
    *
    */
    int currentMonth;

    /**
    *
    *
    */
    int currentYear;

    /**
    *
    *
    */
    string currentAuthor;
    

        
};

#endif	/* INDEXHANDLER_H */

