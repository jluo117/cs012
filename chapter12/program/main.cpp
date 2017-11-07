#include <iostream>
using namespace std;


int gdc(int a, int b){
	if ((a%b) == 0){
		return b;
}
	else {
		int tmp = a%b;
		return gdc(b , tmp);
    }
}


bool diophantine(int a, int b, int c, int &x, int &y){
	if (c%gdc(a,b) != 0){
		return false;
	}


	if ( (a%b) == 0){
		x = 0;
		y = c/b;
		return true;
	}

    else {
        int r = a%b;
        int v;
        int u;
       if (diophantine(b,r,c,u,v)){
           x = v;
           int q = a/b;
           y = u -(q*x);
           return true;
       }
       else {
           return false;
       }
    }
}


int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

