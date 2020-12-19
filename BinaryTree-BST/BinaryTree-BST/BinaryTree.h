//
//  BinaryTree.h
//  BinaryTree-BST
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Initialize a Node from a given value.
Node* createNode(int data);

// Pre-order Traversal.
void NLR(Node* root);

// In-order Traversal.
void LNR(Node* root);

// Post-order Traversal.
void LRN(Node* root);

// Level-order Traversal.
void levelOrder(Node* root);

// Calculate the level of a given Binary Tree.
int level(Node* root);

// Calculate the level of a given Node.
int levelOfNode(Node* root, Node* p);

// Calculate the height of a given Binary Tree.
int height(Node* root);

// Calculate the height of a Node with given value.
// Returns -1 if value not exist.
int heightOfNodeHasValue(Node* root, int value);

// Count the number of Node from a given Binary Tree.
int countNode(Node* root);

// Count the number leaves from a given Binary Tree.
int countLeaf(Node* root);

// Calculate the total value of all Nodes from a given Binary Tree.
int sumAllNodes(Node* root);

#endif
