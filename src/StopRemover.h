/*!
 * \file StopRemover.cpp
 *
 * \author Cameron Keith
 * \date 3 May 2013
 *
 * This function is used to remove the stop words from each page from the XML,
 * stem the remaining words and then pass on each word to the Index Handler to
 * be added to the Inverted File Index.
 */

/*!
* \class StopRemover
*
* \brief Processes the words before being entered into the Index.
*
* [detailed description]
*
* \author Cameron Keith
* \date 2 May 2013
*/
#ifndef STOPREMOVER_H
#define STOPREMOVER_H

#include <string>

#include "Document.h"
#include "IndexHandler.h"

class StopRemover
{
public:

    /*!
     * \brief Constructor for the StopRemover Class.
     *
     * The Main Constructor, accepts one parameter as an arguement which is a
     * Document Class object.
     *
     * \param file A Document Object that is to under go final prep before entering the Index.
     * \param index An IndexHandler point allowing the insertion of Documents.
     * \note Not Accessable by the User.
     */
    StopRemover(Document*&, IndexHandler*&);
    /*!
     * \brief Destructor for the Stop Remover Class.
     *
     * \warning Do not calll unless necessary.
     */
    ~StopRemover();

private:

    /*!
     * \brief Function to Remove Stop words from the Document and Stem.
     *
     * This function goes through the documentTitle and documentText, first
     * changing all punctuation, forgein characters, and numerical characters
     *  in to spaces and inserts the modified string into a stringstream
     * where it is then compared against a list of stopWords. If the word
     * does not match any of the stop words it is then run through a
     * version of the Porter Stemmer before being passed on to be inserted in
     * in the Index.
     *
     * \param file Document object that is being prepped for insertion into the Index.
     * \param index An IndexHandler pointer that allows insertion into the Index.
     * \return Void.
     * \note Not accessable by the User.
     */
    void remove(Document*&, IndexHandler*&);

    /** An array of Strings used to store the StopWords. */
    std::string* stopArray;

    /** The Number of StopWords. */
    int arrayMax;

    /** The Name of the file containing the sStopWords. */
    std::string stopWordsFilename;

};

#endif // STOPREMOVER_H
