//
//  AdditionalFunctions.h
//  AVLTree
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#ifndef ADDITIONAL_FUNCTIONS_H_
#define ADDITIONAL_FUNCTIONS_H_

#include "AVLTree.h"

#define LEFT_DEVIATION     -1
#define BALANCE             0
#define RIGHT_DEVIATION     1

int calculateBalanceFactor(Node* root);
int heightOfNode(Node* root);
void insertImp(Node* &root, int x, bool &insertSuccessful);
void searchToDelete(Node* &p, Node* &q);
void removeImp(Node* &root, int x, bool &removeSuccessful);

#endif
