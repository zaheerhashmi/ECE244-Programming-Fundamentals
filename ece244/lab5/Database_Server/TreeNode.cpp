/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TreeNode.h"
//Contructor

TreeNode:: TreeNode(DBentry* _entrypoint){
    left= NULL;
    right = NULL;
    entryPtr = new DBentry(_entrypoint->getName(),_entrypoint->getIPaddress(),_entrypoint->getActive());

}

//Destructor

TreeNode:: ~TreeNode(){
    delete entryPtr;
    delete left;
    delete right;
}

//Mutators

void TreeNode:: setLeft(TreeNode* newLeft){
    left = newLeft;
}

void TreeNode:: setRight(TreeNode* newRight){
    right = newRight;
}

//Accessors

TreeNode* TreeNode:: getLeft() const{
    return(this->left);
}

TreeNode* TreeNode:: getRight() const{
    return(this->right);
}

DBentry* TreeNode:: getEntry() const {
    return(this->entryPtr);
}










