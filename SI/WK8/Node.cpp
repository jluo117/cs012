#include <iostream>
using namespace std;


struct Node {
	int data;
	Node *nxt;
	Node(int d) : data(d), nxt(0) { }
};

void push_back(Node *&curr, Node *toAdd){
    if (curr == 0){
        curr = toAdd;
        toAdd -> nxt =0;
        return;
    }
    if (curr -> nxt == 0){
        curr -> nxt = toAdd;
        toAdd -> nxt = 0;
        return;
    }
    curr = curr->nxt;
    push_back(curr,toAdd);
}

void display(Node *head){
    if (head == 0){
      return;
    }
    cout << head->data << ' ' << endl;;
    head = head->nxt;
    display(head);
}

void clear(Node*& curr){
    if (curr == 0){
        return;
    }
    delete curr;
    curr = curr -> nxt;
    clear(curr);
}

void insert_ordered(Node*& curr,Node*toAdd){
    if (curr == 0){
        push_back(curr,toAdd);
    }
    if :x

int main() {
	Node *head = 0;
    Node *add = new Node(10);
    Node *add1 = new Node(100);
    push_back(head,add);
    push_back(head,add1);
    display(head);
    clear(head);
    display(head);
	return 0;
}

