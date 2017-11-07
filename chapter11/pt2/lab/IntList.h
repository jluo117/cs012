#ifndef INTLIST_H
#define INTLIST_H
struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};
class IntList{
    private:
    IntNode *head;
    IntNode *tail;
    public:
    IntList();
    ~IntList();
    void display() const;
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void clear();
    bool empty() const;
    void selection_sort();
    void insert_ordered(int value);
    void remove_duplicates();
    IntList(const IntList &cpy);
    IntList & operator=(const IntList &rhs);
};
#endif
