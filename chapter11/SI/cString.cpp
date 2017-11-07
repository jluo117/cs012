#include <iostream>
using namespace std;

void strcpt(char a[], char b[]){
    int i = 0;
    while (a[i] !='\0'){
    b[i] = a[i];
    i++;
    b[i] = '\0';
    }
}
void strcat (char a[], char b[]){
    int i = 0;
    while (a[i] != '\0'){
        i++;
    }
    int j = 0;
    while (b[j] != '\0'){
         a[i] = b[j];
    }
    a[i] = '\0';
}
int main (){
    char c[] = "hello";
  //  char strCat[100]="bobbyRules\0";
    char b[10];
    strcpt(c , b);
    cout << b;
   // strcat(strCat,a);
 //   for (int i = 0; i < 200; i++){
   //     cout << strCat[i];
   // }
   // cout << endl;
    return 0;
}
