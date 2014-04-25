/*!
 * \file [filename]
 *
 * \author [your name]
 * \date
 *
 * [your comment here]
 */

/*!
 * \class [class name]
 *
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \author [your name]
 * \date
 */

 
struct AVLNode{
    AVLNode * left;
    AVLNode * right;
    IndexEntry * data;
    int height;
    
    AVLNode(){
        left = NULL;
        right = NULL;
        data = new IndexEntry;
    }
};