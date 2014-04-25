#include "AVLTree.h"

#include <sstream>

AVLTree::AVLTree()
{
    // Set root to null, if not done add will fail
    root = NULL;
}

void AVLTree::dumpData()
{
    //empty data from structure and set root to null
    _postOrder(root);
    root = NULL;
}

void AVLTree::add(string newWord, DocumentStorage * & document)
{
    // this function checks root for null, if root is null then it
    // makes a new AVLNode at root, if root is not null then checks
    // to see if newWord == what is in root,  if yes then add  document
    // if not then determine if newWord is greater or less than what is in
    // node, and then is sent to appropriate sub tree

    // check for empty tree based on empty root
    if (root == NULL)
    {
        // new AVLNode with newWord and document and a height of 1
        root = new AVLNode;

        root->data->setWord(newWord);
        root->data->addDocument(document);
        root->height = 1;

    }
    else if (root != NULL)
    {
        // there is something in the tree


        // check  to see if newWord is greater or smaller
        if (newWord < root->data->getWord())
        {
            // check if  left is null
            if (root->left == NULL)
            {
                // new node at left with newWord and document
                root->left = new AVLNode;

                root->left->data->setWord(newWord);
                root->left->data->addDocument(document);
                root->left->height = 1;
            }
            else
            {
                // recurisve add left
                _add(newWord, document, root->left);

            }

        }
        else if (newWord > root->data->getWord())
        {
            // check right for null
            if (root->right == NULL)
            {
                // new node at right with new word and document

                root->right = new AVLNode;

                root->right->data->setWord(newWord);
                root->right->data->addDocument(document);
                root->right->height = 1;
            }
            else
            {
                // recurisve add right
                _add(newWord, document, root->right);
            }
        }
        else if (newWord == root->data->getWord())
        {
            // root is newWord
            // add document
            root->data->addDocument(document);
        }

        //check for imballance


        if ((height(root->left) - height(root->right)) < -1)
        {
            if (height(root->right->left) - height(root->right->right) == -1)
            {
                rightRight(root);
            }
            else if (height(root->right->left) - height(root->right->right) == 1)
            {
                rightLeft(root);

            }
            root->height = height(root->right) + 1;
        }
        else if ((height(root->left) - height(root->right)) > 1)
        {
            if (height(root->left->left) - height(root->left->right) == -1)
            {
                leftRight(root);
            }
            else if (height(root->right->left) - height(root->right->right) == 1)
            {
                leftLeft(root);
            }
            else
            {

            }

            root->height = height(root->left) + 1;
        }
    }
    updateHeight(root);
}

void AVLTree::_add(string newWord, DocumentStorage * document, AVLNode *& node)
{
    //  functionaity is similar to add() except all instances of root have been replaced
    //  with  node, also, this call is recursive to itself meaning that it can be used
    //  to insert to the whole tree

    // newWord is smaller
    if (newWord < node->data->getWord())
    {

        // is it null?
        if (node->left == NULL)
        {
            // new Node
            node->left = new AVLNode;

            node->left->data->setWord(newWord);
            node->left->data->addDocument(document);
            node->left->height = 1;
        }
        else
        {

            // chekc out left
            _add(newWord, document, node->left);

        }

    }
    else if (newWord > node->data->getWord())
    {
        // is it greateer?


        // is it null?
        if (node->right == NULL)
        {
            // new node right
            node->right = new AVLNode;

            node->right->data->setWord(newWord);

            node->right->data->addDocument(document);
            node->right->height = 1;
        }
        else
        {
            // check right
            _add(newWord, document, node->right);
        }
    }
    else if (newWord == node->data->getWord())
    {
        // root is newWord, add document
        node->data->addDocument(document);
    }

    //check for imballance
    if ((height(node->left) - height(node->right)) < -1)
    {

        if (height(node->right->left) - height(node->right->right) == -1)
        {
            rightRight(node);
        }
        else
        {
            rightLeft(node);
        }
        node->height = height(node->right) + 1;
    }
    else if ((height(node->left) - height(node->right)) > 1)
    {
        if (height(node->left->left) - height(node->left->right) == -1)
        {
            leftRight(node);
        }
        else
        {
            leftLeft(node);
        }
        node->height = height(node->left) + 1;
    }
    else
    {
        if (height(node->left) > height(node->right))
        {
            node->height = height(node->left) + 1;
        }
        else
        {
            node->height = height(node->right) + 1;
        }

    }
    updateHeight(node);
}

vector<DocumentStorage> AVLTree::search(string term)
{
    // this fucntion and its recursive coutnetpart _search, use the
    // binary search property to look throught the tree to find either
    // a node where term exists or a node where null happens to signify
    // that term is not in the structure

    // chekc for empty root case
    if (root == NULL)
    {
        // return empty vector to signify that there is nothing here
        vector<DocumentStorage> blank;

        return blank;
    }
    else
    {
        // there is something, look for match

        if (term == root->data->getWord())
        {
            //term is in root

            return root->data->getDocuments();
        }
        else if (term < root->data->getWord())
        {
            // look for term left of root

            return _search(term, root->left);
        }
        else if (term > root->data->getWord())
        {
            // look for trem right of root
            return _search(term, root->right);
        }
        else
        {

            // if you see this...... download more ram
            cout << "THIS SHOULD NEVER HAPPEN in AVLTree::search(std::string term)" << endl;
        }
    }
};

vector<DocumentStorage> AVLTree::_search(string term, AVLNode*& Node)
{

    //this is the recursive component for searching, its functionality is similar
    // to search except that it replaces root with node

    if (Node == NULL)
    {
        // nothing else to check, return empty
        vector<DocumentStorage> blank;
        return blank;
    }
    else
    {
        if (term == Node->data->getWord())
        {

            vector<DocumentStorage> temp;
            temp = Node->data->getDocuments();

            return temp;

        }
        else if (term < Node->data->getWord())
        {

            return _search(term, Node->left);
        }
        else if (term > Node->data->getWord())
        {

            return _search(term, Node->right);
        }
        else
        {
            cout << "THIS SHOULD NEVER HAPPEN in AVLTree::_search(std::string term)" << endl;
        }
    }
}

AVLTree::~AVLTree()
{
// destructor

}

void AVLTree::inOrder()
{
// this is a debug statement and should be disabled
    if (root->left != 0)
    {
        //cout << "down left" << endl;
        //_inOrder(root->left, );
    }

    cout << root->data->getWord() << "  ";



    if (root->right != 0)
    {
        //cout << "down right" << endl;
        //_inOrder(root->right);
    }


}

void AVLTree::_inOrder(AVLNode * & node, ofstream & saveFile)
{
    //  part of file io, saves information to file INDEXFILE.save
    //  recursivly goes left, visits node, recurivly goes right
    //  during visit it prints all data in node

    if (node->left != 0)
    {
        //cout << "down left" << endl;
        _inOrder(node->left, saveFile);
    }

    saveFile << node->data->getWord();
    vector<DocumentStorage> temp = node->data->getDocuments();
    DateStamp tempStamp;
    for (int z = 0; z < temp.size(); z++)
    {
        saveFile << "\n";
        tempStamp = temp.at(z).getDate();
        saveFile << "<" << temp.at(z).getTitle();
        saveFile << "|" << temp.at(z).getAuthor();
        saveFile << "|" << tempStamp;
        saveFile << "|" << temp.at(z).getFileName();
        saveFile << "|" << temp.at(z).count << ">";

    }
    saveFile << '\n';
    if (node->right != 0)
    {
        //cout << "down right" << endl;
        _inOrder(node->right, saveFile);
    }

    //cout << "up" << endl;


}

void AVLTree::_postOrder(AVLNode*& node)
{

    // deletes avl tree using recursive callls
    //cout << node->data->getWord() << endl;

    if (node != NULL)
    {

        _postOrder(node->left);
        _postOrder(node->right);


        delete node;
    }


}

int AVLTree::height(AVLNode* node)
{
    // returns the height of a node

    // if node exists return height
    if (node != NULL)
    {
        return node->height;
    }
    else
    {
        // if node does not exist return 0
        return 0;
    }
}

void AVLTree::rightRight(AVLNode *& node)
{
    // right right rotation case
    AVLNode * temp;
    temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;

    updateHeight(node->left);
    updateHeight(node);


}

void AVLTree::rightLeft(AVLNode *& node)
{

    // right left rotation case
    AVLNode * temp;
    temp = node->right;

    node->right = temp->left;

    temp->left = node->right;

    temp->left = node->right->right;

    node->right->right = temp;

    updateHeight(node->right->right);

    updateHeight(node->right);

    rightRight(node);



    return;

}

void AVLTree::leftRight(AVLNode *& node)
{
    //cout << "leftRight" << endl;

    // left right rotation case

    AVLNode * temp;

    temp = node->left;
    node->left = temp->right;
    temp->right = node->left->left;
    node->left->left = temp;

    updateHeight(node->left->left);
    updateHeight(node->left);
    leftLeft(node);



    return;


}

void AVLTree::leftLeft(AVLNode *& node)
{
    //cout << "leftLeft" << endl;

    // left left rotation case

    AVLNode * temp;
    temp = node;
    node = node->left;
    temp->left = node->right;
    node->right = temp;

    updateHeight(node->right);
    updateHeight(node);

}

void AVLTree::updateHeight(AVLNode*& node)
{


    // updates the height of the node, uses height(node*)

    //cout << node->data->number << "***" << height(node->right) << " " << height(node->left) << endl;
    if (height(node->left) > height(node->right))
    {
        node->height = height(node->left) + 1;
    }
    else
    {
        node->height = height(node->right) + 1;
    }

}

void AVLTree::saveData(int count)
{
    // fucntion that starts the process of saving the data to file

    ofstream saveFile;
    saveFile.open("INDEXFILE.save");

    _inOrder(root, saveFile);

    saveFile<<"FileCount For System: "<<count<<endl;

}

void AVLTree::loadData(int& counter)
{
    // reads information from a INDEXFILE.save and adds it to the
    // data structure.  file io
    ifstream saveFile;
    saveFile.open("INDEXFILE.save");

    string temp;
    string currentWord;
    string author;
    string title;
    string filePath;
    string day;
    string month;
    string year;
    string count;

    int prePos;
    int postPos;

    while (saveFile.good())
    {
        getline(saveFile, temp);
        if (temp[0] == '<')
        {
            // extracts the peices of data from file
            prePos = 1;
            postPos = temp.find('|', prePos);
            title = temp.substr(prePos, postPos - prePos);


            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            author = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('/', prePos);
            month = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('/', prePos);
            day = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            year = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('|', prePos);
            filePath = temp.substr(prePos, postPos - prePos);

            prePos = postPos + 1;
            postPos = temp.find('>', prePos);
            count = temp.substr(prePos, postPos - prePos);

            DocumentStorage * tempDocument ;
            tempDocument= new DocumentStorage(title, atoi(day.c_str()), atoi(month.c_str()),
                                              atoi(year.c_str()), author, filePath );
            for (int i = 0; i < atoi(count.c_str()) ; i++)
            {
                add(currentWord, tempDocument);
            };
        }
        else if (temp[0] == 'F' && temp[4] == 'C')
        {
            stringstream ss;
            ss<<temp.substr(22,15);
            ss >> counter;

        }
        else
        {

            currentWord = temp;
        }

    }


}

