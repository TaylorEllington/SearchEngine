/************************************************
*												*
*	File: Driver.cpp							*
*												*
*	Author: Cameron Keith						*
*												*
*	Last Update: 5 May 2013						*
*												*
*												*
************************************************/

#include <iostream>
#include <fstream>

#include <cstdlib>

#include <vector>

#include <cstring>

#include <chrono>

#include "Driver.hpp"
#include "DocumentStorage.h"

Driver::Driver(char* searchEngineMode)
{
    documentCount = 1;
    cout<<searchEngineMode<<endl;
    //Begins the Search Engine in Matainence Mode.
    if(string(searchEngineMode) == "-m")
    {
        cout<<"Search Engine is now entering Matainence Mode.\n";
        runMatainenceMode();
    }

    // Begins the Search Engine in Stress Test Mode.
    if(string(searchEngineMode) == "-s")
    {
        cout<<"Search Engine is now entering Stress Test Mode.\n";
        runStressTestMode();
    }
    // Runs the Search Engine in User Interactive Mode.
    else if(string(searchEngineMode) == "-u")
    {
        cout<<"Search Engine is now entering User Interactive Mode.\n";
        runUserMode();
    }
    //runMatainenceMode();
}

Driver::~Driver()
{
    // For now just a temp filler.
}

void
Driver::runUserMode()
{
    // For ze lulz have a welcome that is the same as the Band intro from
    // marching season.
    int mode;
    string printData;
    string query;
    system("clear");
    cout<<"User Interactive Mode:"<<endl;

    // Asks User how they want the Index Made.
    cout<<"What type of structure would you like the Index to be in? \n1.* AVLTree";
    cout<<"\n2. Hash\n";
    cin >> mode;
    if (mode == 2)
    {
        indexHandler = new IndexHandler(false);
    }
    else
        indexHandler = new IndexHandler(true);

    indexHandler->buildIndexFromFile(documentCount);

    vector<DocumentStorage> result;
    system("clear");
    cout<<"What would you like to do?\n1.* Query Index \n2. Exit\n";
    cin >> mode;
    int fileID;
    do
    {
        if (mode != 2)
        {
            system("clear");
            cout<<"Enter the query you would like to give the system:\n\n*";
            cout<<"Sample format:\nAND, OR, NOT, DATEGT, DATELT, USERNAME\t(";
            cout<<"Please end query with a period)\n\n";
            getline(cin, query, '.');
            queryProcessor = new QueryProcessor(query,indexHandler);
            result = queryProcessor->parseQuery();

            cout<<"Top 15 Returned Files:\n\n";
            cout<<"Total number of Results: "<<result.size()<<endl<<endl;
            if (result.size() != 0)
            {
                if (result.size() > 15)
                {
                    for (int a = 0; a < 15; a++)
                    {
                        cout<<a+1<<endl;
                        result[a].display();
                        cout<<endl;
                    }
                }
                else
                {
                    for (int a = 0; a < result.size(); a++)
                    {
                        cout<<a+1<<".\n";
                        result[a].display();
                        cout<<endl;
                    }
                }
                cout<<"Please choose the Number cooresponding to the file that you";
                cout<<" would like to view the full. ";
                cin >> fileID;
                fileID--;
                if (fileID >= result.size())
                {
                    cout<<"Invalid Number, moving on now.\n";
                }
                else
                {
                    ifstream fin(result[fileID].getFileName().c_str());

                    cout<<fin.good()<<endl;
                    system("clear");
                    while (fin.good())
                    {
                        getline(fin,printData);
                        cout<<printData<<endl;
                    }
                }
            }

        }
        cout<<"\nDo you wish to query again?\n1. Yes\n2.* No\n";
        cin>>mode;

    }
    while (mode != 2);
    cout<<"Thank you!\n";
    cout<<"\n\nRODEO, RODEO, MUSTANGS RIDE 'EM\n";

}

void
Driver::runStressTestMode()
{
    string fileInput;
    string command;
    string theString;
    stringstream ss;
    indexHandler = new IndexHandler(true);
    indexHandler->buildIndexFromFile(documentCount);
    system("clear");
    cout << "Stress Test Mode:\n\n\n";
    cout << "Enter a file of commands to test the search engine: \n"<<endl;
    cin >>  fileInput;
    ifstream testFile(fileInput.c_str());
    system("clear");

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while(testFile.good())
    {
        getline(testFile, fileInput);
        ss << fileInput;
        ss >> command;
        theString = ss.str();
        if(command == "ADD"){
            documentParser = new DocumentParser(documentCount, indexHandler, theString);
        }
        else if(command == "SEARCH"){
            vector<DocumentStorage> tempVector;
            queryProcessor = new QueryProcessor(theString, indexHandler);
            tempVector = queryProcessor->parseQuery();
        }
        else if(command == "DUMP"){
            indexHandler->clearIndex();
        }
        else if(command == "SAVE"){
            indexHandler->saveIndex(documentCount);
        }
        else if(command == "LOAD"){
            indexHandler->buildIndexFromFile(documentCount);
        }
    }

    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds << " ms\n";
}

void
Driver::runMatainenceMode()
{
    system("clear");
    cout<<"Mataince Mode:\n\n\n";
    indexHandler = new IndexHandler(true);
    ifstream indexFile ("INDEXFILE.save");
    string recreateIndex;
    string fileToAdd;

    // Checks to see if An Written Index File Exists.
    if (indexFile.good())
    {
        // Asks if the User wants to upload the Saved Index File into
        // the current Index.
        cout<<"There is a saved Index file, would you like to load it?\n";
        cout<<"1. Yes\n";
        cout<<"2. no\n";
        cin >> recreateIndex;
        if (recreateIndex == "2")
        {
            // If the user says they don't want to use the saved Index File
            // asks if they want to remove the Index from the Beginning.
            system("clear");
            cout<<"Would you like to recreate the Base Index?\n";
            cout<<"1. Yes\n";
            cout<<"2. no\n";
            cin >> recreateIndex;
            if (recreateIndex == "2")
            {
                // If the User says they don't want to remake the file asks if
                // they want to add their own file into the Index.
                system("clear");
                cout<<"Base Index will not be loaded, would you like to add";
                cout<<" your own file?\n";
                cout<<"1. Yes\n";
                cout<<"2. no\n";
                cin >> recreateIndex;

                // If the User doesn't want to add their own file, Exit the
                // Search Engine.
                if (recreateIndex == "2")
                {
                    cout<<"Exiting Mataince Mode.";
                }
                else
                {
                    // If the User wants to add their own file displays a
                    // list of possible .XML files they can add and they then
                    // type the full name of the File.
                    system("clear");
                    cout<<"List of Possible XML Files you can Add.\n\n";
                    system("ls *.xml");
                    cout<<"\nPlease enter the Name of the File to add:\n";
                    cin >> fileToAdd;
                    documentParser = new DocumentParser(documentCount, indexHandler, fileToAdd);
                }
            }
            else
            {
                // If the User says they would like to recreate the Base Index.
                system("clear");
                cout<<"Recreating the Base Index.\n";
                documentParser = new DocumentParser(documentCount, indexHandler);

                // Then asks the User if they want to add their own file.
                cout<<"would you like to add your own file?\n";
                cout<<"1. Yes\n";
                cout<<"2. no\n";
                cin >> recreateIndex;

                // If they say they don't want to add Exit the Search Engine.
                if (recreateIndex == "2")
                {
                    cout<<"Exiting Mataince Mode.";
                }
                else
                {
                    // If the User wants to add a file, displays a list of
                    // possible files they can add and then prompts the
                    // user to type the name of the File.
                    system("clear");
                    cout<<"List of Possible XML Files you can Add.\n\n";
                    system("ls *.xml");
                    cout<<"\nPlease enter the Name of the File to add:\n";
                    cin >> fileToAdd;
                    delete[] documentParser;
                    documentParser = new DocumentParser(documentCount, indexHandler, fileToAdd);
                    cout<<"File successfully added. Matainence Mode shutting down.";
                }
            }
        }
        else
        {
            // If the User says the want to Load from the Saved Written Index File.
            system("clear");
            cout<<"Index is being loaded from the saved file.\n\n";
            indexHandler->buildIndexFromFile(documentCount);

            // Asks if the User wants to add their own file to the Index.
            cout<<"would you like to add your own file?\n";
            cout<<"1. Yes\n";
            cout<<"2. no\n";
            cin >> recreateIndex;

            // If the User doesn't want to add a file, Exits the Search Engine.
            if (recreateIndex == "2")
            {
                cout<<"Exiting Mataince Mode.";
            }
            else
            {
                // If the User wants to add a file, lists all the possible files
                // and prompts the User to Type the name of the File they want.
                system("clear");
                cout<<"List of Possible XML Files you can Add.\n\n";
                system("ls *.xml");
                cout<<"\nPlease enter the Name of the File to add:\n";
                cin >> fileToAdd;
                documentParser = new DocumentParser(documentCount, indexHandler, fileToAdd);
                cout<<"File successfully added. Matainence Mode shutting down.";
            }

        }



    }
    else
    {
        // If no written File Index is found, begins creating the Base Index.
        cout<<"Creating the Base Index.\n";
        documentParser = new DocumentParser(documentCount, indexHandler);

        // Asks the User if they want to add their own file to the Index.
        cout<<"would you like to add your own file?\n";
        cout<<"1. Yes\n";
        cout<<"2. no\n";
        cin >> recreateIndex;
        // If the User doesn't want to add a File, Exit the Search Engine.
        if (recreateIndex == "2")
        {
            cout<<"Exiting Mataince Mode.";
        }
        else
        {
            // If the User Does want to insert a File, lists the Possible files
            // to add and prompts the User for the name of the file they would
            // like to add.
            system("clear");
            cout<<"List of Possible XML Files you can Add.\n\n";
            system("ls *.xml");
            cout<<"\nPlease enter the Name of the File to add:\n";
            cin >> fileToAdd;
            delete[] documentParser;
            documentParser = new DocumentParser(documentCount, indexHandler, fileToAdd);
            cout<<"File successfully added. Matainence Mode shutting down.";
        }
    }
    indexHandler->saveIndex(documentCount);
}
