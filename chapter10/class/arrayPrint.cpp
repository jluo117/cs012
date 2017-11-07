#include <iostream>
#include <ctime>
using namespace std;


const int ARR_CAP = 10;


void display (int arr[], int arSize){
    for (int i = 0; i < arSize; i++){
        cout << arr[i] <<' ';
    }
    cout << endl;
}

void ssort (int arr[], int arSize){
    for (int i = 0; i < arSize; i++){
       int  minLoc = i;
        for (int j = minLoc+1 ; j < arSize; j++){
            if (arr[minLoc] > arr[j]){
                 minLoc = j;
            }
        }
        if (i != minLoc){
          int  temp = arr[i];
            arr[i] = arr[minLoc];
            arr[minLoc] = temp;
        }
    }
}

int main (){
    srand(time(0));
    int arr1[];
    int arr[ARR_CAP];

    for (int i = 0; i < ARR_CAP; i++){
        arr[i] = 1 + rand()%100;
    }

    display (arr, ARR_CAP);
    ssort (arr , ARR_CAP);
    display (arr, ARR_CAP);
    return 0;
}
