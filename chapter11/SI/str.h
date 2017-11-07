class cStr {
Private:
    char* str;
    Int size;
    Int capacity;

public:
    cString();
    cString(char* str);
    ~cString();

    //Assigns rhs cString to implicit lhs cString
    cString =operator(const cString rhs);

    //Adds rhs cString onto implicit lhs cString
    cString +operator(const cString rhs);

    //Returns whether two cStrings are equal in both size, capacity, and char[]
    Bool ==operator(const cString rhs) const;

    //Returns index of found str in cString or -1 if not found
    Const int find(const char* str) const;

    //Returns size of cString
    Const int size() const;

    //Returns capacity of cString
    Const int capacity() const;

    //Returns str as a string
    Const string toString() const;
};
