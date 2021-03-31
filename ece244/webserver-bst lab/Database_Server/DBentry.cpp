/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "DBentry.h" //including the DBentry headerfile to include the definition of the class
using namespace std;

//Implimentation  of the class "DBentry" is below//

//CONTRUCTORS//

DBentry::DBentry(){ 
    name = " ";
    IPaddress = 0;
    active = 0;
} //Default constructor initializing all data members.

DBentry::DBentry(string _name,unsigned int _IPaddress, bool _active ){
    name = _name;
    IPaddress = _IPaddress;
    active = _active;
}

//DESTRUCTOR//
DBentry:: ~DBentry(){} //Does nothing since no dynamic data allocation

//MUTATORS//

void DBentry:: setName(string _name) {
    name = _name;
} // sets the domain name, which we will use as a key.

void DBentry:: setIPaddress(unsigned int _IPaddress){
    IPaddress = _IPaddress;
} // sets the IPaddress data.

void DBentry:: setActive(bool _active){
    active = _active;
} // returns the name.

//ACCESSOR//

string DBentry:: getName() const{ 
    return name;
} //Gets the name of object

unsigned int DBentry:: getIPaddress() const{
    return IPaddress;
} //gets the IPaddress of the object

bool DBentry:: getActive() const{
    return active;
} //gets the active status of the object 

         // prints the entry in the format 
        // name : IPaddress : active  followed by newline
        // active is printed as a string (active or inactive)

    ostream& operator<< (ostream& out, const DBentry& rhs){
    
    out<< rhs.name << " " << ":" << " " << rhs.IPaddress << " " << ":" << " ";
    if(rhs.active==1){
    out<< "active"<<endl;}
    else{
    out<< "inactive" <<endl;}
    
    return(out);
    
} //this function is not a part of the the class but is merely a friend. This is indicated by use of the friend keyword
  //in the header file and the lack of the scoping operator here








