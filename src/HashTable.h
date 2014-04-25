/*!
 * \file HashTable.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class HashTable
*
* \brief HashTable storage Class.
*
* This class inherits from the Class IndexInterface and is one of the two
* storage options for the inverted file index.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "IndexInterface.h"
#include "Bucket.h"
#include <cstdlib>
#include <fstream>

class HashTable : public IndexInterface
{
public:

    /*!
     * \brief Constructor For the HashTable Class.
     *
     * Constructs a new Hash Table with the input interger number of buckets.
     *
     * \param buckets How many buckets will be in the table.
     * \sa IndexInterface, Bucket
     */
    HashTable(int buckets);

    /*!
     * \brief Add a word and the Document its from to the Hash Table
     *
     * \param word Word to add to Hash Table.
     * \param document The Document that the Word is from.
     *
     * \return Void
     */
    void add(string word, DocumentStorage*& document);

    /*!
     * \brief Search the Hash Table for the input word.
     *
     * \param term The word that will be searched for inside the Hash Table.
     * \return Returns a vector of the DocumentStorage class objects where the word is found.
     */
    vector<DocumentStorage> search(string term);

    /*!
     * \brief Delete the Current Hash Table.
     *
     * \return Void
     */
    void dumpData();

    /*!
     * \brief Saves the Current Hash Table to a file.
     *
     * \param count Count of the number of files that are currently stored in the Hash Table.
     * \return Void
     */
    void saveData(int);

    /*!
     * \brief Load information to be stored in the Hash Table from a File.
     *
     * \param counter Count of files that will be read in and stored in the Hash Table.
     * \return void
     */
    void loadData(int&);

    /*!
     * \brief Destuctor for the Hash Table Class.
     *
     * \warning Do not use unless needed.
     */
    ~HashTable();


private:

    /*!
     * \brief Hashing algorithm to create a unique ID for each word to be added to the Table
     *
     * \param word Word to be added to the Hash Table
     * \return Integer corresponding to the unique ID created for the input Word by the Hashing Algorithm
     */
    int hash(string word);

    /// Integer for the Number of Buckets to be used by the Hash Table.
    int bucketCount;

    /// Array of Buckets.
    Bucket * Table;


};

#endif	/* HASHTABLE_H */

