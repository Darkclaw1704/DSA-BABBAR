#include <iostream>
using namespace std;

double value = 3.14;

void shouldPrintOriginal(){
    cout<<value<<endl;
}

void increment(){
    value++;
}

int main(){
    // int r = 10;
    // double area = value * r * r;
    // cout<<"area : "<<area<<endl;

    shouldPrintOriginal();
    increment();
    shouldPrintOriginal();
}

