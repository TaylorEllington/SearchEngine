
#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
}

void AVLTree::dumpData() {
}

void AVLTree::saveData() {
}

void AVLTree::add(string newWord, Document * document) {
    cout << "nurrr" << document->getAuthor() << endl;
    
    
    if (root == NULL) {

        root = new AVLNode;

        root->data->setWord(newWord);
        root->data->addDocument(document);
        root->height = 1;

    } else if (root != NULL) {


        if (newWord < root->data->getWord()) {

            if (root->left == NULL) {

                root->left = new AVLNode;

                root->left->data->setWord(newWord);
                root->left->data->addDocument(document );
                root->left->height = 1;
            } else {

                _add(newWord, document, root->left);

            }

        } else if (newWord > root->data->getWord()) {

            if (root->right == NULL) {

                root->right = new AVLNode;

                root->right->data->setWord(newWord);
                root->right->height = 1;
            } else {

                _add(newWord, document, root->right);
            }
        } else if (newWord == root->data->getWord()) {
           
            root->data->addDocument(document);
        }

        //check for imballance



        if ((height(root->left) - height(root->right)) < -1) {

            if (height(root->right->left) - height(root->right->right) == -1) {
                rightRight(root);
            } else if (height(root->right->left) - height(root->right->right) == 1) {
                rightLeft(root);

            }

            root->height = height(root->right) + 1;
        } else if ((height(root->left) - height(root->right)) > 1) {

            if (height(root->left->left) - height(root->left->right) == -1) {
                leftRight(root);
            } else if (height(root->right->left) - height(root->right->right) == 1) {
                leftLeft(root);
            } else {

            }


            root->height = height(root->left) + 1;
        }
    }
    updateHeight(root);
}

void AVLTree::_add(string newWord, Document * document, AVLNode *& node) {
    if (newWord < node->data->getWord()) {

        if (node->left == NULL) {

            node->left = new AVLNode;

            node->left->data->setWord(newWord);
            node->left->data->addDocument(document);
            node->left->height = 1;
        } else {

            _add(newWord, document, node->left);

        }

    } else if (newWord > node->data->getWord()) {

        if (node->right == NULL) {

            node->right = new AVLNode;

            node->right->data->setWord(newWord);

            node->right->data->addDocument(document);
            node->right->height = 1;
        } else {

            _add(newWord, document, node->right);
        }
    } else if (newWord == node->data->getWord()) {
        
        node->data->addDocument(document);
    }

    //check for imballance


    if ((height(node->left) - height(node->right)) < -1) {

        if (height(node->right->left) - height(node->right->right) == -1) {
            rightRight(node);
        } else if (height(node->right->left) - height(node->right->right) == 1) {

            rightLeft(node);



        }

        node->height = height(node->right) + 1;
    } else if ((height(node->left) - height(node->right)) > 1) {

        if (height(node->left->left) - height(node->left->right) == -1) {
            leftRight(node);
        } else if (height(node->right->left) - height(node->right->right) == 1) {
            leftLeft(node);
        }

        node->height = height(node->left) + 1;
    } else {
        if (height(node->left) > height(node->right)) {
            node->height = height(node->left) + 1;
        } else {
            node->height = height(node->right) + 1;
        }


    }
    updateHeight(node);
}

vector<Document> AVLTree::search(string term) {
    if (root == NULL) {
        vector<Document> blank;
        
        return blank;
    } else {
        if (term == root->data->getWord()) {
            return root->data->getDocuments();
        } else if (term < root->data->getWord()) {
            return _search(term, root->left);
        } else if (term > root->data->getWord()) {
            return _search(term, root->right);
        } else {
            cout << "THIS SHOULD NEVER HAPPEN in AVLTree::search(std::string term)" << endl;
        }
    }
};

vector<Document> AVLTree::_search(string term, AVLNode*& Node) {
    if (Node == NULL) {
        vector<Document> blank;
        return blank;
    } else {
        if (term == Node->data->getWord()) {
            vector<Document> temp;
            temp = Node->data->getDocuments();
            cout << "~~~~~~" <<temp[0].getAuthor()<< endl;
            return Node->data->getDocuments();
           
        } else if (term < Node->data->getWord()) {
            return _search(term, Node->left);
        } else if (term > Node->data->getWord()) {
            return _search(term, Node->right);
        } else {
            cout << "THIS SHOULD NEVER HAPPEN in AVLTree::_search(std::string term)" << endl;
        }

    }
}

AVLTree::~AVLTree() {

}

void AVLTree::inOrder() {
    if (root->left != 0) {
        cout << "down left" << endl;
        _inOrder(root->left);
    }

    cout << root->data->getWord() << "  ";



    if (root->right != 0) {
        cout << "down right" << endl;
        _inOrder(root->right);
    }


}

void AVLTree::_inOrder(AVLNode * & node) {
    if (node->left != 0) {
        cout << "down left" << endl;
        _inOrder(node->left);
    }

    cout << node->data->getWord() << "  ";

    if (node->right != 0) {
        cout << "down right" << endl;
        _inOrder(node->right);
    }

    cout << "up" << endl;


}

int AVLTree::height(AVLNode* node) {
    if (node != NULL) {
        return node->height;
    } else {
        return 0;
    }
}

void AVLTree::rightRight(AVLNode *& node) {
    cout << "rightRight" << endl;
    AVLNode * temp;
    temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;

    updateHeight(node->left);
    updateHeight(node);


}

void AVLTree::rightLeft(AVLNode *& node) {
    cout << "rightLeft" << endl;

    AVLNode * temp;

    temp = node->right;
    node->right = temp->left;
    temp->left = 0;
    node->right->right = temp;

    updateHeight(node->right->right);
    updateHeight(node->right);
    rightRight(node);




    return;

}

void AVLTree::leftRight(AVLNode *& node) {
    cout << "leftRight" << endl;

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

void AVLTree::leftLeft(AVLNode *& node) {
    cout << "leftLeft" << endl;

    AVLNode * temp;
    temp = node;
    node = node->left;
    temp->left = node->right;
    node->right = temp;

    updateHeight(node->right);
    updateHeight(node);

}

void AVLTree::updateHeight(AVLNode*& node) {

    //cout << node->data->number << "***" << height(node->right) << " " << height(node->left) << endl;
    if (height(node->left) > height(node->right)) {
        node->height = height(node->left) + 1;
    } else {
        node->height = height(node->right) + 1;
    }

}