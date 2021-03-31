#include <galaxy-explorer/AsteroidList.hpp>
AsteroidListItem::AsteroidListItem() {
	this->next = nullptr;
	this->data = nullptr;
}

AsteroidListItem::AsteroidListItem(Asteroid a) {
	next = nullptr;
	data = new Asteroid(a);
}

AsteroidListItem::~AsteroidListItem() {
    delete data;
}

AsteroidList::AsteroidList() //empty list nothing needs to be done
{ 
}

AsteroidList::AsteroidList(const AsteroidList& src){ // Implements the code for the 

const AsteroidListItem* ptr = (src.head).getNext();
AsteroidListItem* newList = &head;
AsteroidListItem* nptr = nullptr;

while(ptr != nullptr){ 
    nptr = new AsteroidListItem(ptr->getData());
    newList->setNext(nptr);
    ptr = ptr->getNext();
    newList = newList->getNext();
}

    
}


//{
    //this = src; // making ptr point to the head of the source list
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	// The functions in this class are listed in a suggested order of implementation,//
	// except for this one and the destructor (because you should put all your constructors together).//
//}

AsteroidList::~AsteroidList() {
    this -> clear();
    head.setNext(NULL);
//	// The functions in this class are listed in a suggested order of implementation,//
//	// except for this one and the copy constructor (because you should put all your constructors together).//
    
    
}

void AsteroidList::pushFront(Asteroid e) {
    AsteroidListItem* tmp = new AsteroidListItem(e); //new node initialized with Asteroid e, now we will add it to the linked list//
    tmp->setNext(head.getNext()); // the new node now points to the the current head node//
    head.setNext(tmp); // the new node becomes the new "head node" and the asteroid e is added to the linked list// 
}

Asteroid& AsteroidList::front() {
    if(!head.hasNext()){
        return*(Asteroid*)nullptr;
    }
    return ((head.getNext())-> getData()); //returns the first asteroid in the linked list //
}

const Asteroid& AsteroidList::front() const {
	return ((head.getNext())-> getData()); //returns the first asteroid in the linked list// 
}

bool AsteroidList::isEmpty() const {
    if(head.getNext() ==  NULL || head.getNext()== nullptr) // checks if the head ptr points to a nodel if it does then list empty else is has atleast one node
	return true;
    else 
        return false;
//    return !head.hasNext();
}

int AsteroidList::size() const {
   const AsteroidListItem* tmp = head.getNext();
    int size=0;// this serves as our counter 
    while (tmp != nullptr){
        tmp = tmp -> getNext();
        size = size+1;
    }
    //will need to traverse the list till nullptr or NULL is reached,
    //for keeping track of the size we will have a counter//.
	return (size);
}

AsteroidListItem* AsteroidList::beforeBegin() { // This will check if list is empty or not if it is it returns beforeEnd else it gives us a pointer to the head item
 
        AsteroidListItem* tmp = &head;
        return(tmp);
}

const AsteroidListItem* AsteroidList::beforeBegin() const { //returns a pointer to the head list item//
      const AsteroidListItem* tmp = &head;
        return(tmp);
}

AsteroidListItem* AsteroidList::begin() { //returns the pointer to node of first asteroid object//
   
    return(head.getNext());
}

const AsteroidListItem* AsteroidList::begin() const { //returns the pointer to node of first asteroid object//
    return(head.getNext());
     
}

AsteroidListItem* AsteroidList::beforeEnd() {
    AsteroidListItem* tmp = head.getNext();
    AsteroidListItem* pptr = NULL;
    while(tmp != NULL){
        pptr = tmp;
        tmp = tmp ->getNext();
    }
	return pptr;
}

const AsteroidListItem* AsteroidList::beforeEnd() const {
    const AsteroidListItem* tmp = head.getNext();
    const AsteroidListItem* pptr = NULL;
    while(tmp != NULL){
        pptr = tmp;
        tmp = tmp ->getNext();
    }
	return pptr;

}

AsteroidListItem* AsteroidList::end() {
	return nullptr;
}

const AsteroidListItem* AsteroidList::end() const {
	return nullptr;
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    AsteroidListItem* tmp = new AsteroidListItem(e);
    tmp ->setNext(prev->getNext()); //getting the new object to point to the node after 
    prev->setNext(tmp); // making the "prev" node point to new node
    return(tmp);// returning the new node recently inserted 
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) { //gotta do//
   AsteroidList* tmp = new AsteroidList(others); //creates a copy of others
   if(prev->getNext()== NULL){
       AsteroidListItem* p1 = prev->getNext();
       prev->setNext(tmp->begin());
       return(p1);}//attaches the head item of the copy list to the list where prev is NULL.
            
   else // in the case prev is not NULL we will need access to the pointer after prev//
   { AsteroidListItem* ptr = prev->getNext(); //storing the item after prev item
                   prev->setNext(tmp->begin()); // assigning the first item of the copy to prev//
                   (tmp-> beforeEnd())->setNext(ptr);
                           return(tmp->beforeEnd());}
} 

AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    AsteroidListItem* tmp = (prev->getNext())->getNext();
    delete prev->getNext();
    prev-> setNext(tmp);
    
    
	return tmp;
}

void AsteroidList::clear() {
    AsteroidListItem* tmp;
    while(head.getNext() != NULL){ // Traversing through the list and assigning next nodes to head until we assign NULL//
        tmp = head.getNext();
        head.setNext(tmp->getNext());
        delete (tmp);
    }
  
    
}

AsteroidList& AsteroidList::operator=(const AsteroidList& src) {

    this->clear();
    this->insertAfter(&(this->head), src);
    return (*this);
    
}   
 

