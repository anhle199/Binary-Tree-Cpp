//
//  main.cpp
//  RBTree
//
//  Created by Le Hoang Anh on 16/12/2020.
//

#include "RBTree.h"

using namespace std;

int main() {
    Node* root = nullptr;

    // insert
    int insertedValues[] = {5088, 5892, 3062, 6276, 8393, 0, 2130, 2319, 1213, 2745,
                            8121, 9059, 5819, 4765, 5900, 1630, 9014, 3239, 2756};
    int n = sizeof(insertedValues) / sizeof(insertedValues[0]);
    for (int i = 0; i < n; i++)
        insert(root, insertedValues[i]);


    // print
    cout << "- AFTER INSERTING:" << endl;
    cout << "Pre-order:" << endl;
    NLR(root);
    cout << endl;

    cout << "Level order:" << endl;
    levelOrder(root);
    cout << endl;

    // remove
    int deletedValues[] = {2745, 5088, 8393, 2130, 1213, 0};
    int m = sizeof(deletedValues) / sizeof(deletedValues[0]);
    for (int i = 0; i < m; i++)
        remove(root, deletedValues[i]);

    cout << "\n- AFTER DELETING:" << endl;
    // print
    cout << "Pre-order:" << endl;
    NLR(root);
    cout << endl;

    cout << "Level order:" << endl;
    levelOrder(root);
    cout << endl;

    removeTree(root);

    return 0;
}
