#include <iostream>
#include <stdexcept>
using namespace std;

class IntVector{
    private:
    unsigned sz;
    unsigned cap;
    int *data;

    public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    int & at(unsigned index);
    const int & front() const;
    const int & back() const;
    int & front();
    int & back();
    void erase (unsigned index);
    void insert(unsigned index, int value);
    void push_back (int value);
    void pop_back();
    void clear();
    void resize(unsigned size, int value = 0);
	void reserve(unsigned n);
    void assign (unsigned n, int value);
    private:
    void expand(unsigned amount);
    void expand();
};

