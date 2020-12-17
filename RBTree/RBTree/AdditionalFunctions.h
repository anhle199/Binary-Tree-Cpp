//
//  AdditionalFunctions.h
//  RBTree
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#ifndef ADDITIONAL_FUNCTIONS_H_
#define ADDITIONAL_FUNCTIONS_H_

#include "RBTree.h"

#define null    nullptr

#define LEFT    true
#define RIGHT   false

typedef bool    Direction;

string colorToString(Color color);

Node* getPredecessor(Node* node);
Node* getUncle(Node* node);
Node* getSibling(Node* node, Node* parent);
void reverseColor(Node* node);

Node* BSTInsert(Node* &root, int x);
void rotateLeft(Node* &root, Node* &node);
void rotateRight(Node* &root, Node* &node);

void fixViolateInsert(Node* &root, Node* &x);

void fixViolateDeleteForSiblingIsLeftChild(Node* &root, Node* &sibling, Node* &parent);
void fixViolateDeleteForSiblingIsRightChild(Node* &root, Node* &sibling, Node* &parent);
void fixViolateDelete(Node* &root, Node* &x, Node* &parent);

#endif
