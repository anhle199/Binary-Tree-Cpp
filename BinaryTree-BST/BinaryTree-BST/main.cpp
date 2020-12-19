//
//  main.cpp
//  BinaryTree-BST
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "BST.h"

int main() {
    //    srand((unsigned int) time(nullptr));
    //
    //    int n;
    //    cout << "Enter the number of nodes: ";
    //    cin >> n;
    //
    ////     ADD NEW Node.
        Node* root = nullptr;
    //    cout << "Random value: ";
    //    for (int i = 0; i < n; i++) {
    //        int x = rand() % 1000;
    //        cout << x << " ";
    //
    //        insert(root, x);
    //    }
    //    cout << endl;
        insert(root, 10);
        insert(root, 2);
        insert(root, 5);
        insert(root, 15);
        insert(root, 14);
        insert(root, 65);
        insert(root, 58);
        insert(root, 25);
        insert(root, 24);
        insert(root, 26);
        insert(root, 89);
        insert(root, 82);
        insert(root, 84);
        // TRAVERSAL.
//        cout << "Pre-order traversal: ";
//        NLR(root);
//        cout << endl;

    //    cout << "In-order traversal: ";
    //    LNR(root);
    //    cout << endl;
    //
    //    cout << "Post-order traversal: ";
    //    LRN(root);
    //    cout << endl;

//        cout << "Level-order traversal: ";
//        levelOrder(root);
//        cout << endl;
//
//        cout << "Level of binary tree: " << level(root) << endl;
//        cout << "Height of binary tree: " << height(root) << endl;
//        cout << "The number of nodes of binary tree: " << countNode(root) << endl;
//        cout << "The total value of all nodes of binary tree: " << sumAllNodes(root) << endl;

        int val;
//        cout << "Enter the value of node need to find height: ";
//        cin >> val;
//        cout << "The height of a Node has value " << val << ": " << heightOfNodeHasValue(root, val) << endl;
//
//        cout << "Enter the value of node need to find level: ";
//        cin >> val;
//        Node* node = createNode(val);
//        cout << "The level of a Node has value " << val << ": " << levelOfNode(root, node) << endl;
//        delete node;
//
//        cout << "The level of a Node has no value (nullptr) : " << levelOfNode(root, nullptr) << endl;
//        cout << "The number of leaves of binary tree: " << countLeaf(root) << endl;

    // ********************
    // Wrong.
    // ********************
//        cout << "Enter the value of node need to find the number of nodes has value is less than this node: ";
//        cin >> val;
//        cout << "The number of nodes has value is less than " << val << ": " << countLess(root, val) << endl;

//        cout << "Enter the value of node to find the number of nodes has value is greater than this node: ";
//        cin >> val;
//        cout << "The number of nodes has value is greater than " << val << ": " << countGreater(root, val) << endl;


//        cout << "Enter the value of node need to find level: ";
//        cin >> val;
//        Node* p = search(root, val);
//        if (p)
//            cout << "Value: " << p->key << endl;
//        else
//            cout << "Not found." << endl;
//
//        cout << "Enter the value of node you want to delete: ";
//        cin >> val;
//        cout << "After remove " << val << ": ";
//        remove(root, val);
//        NLR(root);
//        cout << endl;

    //    removeTree(root);
    //
    //    NLR(root);
    //    cout << endl;
    //
    //    int a[n];
    //    for (int i = 0; i < n; i++) {
    //        a[i] = rand() % 1000;
    //        cout << a[i] << " ";
    //    }
    //    cout << endl;
    //
    //
    //
    //
    //    NLR(root);
    //    cout << endl;
    //
    //    cout << (isBST(root) ? "true" : "false") << endl;
    //
    ////    int a[] = {50, 48, 23, 19, 33, 49, 60, 59, 69}; // true
    ////    int a[] = {50, 48, 23, 19, 49, 60, 59, 69}; // false
    //    n = sizeof(a) / sizeof(int);
    //    root = createTree(a, n);
    //    root = createNode(19);
    //    root->left = createNode(2001);
    //    root->right = createNode(9);
    //    root->right->left = createNode(5);
    //    root->right->right = createNode(10);
    //    cout << (isBST(root) ? "true" : "false") << endl;
    //    cout << (isFullBST(root) ? "true" : "false") << endl;
    //
    //    removeTree(root);
    //
    //
    //
    //
    //
    //
    //
    //
    ////    int n;
    //    cout << "Enter the number of nodes: ";
    //    cin >> n;
    //
    //    int x;
    ////    Node* root = nullptr;
    //    cout << "Random value: ";
    //    for (int i = 0; i < n; i++) {
    //        x = rand() % 1000;
    //        cout << x << " ";
    //
    //        insert(root, x);
    //    }
    //    cout << endl;
    //
    //    if (isBST(root)) {
    //        cout << "----- After Insert -----" << endl;
    //        cout << "Pre-order: ";
    //        NLR(root);
    //        cout << endl;
    //
    //        cout << "In-order: ";
    //        LNR(root);
    //        cout << endl;
    //
    //        cout << "Post-order: ";
    //        LRN(root);
    //        cout << endl;
    //
    //        cout << "Level-order: ";
    //        LevelOrder(root);
    //        cout << endl;
    //
    //        cout << "Enter the number of nodes you want to delete: ";
    //        cin >> n;
    //        for (int i = 0; i < n; i++) {
    //            cout << "Enter the value you want to delete: ";
    //            cin >> x;
    //
    //            remove(root, x);
    //        }
    //
    //        cout << "----- After Remove -----" << endl;
    //        cout << "Pre-order: ";
    //        NLR(root);
    //        cout << endl;
    //
    //        cout << "In-order: ";
    //        LNR(root);
    //        cout << endl;
    //
    //        cout << "Post-order: ";
    //        LRN(root);
    //        cout << endl;
    //
    //        cout << "Level-order: ";
    //        LevelOrder(root);
    //        cout << endl;
    //    }
    //
    removeTree(root);

    return 0;
}
