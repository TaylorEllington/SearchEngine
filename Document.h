/* 
 * File:   Document.h
 * Author: Nick Morris
 * Part of Search Engine project
 * Created on April 18, 2013, 3:48 PM
 */

#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include <string>


class Document {
public:
    Document();
    Document(std::string, std::string, std::string);
    Document(const Document& orig);
    virtual ~Document();
    void setTitle(std::string);
    void setDate(std::string);
    void setText(std::string);
    std::string getTitle();
    std::string getDate();
    std::string getText();
private:
    std::string documentTitle;
    std::string documentDate;
    std::string documentText;

};

#endif	/* DOCUMENT_H */

