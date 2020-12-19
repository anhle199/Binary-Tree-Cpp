//
//  AVLTree.h
//  AVLTree
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Initialize a Node from a given value.
Node* createNode(int data);

// Determine if a given Binary Tree is an AVL Tree.
bool isAVL(Node* root);

// Pre-order Traversal (key and height of Node is required).
void NLR(Node* root);

// In-order Traversal (key and height of Node is required).
void LNR(Node* root);

// Post-order Traversal (key and height of Node is required).
void LRN(Node* root);

// Level-order Traversal (key and height of Node is required).
void levelOrder(Node* root);

// Find and return a Node with given value from a given AVL Tree.
Node* search(Node* root, int x);

// Add a Node with given value into a given AVL Tree.
// Notify if the given value existed.
void insert(Node* &root, int x);

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void remove(Node* &root, int x);

// Case: the right sub-tree is skewed right or balanced.
void rotateLeft(Node* &root);

// Case: the left sub-tree is skewed left or balanced.
void rotateRight(Node* &root);

// Case: the left sub-tree is skewed right.
void rotateLeftRight(Node* &root);

// Case: the right sub-tree is skewed left.
void rotateRightLeft(Node* &root);

// Rebalanced the left sub-tree of the AVL tree.
void rebalanceLeft(Node* &root);

// Rebalanced the right sub-tree of the AVL tree.
void rebalanceRight(Node* &root);

// Rebalanced the AVL tree.
void rebalanceTree(Node* &root);

// Completely remove a given AVL Tree.
void removeTree(Node* &root);

#endif

