
// File:   DateStamp.hpp
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
#ifndef DATESTAMP_HPP
#define	DATESTAMP_HPP

#include <iostream>
using namespace std;

class DateStamp {
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
    DateStamp();

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
    DateStamp(int _day, int _month, int _year);

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
    DateStamp(const DateStamp& orig);

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
    virtual ~DateStamp();

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
    void setDate(int _day, int _month, int _year);

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
    int getDay();

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
    int getMonth();

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
    int getYear();
    
    //friend ostream& operator<<( ostream& os);
private:
    int day;
    int month;
    int year;

};

#endif	/* DATESTAMP_HPP */

