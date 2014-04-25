/*!
 * \file Bucket.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class Bucket
*
* \brief An object used with the Hash Table.
*
* Used in conjunction with the HashTable class to store the Indexed Files.
*
* \author Taylor Ellington.
* \date 4 May 2013
*/

#ifndef BUCKET_H
#define	BUCKET_H

#include "IndexEntry.h"

class Bucket
{
public:

    /// Vector of IndexEntry objects storedin this Bucket.
    vector<IndexEntry> contents;

private:

};

#endif	/* BUCKET_H */

