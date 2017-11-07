#include <iostream>
#include "IntList.h"

using namespace std;
    IntList::IntList(){
        head = 0;
        tail = 0;
    }
    IntList::~IntList(){
       IntNode *current = head;
       while (current != 0){
       delete current;
       current = current-> next;
    }
    delete current;
}
 void IntList::display() const{
    IntNode *currObj = head;
    while (currObj != 0) {
      cout << currObj->data;
      currObj = currObj->next;
      if (currObj == 0){
          return;
      }
       cout <<' ';

   }
return;
}

void IntList::push_front(int value){
   IntNode  *tmp = new IntNode(value);
    if(empty()){
        tail = tmp;
    }
     else{
        tmp ->next = head;
}
    head = tmp;

}

void IntList::pop_front(){
    if (head == 0){
		tail = 0;
        return;
    }
	IntNode *tmp = head;
    delete head;
    head = tmp->next;
}
bool IntList::empty() const{
    return (head == 0);
}

void IntList::push_back(int value){
    if (empty()){
        push_front(value);
        return;
    }
    IntNode *tmp = new IntNode(value);

    tail->next = tmp;
    tail = tail -> next;

}
IntList::IntList(const IntList& cpy){
    head = 0;
    tail = 0;
    IntNode *tmp = cpy.head;
    while (tmp != 0){
        push_back(tmp->data);
        tmp = tmp-> next;
    }
}

IntList & IntList:: operator=(const IntList &rhs){
    if (this != &rhs){
    clear();
    IntNode *tmp =rhs.head;
    while (tmp != 0){
        push_back(tmp->data);
        tmp = tmp -> next;
    }
    }
return *this;

}
void IntList::clear(){
    IntNode *tmp = head;
    while (tmp != 0){
        delete tmp;
        tmp = tmp -> next;
  }
    delete tmp;
    head = 0;
    tail = 0;
}

void IntList::selection_sort(){
    IntNode *current = head;
    while (current != 0){
        IntNode *min = current;
        IntNode *cur = current;
        while (cur != 0){
            if (cur -> data < min-> data){
                min = cur;
            }
            cur = cur -> next;
        }
        int temp = current -> data;
        current->data  = min->data;
        min->data = temp;
        current = current -> next;
    }
}

void IntList::insert_ordered(int value){
    if (empty()){
        push_front(value);
        return;
}
    if (value <= head-> data){
        push_front(value);
        return;
    }
    if (value >= tail->data){
        push_back(value);
        return;
    }
    for (IntNode *cur = head; cur != 0; cur = cur->next){
        if ((cur->data <= value) && (cur->next->data >= value)){
            IntNode *temp = new IntNode(value);
            temp -> next = cur -> next;
            cur -> next = temp;
            return;
        }
}
}

void IntList::remove_duplicates(){
    for(IntNode *cur = head; cur != 0; cur=cur -> next){
        int moveData = cur->data;
        IntNode *prev = cur;
        for (IntNode *curLoop = cur->next; curLoop != 0; curLoop = curLoop -> next){
            if (curLoop->data == moveData){
            prev -> next = curLoop -> next;
            delete curLoop;
            }
            else {
                prev = curLoop;
            }
        }
    }
}
ostream & operator<<(ostream &out, const IntList &rhs) {
    if (rhs.head == 0){
    return out;
    }

    IntNode *cur = rhs.head;
    while (cur != 0){
        out << cur->data;
        cur = cur -> next;
        if (cur == 0){
            return out;
        }
        out <<' ';
    }

    return out;
}






