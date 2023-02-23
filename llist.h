//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Simon Hausmaninger
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 public:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //** Purpose: Returns true if LL is empty and False if not empty
  bool isEmpty();
  
  //** Purpose: Displays all contents of LL
  void displayAll();
    
  //** Purpose: Adds el_t to front of LL
  void addFront(el_t);
    
  //** Purpose: Adds el_t to rear of LL
  void addRear(el_t);

  //** Purpose: Deletes front element of LL
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //** Deletes rear element
  void deleteRear(el_t&);
    
  //**deletes specified element (ith in list)
  void deleteIth(int, el_t&);  // calls moveTo

  //** Inserts into an ith position of LL
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
