/*!
 * \file DocumentStorage.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 * This file is the combined effort of Nick and Talyor for use in the Index
 * and in query processing.
 */

/*!
* \class DocumentStorage
*
* \brief Class used to Store Document Title, Author, Creation date, and file Address.
*
* This class is used to create items that are stored in the Inverted File Index
* and additionally used by the QueryProcessor to return possible documents back
* to the User.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef DOCUMENTSTORAGE_H
#define	DOCUMENTSTORAGE_H

#include <string>
#include "DateStamp.h"



class DocumentStorage
{
public:

    /*!
     * \brief Default Constructor for DocumentStorage Class.
     *
     * Constructor which sets all values to NULL.
     *
     * \note Try not to use if possible.
     */
    DocumentStorage();

    /*!
     * \brief Constructor for DocumentStorage Class accepting all parameter values.
     *
     * Construtor taking an input value for each data member of the class.
     *
     * \param title Title of the document.
     * \param day Day of creation of the document.
     * \param month Month of creation of the document.
     * \param year Year of the creation of the document.
     * \param author Author of the document.
     * \param fileName Path to the file on th Hard Disk.
     *
     * \note Main constructor to use.
     */
    DocumentStorage(std::string, int, int, int, std::string, std::string);

    /*!
     * \brief Destructor for the DocumentStorage Class.
     *
     * \warning Do not call unless needed.
     */
    virtual ~DocumentStorage();

    /*!
     * \brief Sets the document Title.
     *
     * Recieves an input string and sets the DocumentTitle to the input string.
     *
     * \param  title The new title of the document.
     * \return Void.
     */
    void setTitle(std::string);

   /*!
     * \brief Sets the document creation date.
     *
     * Recieves three integers representing Day, Month, and Year, creates
     * a new DateStamp object with the input values.
     *
     * \param day The new document creation day.
     * \param month The new document creation day.
     * \param year The new document creation year.
     * \return Void.
     */
    void setDate(int day, int month, int year);

    /*!
     * \brief Returns the documents title.
     *
     * \return Title of the document.
     */
    std::string getTitle();

    /*!
     * \brief Returns the creation date of the document.
     *
     * \return DateStamp of the documents creation date.
     */
    DateStamp getDate();

    /*!
     * \brief Sets the docuemts Author.
     *
     * \param author The new Author for the document.
     * \return void
     */
    void setAuthor(std::string);

    /*!
     * \brief Returns the Author of the document.
     *
     * \return The Author of the document.
     */
    std::string getAuthor();

    /*!
     * \brief Sets the path to the file on the HardDisk.
     *
     * \param fileName Path to the Document that was written to the HardDisk.
     * \return Void
     */
    void setFileName(std::string);

    /*!
     * \brief Returns the file Path.
     *
     * \return Returns the path to Documents location on the HardDisk.
     */
    std::string getFileName();

    /*!
         * \brief Print the Docuemt Info to screen.
         *
         * \author Cameron Keith
         *
         * \return Void
         */
    void display();

    /// Count of how many times a word appears in that document
    int count;


private:

    /// Title of the document.
    std::string documentTitle;

    /// Author of the document.
    std::string documentAuthor;

    /// Creation date of the document.
    DateStamp date;

    /// Path to the file's location on the HardDisk.
    std::string fileName;

};

#endif	/* DOCUMENT_H */

