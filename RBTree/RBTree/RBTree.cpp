//
//  RBTree.cpp
//  RBTree
//
//  Created by Le Hoang Anh on 16/12/2020.
//

#include "AdditionalFunctions.h"
#include <queue>

Node* createNode(int x, Color color) {
    Node* node = new Node;

    if (node) {
        node->key = x;
        node->color = color;
        node->parent = node->left = node->right = null;
    }

    return node;
}

Node* createRBTree(int x) {
    return createNode(x, BLACK);
}

void NLR(Node* root) {
    if (root) {
        cout << "(key: " << root->key << ", color: " << colorToString(root->color) << ")" << endl;
        NLR(root->left);
        NLR(root->right);
    }
}

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << "(key: " << node->key << ", color: " << colorToString(node->color) << ")" << endl;

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

Node* search(Node* root, int x) {
    while (root && root->key != x)
        root = (root->key > x) ? root->left : root->right;

    return root;
}

void insert(Node* &root, int x) {
    Node* node = BSTInsert(root, x);
    if (node)
        fixViolateInsert(root, node);
}

void remove(Node* &root, int x) {
    Node* node = search(root, x);
    
    if (node) {
        Node* nodeDeleted = (node->left == null || node->right == null) ? node : getPredecessor(node);
        Node* childOfNodeDeleted = (nodeDeleted->left) ? nodeDeleted->left : nodeDeleted->right;

        // update child of node is deleted.
        Node* parent = nodeDeleted->parent;
        if (childOfNodeDeleted)
            childOfNodeDeleted->parent = parent;

        if (parent == null)
            root = childOfNodeDeleted;
        else {
            if (nodeDeleted == nodeDeleted->parent->left)
                nodeDeleted->parent->left = childOfNodeDeleted;
            else
                nodeDeleted->parent->right = childOfNodeDeleted;
        }
        //...

        if (node != nodeDeleted)
            node->key = nodeDeleted->key;
        if (nodeDeleted->color == BLACK)
            fixViolateDelete(root, childOfNodeDeleted, parent);

        delete nodeDeleted;
    }
}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = null;
    }
}
