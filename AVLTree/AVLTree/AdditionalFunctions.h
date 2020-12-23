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

int calculateBalanceFactor(Node* node);
int heightOfNode(Node* node);
void insertAndFixHeight(Node* &root, int x, bool &success);
void searchToDelete(Node* &nodeDeleted, Node* &successor);
void removeAndFixHeight(Node* &root, int x, bool &success);

#endif
