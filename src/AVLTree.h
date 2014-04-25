/*!
 * \file AVLTree.h
 *
 * \author Cameron Keith
 * \date 5 May 2013
 *
 */

/*!
* \class AVLTree
*
* \brief AVLTree Storage Class.
*
* Inherits from IndexInterface class and is one of the two possible
* storage versions for Index.
*
* \author Taylor Ellington
* \date 4 May 2013
*/

#ifndef AVLTREE_H
#define	AVLTREE_H
//#include <iostream>

#include "IndexInterface.h"
#include "IndexEntry.h"
#include "AVLNode.h"
#include <fstream>
#include <cstdlib>

using namespace std;



class AVLTree : public IndexInterface
{
public:
    /*!
     * \brief Default AVLTree Constructor.
     *
     * \warning Don't Use if possible.
     */
    AVLTree();

    /*!
     * \brief Destructor for AVLTree.
     *
     * \warning Don't call unless necessary.
     */
    virtual ~AVLTree();

    /*!
     * \brief Add a Word to the AVLTree.
     *
     * \param word Word to add to Tree.
     * \param document Document where the Word is found.
     * \return Void
     */
    void add(string newWord, DocumentStorage * & document);

    /*!
     * \brief Delete Tree.
     *
     * \return Void
     */
    void dumpData();

    /*!
     * \brief Save the Tree to a file on the HardDisk.
     *
     * \param count Count of Documents that are in the Index.
     * \return Void
     */
    void saveData(int);

    /*!
     * \brief Load the Index from a File on the HardDisk.
     *
     * \param counter Count of Documents being read into the Index.
     * \return Void
     */
    void loadData(int&);

    /*!
     * \brief Searchs for a Word in the Tree.
     *
     * \param term Word to be searched for.
     * \return Vector of DocumentStorage objects that the search term is found in.
     */
    vector<DocumentStorage> search(string term);

    /*!
     * \brief An inorder traversal of the Tree.
     *
     * \return Void
     */
    void inOrder();



private:

    /// Root of the Tree.
    AVLNode * root;

    /*!
     * \brief Recursive Add that parses the Tree.
     *
     * \param newWord Word to Add.
     * \param docuemt DocumentStorage object where the word is found.
     * \param node Current Node in the Tree.
     * \return Void
     */
    void _add( string newWord, DocumentStorage *document, AVLNode *& node);

    /*!
     * \brief Recursive inorder traversal to print the Tree to file.
     *
     * \param node Current node in the tree.
     * \param saveFile OutFileStream to where the file is to be printed.
     * \return Void
     */
    void _inOrder(AVLNode * & node, ofstream & saveFile);

    /*!
     * \brief Gets the Heigth of a Node.
     *
     * \param node The Node of whose heigth is being retrieved.
     * \return An Integer of the Height of a node.
     */
    int height(AVLNode * node);

    /*!
     * \brief CASE 4 Rotation
     *
     * \param node Node Alpha, where the imbalance is occuring.
     * \return Void
     */
    void rightRight(AVLNode *& node);

    /*!
     * \brief CASE 3 Rotation
     *
     *
     * \param node Node Alpha, where the imbalance is occuring.
    * \return Void
     */
    void rightLeft(AVLNode *& node);

    /*!
     * \brief CASE 2 Rotation
     *
     * \param node Node Alpha, where the imbalance is occuring.
     * \return Void
     */
    void leftRight(AVLNode *& node);

    /*!
     * \brief CASE 1 Rotation
     *
     * \param node Node Alpha, where the imbalance is occuring.
     * \return Void
     */
    void leftLeft(AVLNode *& node);

    /*!
     * \brief Updates the Height of a Node.
     *
     * \param node The Node whose heigth is being updated.
     * \return Void
     */
    void updateHeight(AVLNode *& node);

    /*!
     * \brief Recursive Deletion of the Tree.
     *
     * \param node Current Node in the Tree.
     * \return Void
     */
    void _postOrder(AVLNode *& node);

    /*!
     * \brief [brief description]
     *
     * [detailed description]
     *
     * \param[in] [name of input parameter] [its description]
     * \param[out] [name of output parameter] [its description]
     * \return A vector of DocumentStorage objects that contain the search term.
     */
    vector<DocumentStorage>  _search(string term, AVLNode *& Node);


};



#endif	/* AVLTREE_H */

