//
//  AdditionalFunctions.cpp
//  RBTree
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#include "AdditionalFunctions.h"

string colorToString(Color color) {
    return color == RED ? "red" : "black";
}

Node* getPredecessor(Node* node) {
    Node* predecessor = null;

    if (node && node->left) {
        predecessor = node->left;

        while (predecessor->right)
            predecessor = predecessor->right;
    }

    return predecessor;
}

Node* getUncle(Node* node) {
    Node* uncle = null;

    if (node && node->parent && node->parent->parent) {
        Node* grandparent = node->parent->parent;
        uncle = (grandparent->left == node->parent) ? grandparent->right : grandparent->left;
    }

    return uncle;
}

Node* getSibling(Node* node, Node* parent) {
    Node* sibling = null;

    if (parent) {
        if (node == parent->left)
            sibling = parent->right;
        else
            sibling = parent->left;
    }

    return sibling;
}

void reverseColor(Node* node) {
    if (node)
        node->color = !node->color;
}

Node* BSTInsert(Node* &root, int x) {
    if (root == null) {
        root = createNode(x, BLACK);
        return root;
    }

    Direction direct = LEFT;
    Node* parent = null;
    Node* node = root;

    while (node) {
        if (node->key == x)
            return null;
        if (node->key > x) {
            parent = node;
            direct = LEFT;
            node = node->left;
        } else {
            parent = node;
            direct = RIGHT;
            node = node->right;
        }
    }

    node = createNode(x, RED);
    node->parent = parent;

    if (direct == LEFT)
        parent->left = node;
    else
        parent->right = node;

    return node;
}

void rotateLeft(Node* &root, Node* &node) {
    if (root && node && node->right) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        // update parent of left child of rightChild of `node`.
        if (rightChild->left)
            rightChild->left->parent = node;

        // update parent of rightChild.
        rightChild->parent = node->parent;
        if (node->parent == null) // update root of RBT if `node` is root.
            root = rightChild;
        else {
            if (node->parent->left == node)
                node->parent->left = rightChild;
            else
                node->parent->right = rightChild;
        }

        // update left child of rightChild.
        rightChild->left = node;

        // update parent of `node`.
        node->parent = rightChild;

        // update root of tree is rotated.
        node = rightChild;
    }
}

void rotateRight(Node* &root, Node* &node) {
    if (root && node && node->left) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        // update parent of right child of leftChild of `node`.
        if (leftChild->right)
            leftChild->right->parent = node;

        // update parent of leftChild.
        leftChild->parent = node->parent;
        if (node->parent == null) // update root of RBT if `node` is root.
            root = leftChild;
        else {
            if (node->parent->left == node)
                node->parent->left = leftChild;
            else
                node->parent->right = leftChild;
        }

        // update right child of leftChild.
        leftChild->right = node;

        // update parent of `node`.
        node->parent = leftChild;

        // update root of tree is rotated.
        node = leftChild;
    }
}

void fixViolateInsert(Node* &root, Node* &x) {
    if (root == null || x == null || (x->parent && x->parent->color == BLACK))
        return;

    if (x != root && x->parent && x->parent->parent) {
        Node* uncle = getUncle(x);
        Node* parent = x->parent;
        Node* grandparent = x->parent->parent;


        bool isBothRed = (parent->color == RED && uncle && uncle->color == RED);
        if (isBothRed) {
            // Case 1: parent, uncle and x (node added) are RED.

            // - Reverse color of grandparent, parent and uncle.
            reverseColor(grandparent);
            reverseColor(parent);
            reverseColor(uncle);

            // There are three cases:
            // - Case 1.1: If grandparent is BLACK, then terminate.
            // - Case 1.2: If grandparent is RED, reverse color until grandparent is root.
            // - Case 1.3: If grandparent is root, change color to BLACK.
            if (grandparent->color == RED)
                fixViolateInsert(root, grandparent);

        } else {
            // Case 2 and 3: parent and x are both RED, uncle is BLACK.

            // If parent is left child.
            if (parent == grandparent->left) {

                // Case 3: Rotate left at parent and go to case 2.
                if (x == parent->right)
                    rotateLeft(root, parent);

                // Case 2:
                // - Reverse color of grandparent and parent.
                // - Rotate right at grandparent.
                reverseColor(grandparent);
                reverseColor(parent);
                rotateRight(root, grandparent);

            } else { // parent is right child.
                // Case 3: Rotate right at parent and go to case 2.
                if (x == parent->left)
                    rotateRight(root, parent);

                // Case 2:
                // - Reverse color of grandparent and parent.
                // - Rotate left at grandparent.
                reverseColor(grandparent);
                reverseColor(parent);
                rotateLeft(root, grandparent);
            }
        }
    }

    root->color = BLACK;
}

void fixViolateDeleteForSiblingIsLeftChild(Node* &root, Node* &sibling, Node* &parent) {
    // Case 4.1: external grandchild (left child of sibling) is BLACK.
    // - Reverse color of internal grandchild and sibling.
    // - Rotate left at sibling.
    // - Goto case 4.2.
    if (!sibling->left || sibling->left->color == BLACK) {
        reverseColor(sibling->right);
        reverseColor(sibling);
        rotateLeft(root, sibling);
    }

    // Case 4.2: external grandchild is RED.
    // - Sibling inherits color of its parent.
    // - Color of parent and external grandchild is set to BLACK.
    // - Rotate right at parent.
    sibling->color = parent->color;
    parent->color = BLACK;
    if (sibling->left)
        sibling->left->color = BLACK;

    rotateRight(root, parent);
}

void fixViolateDeleteForSiblingIsRightChild(Node* &root, Node* &sibling, Node* &parent) {
    // Case 4.1: external grandchild (right child of sibling) is BLACK.
    // - Reverse color of internal grandchild and sibling.
    // - Rotate right at sibling.
    // - Goto case 4.2.
    if (!sibling->right || sibling->right->color == BLACK) {
        reverseColor(sibling->left);
        reverseColor(sibling);
        rotateRight(root, sibling);
    }

    // Case 4.2: external grandchild is RED.
    // - Sibling inherits color of its parent.
    // - Color of parent and external grandchild is set to BLACK.
    // - Rotate left at parent.
    sibling->color = parent->color;
    parent->color = BLACK;
    if (sibling->right)
        sibling->right->color = BLACK;

    rotateLeft(root, parent);
}

void fixViolateDelete(Node* &root, Node* &x, Node* &parent) {
    if (root == null)
        return;

    if (root != x) {
        Node* sibling = getSibling(x, parent);

        // Case 1.
        if (x && x->color == RED)
            x->color = BLACK;
        else if (sibling) {
            if (sibling->color == RED) {
                // Case 3: x is BLACK, its sibling is RED.
                // - Reverse color of its parent and sibling.
                // - Rotate at parent.

                reverseColor(parent);
                reverseColor(sibling);

                if (x == parent->left)
                    rotateLeft(root, parent);
                else
                    rotateRight(root, parent);

            } else if ((!sibling->left || sibling->left->color == BLACK) &&
                       (!sibling->right || sibling->right->color == BLACK)) {

                // Case 2: sibling and both of its children are BLACK.
                // - Reverse color of sibling.
                // Attach BLACK token to parent.
                reverseColor(sibling);
                parent->color = BLACK;
                
            } else {
                // Case 4: sibling is BLACK and at least one of its children is RED.

                if (sibling == parent->right)
                    fixViolateDeleteForSiblingIsRightChild(root, sibling, parent);
                else
                    fixViolateDeleteForSiblingIsLeftChild(root, sibling, parent);
            }
        }
    }

    root->color = BLACK;
}
