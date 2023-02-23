 // CS311 Yoshii FALL21 Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl;}

//slist::~slist() 
//{cout << "slist destructor: " << endl;}


// positions always start at 1

int slist::search(el_t key){
  Node *p = Front;
  int count = 1;
  while(p != NULL){
    if(p -> Elem == key){
      return count;
    }
    p = p -> Next;
    count++;
  }
  return 0;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos){
  if(pos > Count || pos < 1){
    throw OutOfRange();
  }
  
  Node *p = Front; //temp to loop through list
  int position = 1; //use as a counter

  while(position != pos){ // will take us to the correct position
    p = p -> Next;
    position++;
  }

  p->Elem = element;//replaces the correct positin with element
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  if(this->Count != OtherOne.Count){
    return false;
  }
  Node *p = this->Front;
  Node *q = OtherOne.Front;
  // if the same lengths,
  // check each node to see if the elements are the same
  while(p != NULL){  //traverses lists
    if(p->Elem != q->Elem){ //checks equality
      return false;
    }
    p = p-> Next; //increment
    q = q -> Next; //increment
  }
  return true; // returns true after traversing both lists
}
