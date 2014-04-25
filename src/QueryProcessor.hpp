/*!
 * \file QueryProcessor.hpp
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class QueryProcessor
*
* \brief Handels user querys to the system.
*
* This class inherits from the Class IndexInterface and is one of the two
* storage options for the inverted file index.
*
* \author Nick Morris
* \date 4 May 2013
*/
#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <string>
#include <sstream>
#include "IndexHandler.h"
#include "DocumentStorage.h"

using std::string;

class QueryProcessor
{
public:

    /*!
     * \brief Constructor For the QueryProcessor Class.
     *
     * Handles the search and returns of queries to and from the USer
     * and the IndexHandler object.
     *
     * \param query What the User is loking for.
     * \param i Pointer to the IndexHandler Class.
     * \sa IndexHandler
     */
    QueryProcessor(string, IndexHandler*);

      /*!
     * \brief Destructor for the QueryProcessor.
     *
     * \warning Try not to use if Possible.
     */
    ~QueryProcessor();

     /*!
     * \brief Sets the Query to the Input string
     *
     * \param query The input query.
     * \return Void
     */
    void setQuery(string);

    /*!
     * \brief OverParser that calls other Query functions, also handles simple Queries.
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> parseQuery();

    /*!
     * \brief Handles AND queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> AND();

    /*!
     * \brief Handles OR queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> OR();

    /*!
     * \brief Handles NOT queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> ANDNOT();

    /*!
     * \brief Handles USERNAME queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> USERNAME();

    /*!
     * \brief SHandles DATEGT queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> DATEGT();

    /*!
     * \brief HandlesDateLT queries
     *
     * \return Vector of DocumentStorage Objects.
     */
    vector<DocumentStorage> DATELT();

    /*!
     * \brief Resizes the queryDocs object.
     *
     * \return Vector of DocumentStorage pointers.
     */
    vector<DocumentStorage>* resize();
private:

    /// a Vector of Vectors of DocumentsStorage objects.
    vector<DocumentStorage>* queryDocs;

    /// Query terms.
    vector<string> queries;

    /// Number of active Queries
    int queryCounter;

    /// Max number of Query terms.
    int queryCapacity;

    /// Stringstream object containing the query.
    stringstream ss;

    /// Pointer to the IndexHandler object.
    IndexHandler* iHandler;

    /// The Entire Query from the User.
    string inQuery;

    /// String representing the stemmed Query term.
    string stemmedQuery;
};

#endif
