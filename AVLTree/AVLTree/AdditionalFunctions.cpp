//
//  AdditionalFunctions.cpp
//  AVLTree
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "AdditionalFunctions.h"

int calculateBalanceFactor(Node* root) {
    if (root == nullptr)
        return BALANCE;

    int heightSubTreeLeft = (root->left ? root->left->height : 0);
    int heightSubTreeRight = (root->right ? root->right->height : 0);
    return heightSubTreeRight - heightSubTreeLeft;
}

int heightOfNode(Node* root) {
    if (root == nullptr)
        return 0;

    int heightLeft = (root->left ? root->left->height : 0);
    int heighRight = (root->right ? root->right->height : 0);
    return max(heightLeft, heighRight) + 1;
}

void insertImp(Node* &root, int x, bool &insertSuccessful) {
    if (root) {
        if (root->key == x) {
            cout << "This value already exists." << endl;
        } else {
            if (root->key > x)
                insertImp(root->left, x, insertSuccessful);
            else
                insertImp(root->right, x, insertSuccessful);


            if (insertSuccessful) {
                root->height = heightOfNode(root);
                rebalanceTree(root);
            }
        }
    } else {
        root = createNode(x);
        insertSuccessful = true;
    }
}

void searchToDelete(Node* &p, Node* &q) {
    if (q->right) {
        searchToDelete(p, q->right);
        q->height = heightOfNode(q);

        rebalanceTree(q);
    } else {
        p->key = q->key;
        p = q;
        q = q->left;
    }
}

void removeImp(Node* &root, int x, bool &removeSuccessful) {
    if (root) {
        if (root->key == x) {
            Node* p = root;

            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            else
                searchToDelete(p, root->left);

            delete p;
            removeSuccessful = true;
        } else if (root->key > x) {
            removeImp(root->left, x, removeSuccessful);
        } else {
            removeImp(root->right, x, removeSuccessful);
        }

        if (removeSuccessful && root) {
            root->height = heightOfNode(root);
            rebalanceTree(root);
        }
    }
}
