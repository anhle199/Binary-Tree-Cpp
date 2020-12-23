//
//  AdditionalFunctions.cpp
//  AVLTree
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "AdditionalFunctions.h"

int calculateBalanceFactor(Node* node) {
    if (node == nullptr)
        return BALANCE;

    int heightLeftSubTree = (node->left ? node->left->height : 0);
    int heightRightSubTree = (node->right ? node->right->height : 0);
    return heightRightSubTree - heightLeftSubTree;
}

int heightOfNode(Node* node) {
    if (node == nullptr)
        return 0;

    int heightLeftSubTree = (node->left ? node->left->height : 0);
    int heightRightSubTree = (node->right ? node->right->height : 0);
    return max(heightLeftSubTree, heightRightSubTree) + 1;
}

void insertAndFixHeight(Node* &root, int x, bool &success) {
    if (root == nullptr) {
        root = createNode(x);
        success = true;
    }

    if (root->key == x)
        return;
    if (root->key > x)
        insertAndFixHeight(root->left, x, success);
    else
        insertAndFixHeight(root->right, x, success);

    if (success) {
        root->height = heightOfNode(root);
        rebalanceTree(root);
    }
}

void searchToDelete(Node* &nodeDeleted, Node* &successor) {
    if (successor->left) {
        searchToDelete(nodeDeleted, successor->left);
        successor->height = heightOfNode(successor);

        rebalanceTree(successor);
    } else {
        nodeDeleted->key = successor->key;
        nodeDeleted = successor;
        successor = successor->right;
    }
}

void removeAndFixHeight(Node* &root, int x, bool &success) {
    if (root == nullptr)
        return;

    if (root->key > x)
        removeAndFixHeight(root->left, x, success);
    else if (root->key < x)
        removeAndFixHeight(root->right, x, success);
    else {
        Node* p = root;

        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
            searchToDelete(p, root->right); // successor.

        delete p;
        success = true;
        return;
    }

    if (success && root) {
        root->height = heightOfNode(root);
        rebalanceTree(root);
    }
}
