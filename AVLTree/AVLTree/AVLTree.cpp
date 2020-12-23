//
//  AVLTree.cpp
//  AVLTree
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "AdditionalFunctions.h"
#include <queue>

Node* createNode(int data) {
    Node* p = new Node;

    if (p) {
        p->key = data;
        p->left = p->right = nullptr;
        p->height = 1;
    }

    return p;
}

bool isAVL(Node* root) {
    if (root == nullptr)
        return false;


    int balanceFactor = calculateBalanceFactor(root);
    if (abs(balanceFactor) > 1)
        return false;

    Node* left = root->left;
    Node* right = root->right;
    if (left == nullptr && right == nullptr)
        return true;

    int key = root->key;
    if (left == nullptr)
        return key < right->key;
    if (right == nullptr)
        return key > left->key;
    if (key <= left->key || key >= right->key)
        return false;


    return isAVL(left) && isAVL(right);
}

void NLR(Node* root) {
    if (root) {
        cout << "(Key: " << root->key
            << ", Height: " << root->height << ")" << endl;

        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(Node* root) {
    if (root) {
        LNR(root->left);
        cout << "(Key: " << root->key
            << ", Height: " << root->height << ")" << endl;
        LNR(root->right);
    }
}

void LRN(Node* root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << "(Key: " << root->key
            << ", Height: " << root->height << ")" << endl;
    }
}

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        cout << "(Key: " << node->key
        << ", Height: " << node->height << ")" << endl;
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }
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
    bool success = false;
    insertAndFixHeight(root, x, success);
}

void remove(Node* &root, int x) {
    bool success = false;
    removeAndFixHeight(root, x, success);
}

void rotateLeft(Node* &root) {
    if (root && root->right) {
        Node* right = root->right;

        // update height after rotate.
        int balanceFactor = calculateBalanceFactor(root->right);
        switch (balanceFactor) {
            case BALANCE:
                --(root->height);
                ++(right->height);
                break;
            case RIGHT_DEVIATION:
                root->height -= 2;
                break;
            default:
                break;
        }

        // rotate.
        root->right = right->left;
        right->left = root;
        root = right;
    }
}

void rotateRight(Node* &root) {
    if (root && root->left) {
        Node* left = root->left;

        // update height after rotate.
        int balanceFactor = calculateBalanceFactor(root->left);
        switch (balanceFactor) {
            case BALANCE:
                --(root->height);
                ++(left->height);
                break;
            case LEFT_DEVIATION:
                root->height -= 2;
                break;
            default:
                break;
        }

        // rotate.
        root->left = left->right;
        left->right = root;
        root = left;
    }
}

void rotateLeftRight(Node* &root) {
    if (root && root->left && root->left->right) {
        Node* T1 = root->left;
        Node* T2 = T1->right;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // rotate ==> sub-tree left.
        T1->right = T2->left;
        T2->left = T1;

        // rotate ==> sub-tree right.
        root->left = T2->right;
        T2->right = root;

        root = T2;
    }
}

void rotateRightLeft(Node* &root) {
    if (root && root->right && root->right->left) {
        Node* T1 = root->right;
        Node* T2 = T1->left;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // rotate ==> sub-tree left.
        T1->left = T2->right;
        T2->right = T1;

        // rotate ==> sub-tree right.
        root->right = T2->left;
        T2->left = root;

        root = T2;
    }
}

void rebalanceLeft(Node* &root) {
    if (root && root->left) {
        int balanceFactor = calculateBalanceFactor(root->left);

        switch (balanceFactor) {
            case LEFT_DEVIATION:
            case BALANCE:
                rotateRight(root);
                break;
            case RIGHT_DEVIATION:
                rotateLeftRight(root);
                break;
            default:
                break;
        }
    }
}

void rebalanceRight(Node* &root) {
    if (root && root->right) {
        int balanceFactor = calculateBalanceFactor(root->right);

        switch (balanceFactor) {
            case RIGHT_DEVIATION:
            case BALANCE:
                rotateLeft(root);
                break;
            case LEFT_DEVIATION:
                rotateRightLeft(root);
                break;
            default:
                break;
        }
    }
}

void rebalanceTree(Node* &root) {
    int balanceFactor = calculateBalanceFactor(root);
    if (balanceFactor > RIGHT_DEVIATION) // right deviation.
        rebalanceRight(root);
    else if (balanceFactor < LEFT_DEVIATION) // left deviation.
        rebalanceLeft(root);
}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}
