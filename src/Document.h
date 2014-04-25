/*!
* \file Document.cpp
*
* \author Cameron Keith
* \date 3 May 2013
*
* This file is the combined effort of Nick and Cameron, used by the Document
* for passing the XML page from one object to another to maintain all data
*/

/*! \class Document
* \brief A class used to pass an XML page data.
*
* This class is used to pass the contents of an XML page to the various other
* classes used by the Document Parser in order to add the contents of the page
* into the file index.
*
* \author Nick Morris
* \date 18 April 2013
*/
#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include <string>

class Document
{
public:

    /*!
     * \brief Default Constructor for the Document Class.
     *
     * Default Constructor which sets all parameters to NULL.
     *
     * \warning Not recommended to use if possible.
     */
    Document();

    /*!
     * \brief Constructor which takes in all parameters for the Document Class.
     *
     * The main constructor as that it recieves a value for each data member of the
     * class in the order of Document Title, Document origin date, document body
     * document body text, and a document ID name.
     *
     * \param title String that is the Title of the XML page that is being sent.
     * \param date String that holds the Date of the XML Page's Creation.
     * \param text String that holds the Body of the XML Page.
     * \param author String that holds the Author of the XML page.
     * \param name String that holds the Name of the XML page used in simple ID.
     * \note This is the main constructor to be used.
     */
    Document(std::string, std::string, std::string, std::string, std::string);

    /*!
     * \brief Destructor for Document.
     *
     * A virtualized Destructor function for the Document class for the
     * case if a class inherited from Document to rewrite the destructor for
     * the inherited class.
     *
     * \note Dangerous, do not call unless you are a trained professional.
     * \warning Do not call the destructor of this class prematurely.
     */
    virtual ~Document();

    /*!
     * \brief Sets the Document Title.
     *
     * Recieves an input string and sets the DocumentTitle to the input string.
     *
     * \param  title The new title of the Document.
     * \return Void.
     */
    void setTitle(std::string);

    /*!
     * \brief Sets the Document creation date.
     *
     * Recieves an input string and sets the Document's date of creation to the input string.
     *
     * \param date The new Document creation date.
     * \return Void.
     */
    void setDate(std::string);

    /*!
     * \brief Sets the Document body text.
     *
     * Recieves an input string containing the body text of a XML document
     * and sets the DocumentText parameter to the input string.
     *
     * \param text The new Document body Text.
     * \return Void.
     */
    void setText(std::string);

    /*!
     * \brief Sets the Document's Author.
     *
     * Recieves an input string containing the XML pages author and sets the
     * DocumentAuthor parameter to the input string.
     *
     * \param author The new Document Author
     * \return Void.
     */
    void setAuthor(std::string);

    /*!
         * \brief Return the Document's Title.
         *
         * \return Returns the Document's title as a string.
         */
    std::string getTitle();

    /*!
         * \brief Return the Document's creation date.
         *
         * \return Returns the Document's creation date as a string.
         * \note [any note about the function you might have]
         */
    std::string getDate();

    /*!
         * \brief Return the Document's main text.
         *
         * \return Returns the Document's body text as a string.
         */
    std::string getText();

    /*!
         * \brief Return the Document's ID string.
         *
         * \return Returns the Document's author as a string.
         */
    std::string getAuthor();

    /** String to hold the Title of the Document.*/
    std::string documentTitle;

    /** String to hold the creation date of the Document.*/
    std::string documentDate;

    /** String to hold the body text of the Document.*/
    std::string documentText;

    /** String to hold the Author of the Document.*/
    std::string documentAuthor;

    /** String to hold the Document's ID name.*/
    std::string documentName;

    /// Boolean value stating if the document has forgien characters.
    bool isForgien;

};

#endif	/* DOCUMENT_H */
