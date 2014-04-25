/*!
 * \file AVLNode.h
 *
 * \author Taylor Ellington
 * \date 3 May 2013
 *
 *
 */

/*!
 * \struct AVLNode
 *
 * \brief Granular unit AVLTree is based upon
 *
 * \var AVLNode::left  pointer to another AVLNode that is "less" than this
 * \var AVLNode::right pointer to another AVLNode that is "more" than this
 * \var AVLNode::data  data contained in node
 * \var AVLNode::height  height of the node
 *
*
 * This struct provides the framework for connectin nodes and building
 * the data structure as well as holding the data in question
 *
 * \author Taylor Ellington
 * \date 3 May 2013
 */


struct AVLNode
{

    AVLNode * left;
    AVLNode * right;
    IndexEntry * data;
    int height;


    AVLNode()
    {
        left = NULL;
        right = NULL;
        data = new IndexEntry;
    }

};
