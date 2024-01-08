#include <iostream>

using namespace std;

int main(){
    // int num = 5;
    // cout<< "value of num : "<<num << endl;

    // cout<<"address of num : "<<&num<<endl;

    // int *ptr = &num;
    // cout<<"value at address : "<<*ptr<<endl;
    // cout<<"value at ptr : "<<ptr<<endl;
    // cout<<"size of integer (should be 4): "<<sizeof(num)<<endl;
    // cout<<"size of pointer (should be 8): "<<sizeof(ptr)<<endl;


    // int *nullPointer = 0;
    // // cout<<*nullPointer;

    // int n = 10;
    // int *p = 0;
    // p = &n;
    // cout<<"value : "<<*p<<endl;


    // int num = 5;

    // int *p = 0;
    // p = &num;

    // cout<<"old value : "<<num<<endl;

    // (*p)++;

    // cout<<"new value : "<<num<<endl;


    int num = 10;

    int *p = &num;

    int *q = p;

    cout<<"addresses at p and q : " << p <<"  "<<q <<endl;
    cout<<"values at p and q : " << *p <<"  "<<*q <<endl;


    int i = 10;
    int *ptr = &i;

    cout<<"before incrementing : "<<ptr<<endl;
    ptr = ptr + 1;
    cout<<"after incrementing : "<<ptr<<endl;

}