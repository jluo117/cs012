#include <iostream>
using namespace std;

int power(int x,int n){
    if (n==0){
        return 1;
    }
    return x * (power(x,n-1));
}

int sum (int n){
    if (n==0){
        return 0;
    }
    return n + sum(n-1);
}

void sequence (int n){
    cout << n <<' ';
    if (n==1){
        return;
    }
    if (n%2 == 0){
        sequence(n/2);
    }
    else{
        sequence((n*3) + 1);
    }
}

int main (){
    int x , n;
    cin >> x >>  n;
    cout << "Power " <<  power(x,n) << endl;
    cout << "Sum " << sum(n) << endl;
    sequence(n);
    cout << endl;
    return 10;
}
