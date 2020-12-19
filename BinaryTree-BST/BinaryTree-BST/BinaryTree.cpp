//
//  BinaryTree.cpp
//  BinaryTree-BST
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "BST.h"
#include <queue>

// Initialize a Node from a given value.
Node* createNode(int data) {
    Node* p = new Node;
    p->key = data;
    p->left = p->right = nullptr;

    return p;
}

// Pre-order Traversal.
void NLR(Node* root) {
    if (root) {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

// In-order Traversal.
void LNR(Node* root) {
    if (root) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

// Post-order Traversal.
void LRN(Node* root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

// Print all nodes of a specify level of Binary Tree.
void specifyLevelOrder(Node* root, int level) {
    if (root == nullptr)
        return;

    if (level == 0)
        cout << root->key << " ";
    else {
        specifyLevelOrder(root->left, level - 1);
        specifyLevelOrder(root->right, level - 1);
    }
}

// Level-order Traversal.
// Print all value of nodes from left to right by each level.

void levelOrder(Node* root) {
    // -------------------------------------------------------------------------------
    // |    Reference: https://www.geeksforgeeks.org/level-order-tree-traversal/     |
    // -------------------------------------------------------------------------------



    // ----------------------------------------------------------
    // |                                                        |
    // |                        Version 1                       |
    // |    - Uses the function to print each specify level.    |
    // |    - Time complexity: O(n^2).                          |
    // |    - Space complexity: O(n).                           |
    // |                                                        |
    // ----------------------------------------------------------

    //    int level = level(root);
    //    for (int i = 0; i <= level; i++)
    //        specifyLevelOrder(root, i);

    // ----------------------------------------------------------



    // **********************************************************



    // ----------------------------------------------------------
    // |                                                        |
    // |                        Version 2                       |
    // |                - Uses the queue structure.             |
    // |                - Time complexity: O(n).                |
    // |                - Space complexity: O(n).               |
    // |                                                        |
    // ----------------------------------------------------------

    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        cout << node->key << " ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }

    // ----------------------------------------------------------
}

int level(Node* root) {
    return height(root) - 1;
}

int levelOfNode(Node* root, Node* p) {
    if (p == nullptr || search(root, p->key) == nullptr)
        return -1;

    if (root->key == p->key)
        return 0;
    if (root->key > p->key)
        return 1 + levelOfNode(root->left, p);
    else
        return 1 + levelOfNode(root->right, p);
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int heightOfNodeHasValue(Node* root, int value) {
    Node* p = search(root, value);
    return p ? height(p) : -1;
}

int countNode(Node* root) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root == nullptr)
    //        return 0;
    //
    //    return 1 + countNode(root->left) + countNode(root->right);

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    int count = 0;

    if (root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            ++count;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return count;

    // ----------------------------------
}

int countLeaf(Node* root) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root == nullptr)
    //        return 0;
    //    if (root->left == nullptr && root->right == nullptr)
    //        return 1;
    //
    //    return countLeaf(root->left) + countLeaf(root->right);

    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    int count = 0;

    if (root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->left == nullptr && node->right == nullptr)
                ++count;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return count;

    // ----------------------------------
}

int sumAllNodes(Node* root) {
    // ----------------------------------
    // |                                |
    // |    Version 1: recursive.       |
    // |                                |
    // ----------------------------------

    //    if (root == nullptr)
    //        return 0;
    //
    //    return root->key + sumAllNodes(root->left) + sumAllNodes(root->right);


    // ----------------------------------



    // **********************************



    // ----------------------------------
    // |                                |
    // |    Version 2: for-loop.        |
    // |                                |
    // ----------------------------------

    int sum = 0;

    if (root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            sum += node->key;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return sum;

    // ----------------------------------
}
