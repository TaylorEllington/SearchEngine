
// File:   main.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include <cstdlib>

#include "AVLTree.h"
#include "IndexHandler.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    IndexHandler test(true);
    
    test.newFile("file 1", 1, 1, 1991, "taylor Ellington");
    test.addWord("bob");
    test.addWord("sanna");
    test.addWord("gnerard");
    test.addWord("bob");
 
    vector<Document> testz;
    testz = test.search("bob");
    cout << "*(*(*(*" <<testz.size() << endl;
    for(int z = 0; z < testz.size(); z++){
        cout << z <<"  "<<testz.at(z).getAuthor() << endl;
    }
    
    

    return 0;
}

