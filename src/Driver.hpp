/*!
* \file Driver.hpp
*
* \author Cameron Keith
* \date 4 May 2013
*
* A group collaberative effort to create this class to handle the three
* different modes the Search Engine can run in.
*
*/

/*! \class Driver
* \brief Over classes used to control the Search Engine.
*
* This class is used to control the DocumentParser class, the IndexHandler
* class, the Inverted File index, and the QueryProcessor class and run each
* in accordance with the particular mode that the Search Engine is running in.
*
* \author Cameron Keith
* \date 4 May 2013
*/

#ifndef DRIVER_H
#define DRIVER_H

#include <string>

#include "DocumentParser.h"
#include "IndexHandler.h"
#include "QueryProcessor.hpp"

class Driver
{
public:

    /*!
     * \brief Constructor for the Driver Class.
     *
     * Constructor reciving a single parameter corresponding to the state
     * that the Search Engine should run in, with a defualt case of running
     * the User interactive case.
     *
     * \param searchEngineMode A char array passed in from the command line.
     * \note If an improper command tag is passed, the engine will default to User Interactive.
     */
    Driver(char*);

    /*!
    * \brief Destructor for the Driver class.
    */
    ~Driver();

    /*!
     * \brief Runs the Search Engine in Matainence Mode.
     *
     * Checks to see if there is a written Index file in the system and asks
     * the user depending on the result of the check whether they want to
     * remake the index or simply add to the Index file if it Exists.
     *
     * \return Void
     * \sa DocumentParser, IndexHandler, StopRemover, LanguageRemover, XMLParser
     * \note Responsible for modifying documents in the Index.
     */
    void runMatainenceMode();

    /*!
    * \brief Defualt Method of Running the Search Engine.
    *
    * Allows the User to Query the Index using a variety of parameters, returns
    * a list of the top 15 files that relate to the initial query and allows
    * the user to then choose which of the documents they want to read.
    *
    * \return Void
    * \sa IndexHandler, QueryProcessor, Bucket, HashTable, AVLNode, AVLTree, IndexEntry, IndexInterface
    * \note Version of the Search Engine for the Typical User.
    */
    void runUserMode();

    /*!
    * \brief Tests the limits of what the Search Engine can take.
    *
    * Asks the User what file of commands they would like to test the Search
    * Engine with. Reads the file and then completes the tasks read from the
    * file.
    *
    * \return Void
    * \sa IndexHandler, QueryProcessor, DocumentParser
    * \note Tests the limits of the Search Engine.
    */
    void runStressTestMode();

private:

    /// The IndexHandler for the Search Engine.
    IndexHandler* indexHandler;

    /// The DocuemtParser for the Search Engine.
    DocumentParser* documentParser;

    /// The QueryProcessor for the Search Engine.
    QueryProcessor* queryProcessor;

    /// Count of Files currently Stored in the Index.
    int documentCount;

};
#endif //DRIVER_H
