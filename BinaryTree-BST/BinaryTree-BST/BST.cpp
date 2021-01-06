//
//  BST.cpp
//  BinaryTree-BST
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "BST.h"

enum Direction {LEFT, RIGHT};

// This function to find an element to replacement the removed element (p).
// Case: p have two sub-tree.
void searchToDelete(Node* &p, Node* &q);
void searchToDelete(Node* &p, Node* &q) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

//    if (q->left)
//        searchToDelete(p, q->left);
//    else {
//        p->key = q->key;
//        p = q;
//        q = q->right;
//    }

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    Node* previousSuccessor = nullptr;
    Node* successor = q;

    while (successor->right) {
        previousSuccessor = successor;
        successor = successor->right;
    }

    p->key = successor->key;
    p = successor;
    if (previousSuccessor)
        previousSuccessor->right = successor->left;

    // ----------------------------------
}

Node* createTree(int a[], int n) {
    Node* root = nullptr;

    for (int i = 0; i < n; i++)
        insert(root, a[i]);

    return root;
}

bool isBST(Node* root) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;

        if (left == nullptr && right == nullptr)
            return true;

        int key = root->key;
        if (left == nullptr)
            return (key >= right->key) ? false : isBST(right);
        if (right == nullptr)
            return (key <= left->key) ? false : isBST(left);
        if (key <= left->key || key >= right->key)
            return false;

        return isBST(left) && isBST(right);
    }

    return false;
}

bool isFullBST(Node* root) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;

        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        int key = root->key;

        if (key <= left->key || key >= right->key)
            return false;
        return isFullBST(left) && isFullBST(right);
    }

    return false;
}

Node* search(Node* root, int x) {
    while (root) {
        if (root->key == x)
            return root;
        if (root->key > x)
            root = root->left;
        else
            root = root->right;
    }

    return nullptr;
}

void insert(Node* &root, int x) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root) {
    //        if (root->key == x)
    //            return;
    //        if (root->key > x)
    //            insert(root->left, x);
    //        else
    //            insert(root->right, x);
    //    } else {
    //        root = createNode(x);
    //    }

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    if (root == nullptr) {
        root = createNode(x);
        return;
    }

    Node* previous = nullptr;
    Node* node = root;
    Direction direct = LEFT;

    while (node) {
        if (node->key == x)
            return;

        if (node->key > x) {
            direct = LEFT;
            previous = node;
            node = node->left;
        } else {
            direct = RIGHT;
            previous = node;
            node = node->right;
        }
    }

    if (direct == LEFT)
        previous->left = createNode(x);
    else
        previous->right = createNode(x);

    // ----------------------------------
}

// Remove a Node with given value from a given Binary Search Tree.
void remove(Node* &root, int x) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root) {
    //        if (root->key == x) {
    //            Node* p = root;
    //
    //            if (root->left == nullptr)
    //                root = root->right;
    //            else if (root->right == nullptr)
    //                root = root->left;
    //            else
    //                searchToDelete(p, root->left);
    //
    //            delete p;
    //        }
    //
    //        if (root->key > x)
    //            remove(root->left, x);
    //        else
    //            remove(root->right, x);
    //    }

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    if (root == nullptr)
        return;

    Node* node = root;

    while (node) {
        if (node->key == x) {
            Node* nodeDeleted = node;

            if (node->left == nullptr)
                node = node->right;
            else if (node->right == nullptr)
                node = node->left;
            else
                searchToDelete(nodeDeleted, node->left);

            if (root->key == x)
                root = node;

            delete nodeDeleted;
            return;
        }

        node = (node->key > x) ? node->left : node->right;
    }

    // ----------------------------------
}

// Completely remove a given Binary Search Tree.
void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}

// Count the number of Node from a given Binary Search Tree which key value
// is less than a given value.
int countLess(Node* root, int x) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root == nullptr)
    //        return 0;
    //
    //    if (root->key == x)
    //        return countNode(root->left);
    //    if (root->key < x)
    //        return 1 + countNode(root->left) + countLess(root->right, x);
    //    return countLess(root->left, x);

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    int count = 0;
    while (root) {
        if (root->key == x) {
            count += countNode(root->left);
            break;
        } else if (root->key < x) {
            count += 1 + countNode(root->left);
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return count;

    // ----------------------------------
}

// Count the number of Node from a given Binary Search Tree which key value
// is greater than a given value.
int countGreater(Node* root, int x) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root == nullptr)
    //        return 0;
    //
    //    if (root->key == x)
    //        return countNode(root->right);
    //    if (root->key > x)
    //        return 1 + countNode(root->right) + countGreater(root->left, x);
    //    return countGreater(root->right, x);

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    int count = 0;
    while (root) {
        if (root->key == x) {
            count += countNode(root->right);
            break;
        } else if (root->key > x) {
            count += 1 + countNode(root->right);
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return count;

    // ----------------------------------
}
