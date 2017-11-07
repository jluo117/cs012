#include "IntList.h"
using namespace std;

IntList::IntList(){
    head = 0;
}


void IntList::push_front(int value){
   IntNode  *tmp = new IntNode(value);
    tmp ->next = head;
    head = tmp;

}

ostream & operator<<(ostream &out, const IntList & list){
    if (list.head == 0){
        return out;
    }
	out <<list.head;
	return out;
}

ostream &operator<<(ostream &out,IntNode *cur){
    out << cur ->data;
    cur = cur -> next;
    if (cur == 0){
        return out;
    }
    out << ' '<< cur;
    return out;
}

bool IntList::exists(int a) const{
    if (head == 0){
        return false;
    }
    return exists(head , a);
}


bool IntList::exists(IntNode *cur, int a) const{
    if (cur == 0){
        return false;
    }
    if (cur ->data == a){
        return true;
    }
    cur = cur -> next;
    return exists(cur , a);
}
