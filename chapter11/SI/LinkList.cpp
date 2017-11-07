#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *nxt;
	Node(int d) : data(d), nxt(0) { }
};

class IntList {
    private:
    Node *head;
    Node *tail;

    public:
    IntList();
    void display();
	void push_front(int value);
 	bool circle();
	void push_back(int value);
};


IntList::IntList(){
    Node head = 0;
}

void IntList::push_front(int value){
    Node  *tmp = new Node(value);
          tmp ->nxt = head;
     head = tmp;

}
void IntList::push_back(int value){
     Node *tmp = new Node(value);




}


void IntList::display(){
    Node *current = head;
    while (current != 0){
        cout << current->data <<' ' << endl;
        current = current -> nxt;
    }
    cout << "Complete" << endl;
}
bool IntList::circle(){
    for (Node *current = head->nxt; current !=0; current= current->nxt){
        if (current == head){
            return true;
        }

    }
    return false;
}

int main() {
IntList test;
test.push_front(10);
test.push_front(20);
test.push_back(0);
test.display();

/*if (test.circle()){
    cout << "Circle" << endl;
}
*/
	return 0;
}


