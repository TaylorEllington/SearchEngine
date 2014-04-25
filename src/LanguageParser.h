/*!
 * \file LanguageParser.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class LanguageParser
*
* \brief Looks for files that aren't in english
*
* Class that accepts a document, and looks at random character in the text and
* checks if they are english. Also performs a check on the title of the
* document for common language names as well as files known to not have useful
* information.
*
* \author Cameron Keith
* \date 5 May 2013
*/

#ifndef LANGUAGEPARSER_H
#define LANGUAGEPARSER_H

#include "Document.h"
class LanguageParser
{
public:

    /*!
     * \brief Constructor for the LanguageParser Class.
     *
     * Accepts a document and immediately calls the testLanguage function.
     *
     * \param file The Document that is being checked.
     */
    LanguageParser(Document*&);

    /*!
         * \brief Destructor for the Language Class.
         *
         * \warning Do not call unless needed.
         */
    ~LanguageParser();
private:

    /*!
     * \brief Function which tests if the file is English.
     *
    * Accepts a document, and looks at random character in the text and
    * checks if they are english. Also performs a check on the title of the
    * document for common language names as well as files known to not have useful
    * information.
     *
     * \param file Document to be tested.
     * \return Void
     */
    void testLanguage(Document*&);
};

#endif // LANGUAGEPARSER_H
