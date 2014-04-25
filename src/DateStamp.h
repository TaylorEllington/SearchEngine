/*!
 * \file DateStamp.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class DateStamp
*
* \brief Class to store the creation date of a DocumentStorage Object.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef DATESTAMP_HPP
#define	DATESTAMP_HPP

#include <iostream>
using namespace std;

class DateStamp
{
public:

    /*!
     * \brief Default Constructor for the DateStamp class.
     *
     * \warning Do not use if possible.
     */
    DateStamp();

    /*!
     * \brief Constructor for DateStamp Class taking parameters.
     *
     * Constructor taking in three integer parameters representing the day,
     * month, and year to be in the Class.
     *
     * \param day Day of creation.
     * \param month Month of creation.
     * \param year Year of creation.
     */
    DateStamp(int _day, int _month, int _year);

    /*!
     * \brief Destructor for the DateStamp Class.
     *
     * \warning Do not call unless needed.
     */
    virtual ~DateStamp();

    /*!
     * \brief Sets the day, month, and year to new values.
     *
     * \param day New day of creation.
     * \param month New month of creation.
     * \param year New year of creation.
     *
     * \return [information about return value]
     */
    void setDate(int _day, int _month, int _year);

    /*!
     * \brief Returns the Day.
     *
     * \return Returns the Day integer.
     */
    int getDay();

    /*!
     * \brief Returns the Month.
     * \return Returns the Month integer.
     */
    int getMonth();

    /*!
     * \brief Returns the Year.
     * \return Returns the Year intege.
     */
    int getYear();

    //friend ostream& operator<<( ostream& os);
private:

    /// Integer representing the day of creation.
    int day;

    /// Ingetger representing the month of creation.
    int month;

    /// Integer representing the year of creation.
    int year;

};

    /*!
     * \brief Overloaded Stream insertion Operator
     * \param os OutStream
     * \param ds DateStamp object to be read out.
     *
     * \return Returns an Outstream object.
     */
ostream& operator<<( ostream& os,  DateStamp& ds );


#endif	/* DATESTAMP_HPP */

