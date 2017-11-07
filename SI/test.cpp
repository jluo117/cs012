#include <iostream>
#include <cstring>
using namespace std;
int loop = 0;
int r1(int x) {
    if(x == 7) {
        return 0;
    }
    return x - r1(x+1);
}

int r2(int x) {
    if(x == 0) {
        return x + 2;
    }
    int a = r2(x/3);
    cout << x << " ";
    int b = r2(a/3);
    return b*a;
}

int r3(int x, int y) {
    if((x + 1) % 3 == 0) {
        return y;
    }
    if(x > y) {
        return x - r3(y, x);
    }
    cout << x + y << " ";
    return r3(y-x, x);
}

//char * r4(char a[], char b[]) {
int * r4(int a[], int b[]) {
	loop++;
    if(*a == 0 || *b == 0) {
        return b;
    }
    if(*a > *b) {
        return r4(a, b+1);
    }
    *r4(a+1, b-1) += 2;
    return a;
}

void printArr(int *arr) {
    while(*arr) {
        cout << *(arr++) << ' ';
    }
}

int main() {
    ///////////////////////////////////// 1 ////////////////////////////////////
    cout << "r1(4): " << r1(4) << endl << endl;

    ///////////////////////////////////// 2 ////////////////////////////////////
    int val = r2(10);
    cout << endl << "r2(10): " << val << endl << endl;

    ///////////////////////////////////// 3 ////////////////////////////////////
    val = r3(10, 4);
    cout << endl << "r3(10, 4): " << val << endl << endl;

    ///////////////////////////////////// 4 ////////////////////////////////////
    //char s1[] = "cha", s2[] = "ben";
    int s1[4] = {3, 8, 1}, s2[4] = {2, 5, 14};
    r4(s1, s2);
    //cout << "s1: " << s1 << "\ts2: " << s2 << endl;
    cout << "s1: "; printArr(s1);
    cout << "\ts2: "; printArr(s2); cout << endl;
    return loop;
}

