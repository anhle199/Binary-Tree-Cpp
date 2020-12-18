//
//  RBTree.h
//  RBTree
//
//  Created by Le Hoang Anh on 16/12/2020.
//

#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include <iostream>

using namespace std;

enum Color {RED, BLACK};

struct Node {
    int key;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

Node* createNode(int x, Color color);
Node* createRBTree(int x);

void NLR(Node* root);
void levelOrder(Node* root);

Node* search(Node* root, int x);
void insert(Node* &root, int x);
void remove(Node* &root, int x);

void removeTree(Node* &root);

#endif
