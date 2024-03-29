/**
 * Defines the BST and BSTNode classes.
 * By MOKT (Max Ovsiankin, Ori Klein, Keivan Safavi, Tomer Erlich)
 */
#ifndef __BST_H
#define __BST_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Food.h"

using namespace std;

/**
 * Represents a node in a binary search tree.
 */
template <class Type>
class BSTNode {
 private:
  Type data;

 public:
  BSTNode *right;
  BSTNode *left;
  BSTNode(Type t);
  void setData(Type d);
  Type getData();
};

/**
 * Represents a binary search tree that is balanced using the AVL method.
 */
template <class Type>
class BST {
 private:
  BSTNode<Type> *root;
  int size;

  /**
  The [sub]tree is shorter after a deletion on the left branch.
  If necessary, balance the tree by rotating.
  @Pre:	tree is shorter
  @post	balance restored
  @return:	new root
  */
  BSTNode<Type> *deleteRightBalance(BSTNode<Type> *subRoot);

  /**
  The [sub]tree is shorter after a deletion on the right branch.
  If necessary, balance the tree by rotating.
  @Pre:	tree is shorter
  @post	balance restored
  @return:	new root
  */
  BSTNode<Type> *deleteLeftBalance(BSTNode<Type> *subRoot);

  /**
  This algorithm is entered when the root is left high(the left subtree is
  higher than the right subtree).
  @pre:	root is a pointer to the root of the subtree
  @post:	root has been updated (if necessary)
  */
  BSTNode<Type> *leftBalance(BSTNode<Type> *subRoot);

  /**
  This algorithm is entered when the root is right high(the right subtree is
  higher than the left subtree).
  @pre:	root is a pointer to the root of the subtree
  @post:	root has been updated (if necessary)
  */
  BSTNode<Type> *rightBalance(BSTNode<Type> *subRoot);

  /**
  This algorithm exchanges pointers to rotate the tree right
  @pre:	root points to tree to be rotated
  @post:	node rotated and root updated
  */
  BSTNode<Type> *rotateLeft(BSTNode<Type> *subRoot);

  /**
  This algorithm exchanges pointers to rotate the tree left
  @pre:	root points to tree to be rotated
  @post:	node rotated and root updated
  */
  BSTNode<Type> *rotateRight(BSTNode<Type> *subRoot);

 public:
  /**
   * Constructs a new BST.
   */
  BST();

  /**
   * Gets the root node of the BST.
   */
  BSTNode<Type> *getRoot();

  /**
   * Inserts the given node into the bst.
   */
  void insert(Type data);

  /**
   * Gets the BST node that is holds the given data.
   */
  BSTNode<Type> *get(Type data);

  /**
  Use recursion to insert a node into an AVL tree
  @Pre: 	root is pointer to first node in AVL tree/subtree
  @pre:	newData is pointer to new node to be inserted
  @post:	new node has been inserted
  @return:	root returned recursively up the tree
  */
  BSTNode<Type> *insert(BSTNode<Type> *subRoot, Type data);

  /**
   * Gets the node of a Type data if exists
   */
  BSTNode<Type> *get(BSTNode<Type> *subRoot, Type data);

  /**
  This algorithm deletes a node from an AVL tree and rebalances if necessary
  @Pre:	root is a pointer to a [sub]tree
                  data is the key of node to be deleted
                  success is a reference to a boolean variable
  @Post:	node deleted if found, tree unchanged if not.
                  success set true or false
  @return:	pointer to root of [potential] new subtree
  */
  BSTNode<Type> *AVLDelete(BSTNode<Type> *subRoot, Type data, bool success);

  /**
   * Return vector in sorted order
   */
  vector<Type> *getSorted(BSTNode<Type> *subRoot);

  /**
   * Gets the hight of the BST.
   */
  int getHeight(BSTNode<Type> *subRoot);

  /**
   * Checks if the BST is empty.
   */
  bool isEmpty();
};

#endif  // !__BST_H
