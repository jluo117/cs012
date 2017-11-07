#include <iostream>
using namespace std;

double mean(const double array[], int arraySize){
    double value(0.0);
    for (int i = 0; i<arraySize; i++){
        value = value + array[i];
    }
    return value/arraySize;
}

void remove(double array[], int& arraySize, int index){
    for (int i = index; i < arraySize-1; i++){
        array[i] = array[i+1];
        }
        arraySize--;
}
void display(const double array[], int arraySize){
    int i;
for ( i =0; i<arraySize-1; i++){
    cout << array[i] << ", ";
}
cout << array[i] << endl;
}



int main(){
cout << "Enter 10 values:" << endl << endl;
int arraySize = 10;
double  array[arraySize];
int index;
for (int i = 0; i < arraySize; i++){
    cin >> array[i];
}

cout << "Mean: " << mean(array, arraySize) << endl << endl;
cout << "Enter index of value to be removed: ";
cin >> index;
cout << endl;
cout << "Before removing value: ";
display(array, arraySize);
remove(array, arraySize,index);
cout << "After removing value: ";
display(array,arraySize);
return 0;
}
