//CS311 Yoshii FALL21 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Simon Hausmaninger
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  Front = NULL;
  Rear = NULL;
  Count = 0;
  cout << "... in llist constructor..." << endl; }

llist::~llist()
{ cout << ".... in llist destructor..." << endl; }

//PURPOSE: Checks if llist is empty
//PARAMETER: n/a
bool llist::isEmpty() {
  if(Front == NULL && Rear == NULL && Count == 0){
    return true;
  } else return false;
 } // be sure to check all 3 data members

//PURPOSE:Displays all elements of LL
//PARAMETER: na
void llist::displayAll() {
  Node *P = Front; //temp node to traverse list
  if(isEmpty()){
    cout<<"[ Empty ]"<< endl;
  } else{
    cout << " [ ";
    while(P!= NULL){ //traverse
      cout<< P->Elem << " ";
      P=P->Next;
    }
    cout << "]\n";
  }
 }  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: Add to rear of LL
//PARAMETER: el_t
void llist::addRear(el_t NewNum) {
  if(isEmpty()){
    Node *newNode = new Node;
    newNode -> Elem = NewNum;
    Front = newNode;
    Rear = newNode;
    newNode -> Next = NULL;
    Count++;
  } else{
  Rear -> Next = new Node; //link to list
  Rear = Rear -> Next;
  Rear -> Elem = NewNum;
  Rear -> Next = NULL; 
  Count++; //increment count
 }} // comment the 2 cases

//PURPOSE: Add to front of LL
//PARAMETER: el_t
void llist::addFront(el_t NewNum) {
  if(Count == 0){
    Node *newNode = new Node;
    newNode -> Elem = NewNum;
    Front = newNode;
    Rear = newNode;
    Count++;
  } else{
    Node *newNode = new Node;
    newNode -> Elem = NewNum;
    newNode -> Next = Front;
    Front = newNode;
    Count++;
  }
 } // comment the 2 cases

//PURPOSE: Delete front element of LL
//PARAMETER: el_t&
void llist::deleteFront(el_t& OldNum) {
  if(isEmpty()){
    throw Underflow();
  } else if(Count == 1){
  OldNum = Front -> Elem;
  delete Front;
  Front = NULL;
  Rear = NULL;
  Count--;
  } else{
  OldNum = Front -> Elem;
  Node *Second;
  Second = Front -> Next;
  delete Front;
  Front = Second;
  Count--;
 }} // comment the 3 cases - count = 0,1,...

//PURPOSE: Deletes rear element of LL
//PARAMETER: el_t
void llist::deleteRear(el_t& OldNum){
  if(isEmpty()){ //when ll is empty
    throw Underflow();
  } else if(Count == 1){ //when there is one element
    OldNum = Rear -> Elem;
    delete Rear;
    Front = NULL;
    Rear = NULL;
    Count--;
  } else{ //all other cases
    OldNum = Rear -> Elem;
    Node *second = Front;
    while(second -> Next != Rear)
    second = second -> Next;
    delete Rear;
    Rear = second;
    Rear -> Next = NULL;
    Count--;//decrementing Count because we have deleted a node
  }

} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  for(int K = 1; K <= (J-1); K++)
  {
    temp = temp -> Next;
  }
}

//PURPOSE: Removes ith element of LL
//PARAMETER: el_t
void llist::deleteIth(int I, el_t& OldNum) { 
 // 1) error case
	// if out of range, throw outofrange.
	if (I > Count || I < 1) {
		throw OutOfRange();
	}
	// 2) special case
	// if I equals 1, call deleteFront.
	else if (I == 1) {
		deleteFront(OldNum);
	}
	// 3) special case
	// if I equal Count, call deleteRear.
	else if (I == Count) {
		deleteRear(OldNum);
	}
	// 4) regular case2

	else {
		Node *P = Front;        // make P point to a node cell and points to front
      moveTo(I-1, P);           // call moveTo
      Node *Q = P-> Next;      // Q points to the ith term
      P->Next = Q->Next;      // P points to the position after ith
      OldNum = Q->Elem;       // oldnum gets Q's elem
      delete Q;               // delete Q
      Count--;                // decrement count
	}
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: Inserts element into ith position
//PARAMETER: el_t
void llist::insertIth(int I, el_t newNum) {
if ((I < 1) || (I > Count+1))
{
throw OutOfRange();
}
else if (isEmpty())
{
throw Underflow();
}
else if (I == 1)
{
addFront(newNum);
}
else if (I == Count + 1)
{
addRear(newNum);
//Count++;
}
else
{
  Node *P = Front; //P Points to front
  moveTo(I-1,P); // call moveto
	Node *temp = P->Next; //temp points to ith term
	P->Next = new Node; //P next is new node
	P->Next->Next = temp; // 2nd element after P is set to temp
	P->Next->Elem = newNum; 
	Count++;
}
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Allow passing of a list by value and returning of a list by value
//PARAMETER:
//llist::llist(const llist& Original) { } // use my code
llist::llist(const llist& Original)
  {
    //  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with 
    //  operator= above. To do this,
     // // this-> object has to be built up by allocating new cells with Original elements (**).

    //  Nothing to return because this is a constructor.
}


//PURPOSE:for allowing the client to use = for linked list objects with pointers
//PARAMETER:
llist& llist::operator=(const llist& OtherOne)
  {  el_t x;
     // First make sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
                   this->deleteRear(x);  
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} 


