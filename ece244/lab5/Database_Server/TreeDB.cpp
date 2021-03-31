/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"
#include <string>
#include <iostream>
using namespace std;

//Default Constructor: Creates an empty database//

TreeDB::TreeDB(){
    root = NULL;
}

//Destructor 
TreeDB::~TreeDB(){
    if(root==NULL){
        return;}
    else 
        {delete_database(root);}
}

//Helper function for the Data base//
void TreeDB:: delete_database(TreeNode* DBroot ){
    if(DBroot == NULL) {return;} //Base Case: empty data base 
    
    delete_database (DBroot->getLeft());  //delete left subtree
    delete_database (DBroot->getRight()); //delete right subtree
    delete (DBroot->getEntry()); //deletes the DBentry
    delete DBroot; //deletes the root of database
   
}

     // searches the database for an entry with a key equal to name.
    // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
  // Also sets probesCount
   DBentry* TreeDB:: find(string name){
       //Setting probe count//
       probesCount = 0;
       
       //Searching for the node 
       DBentry* tmp = search_db(root, name);
       return (tmp);
   }
   //Search helper function//
   DBentry* TreeDB:: search_db(TreeNode* root, string name){
       probesCount = probesCount+1;
       if (root == NULL) {return NULL;} // Base Case: Empty list 
       if ((root->getEntry()->getName())== name) {return root->getEntry();}
       { if ((root->getEntry()->getName())< name) {return search_db(root->getRight(),name);} //looking in right subtree
       else {return search_db(root->getLeft(),name);}} //looking in left subtree
   }
   
   
   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB:: insert(DBentry* newEntry){
       DBentry* tmp = search_db(root,newEntry->getName()); //Searching for key in database
       
       if(tmp->getName() == newEntry->getName()) {return false;}
       else {//Helper function needed
           insert_newEntry(root,newEntry);
           return true;
       } 
       
   
   }
   
   //Helper function for inserting new entry//
   
   void TreeDB:: insert_newEntry(TreeNode* root, DBentry* newEntry){
       if(root == NULL) {
           root = new TreeNode(newEntry);
       } //base case
       
        if(root->getEntry()->getName() <  newEntry->getName()){
           if(root->getRight() == NULL){root->setRight(new TreeNode(newEntry));
                                        return;}
           else 
                insert_newEntry(root-> getRight(),newEntry);} //if new name is larger than root node name
        
        if (root->getEntry()->getName() > newEntry->getName()){ 
            if(root->getLeft() == NULL){root->setLeft(new TreeNode(newEntry));
                                        return;}
            else 
                insert_newEntry(root->getLeft(),newEntry);}  //if new name is smaller than root node name
       
   }
  // deletes all the entries in the database.
   void TreeDB:: clear(){
       delete_database(root);
   }
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void TreeDB:: countActive() const {
       int counter = 0; //for counting number of actives
       if (root == NULL){ //Checking for empty tree
           cout << counter << endl;
           return;}
       else{ 
           //helper function called
           activeCounter (root ,counter);
           cout << counter << endl;
       return;}
   
   }
   
   //helper function for countActive//
   
   void TreeDB:: activeCounter(TreeNode* root, int &count) const{
       if(root == NULL) {return;}
       if(root->getEntry()->getActive() == true){count = count + 1;}
       activeCounter(root->getLeft(),count);
       activeCounter(root->getRight(),count);
         
   }
   
   //print probes//
   
   void TreeDB:: printProbes() const{
       cout<< probesCount << endl;
   }
   
   //cout implementation//
   //will define an in-order(LHS) traversal function for printing//
   
   ostream& operator<< (ostream& out, const TreeDB& rhs){
   if (rhs.root == NULL)
       return out;
   else
       out << rhs.root;
   
   }
   
   ostream& operator<< (ostream& out, TreeNode* rhs){
       out<< rhs->getLeft();
       out<< *(rhs->getEntry());
       out<< rhs->getRight();
       return out;
   
   
   }
   
   
   
   
       
       
 
   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output
   
   bool TreeDB:: remove(string name){
   //find the key if it exists and decide if to delete or not//
   //if key is there we will need to find the the type of node it is: leaf? with one child with two children//; is it the root node itself
   // for this we need the node's parent//
   
       TreeNode* parent = findparent(root,name);
        if ( (find(name)->getName()) != name) {
           return (false);}
      
       
       if(parent->getLeft() == NULL && parent->getRight() == NULL ) //leafnode// simply delete the node
           delete (parent->getEntry());
           delete parent;
        
           
       if(parent->getLeft() == NULL || parent->getRight() == NULL){
           
           if(parent->getLeft() == NULL)
               root->setLeft(parent->getRight());
           delete parent;
               
           if(parent->getRight() == NULL)
               root->setLeft(max_in_lst(parent));
       }
   
           return(true);}
   
   
   TreeNode* TreeDB:: findparent(TreeNode* root,string name){
      
       
       if (root->getEntry()->getName() == name) {return root;}
       
       else if (root->getEntry()->getName() > name) {
           findparent(root->getLeft(),name);}
       else if(root->getEntry()->getName() < name) {  findparent(root->getRight(),name);}
     }
   
   TreeNode* TreeDB:: max_in_lst(TreeNode* parent){
       
       if(parent->getRight() == NULL) {
           return parent;
       }
       else 
           return max_in_lst(parent->getRight());
   }
   
   
 
           
       
      
   

   