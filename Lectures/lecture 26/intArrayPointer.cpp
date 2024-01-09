#include <iostream>
using namespace std;

int main(){
    int arr[10]={2,5,6};

    cout<<"address of arr : "<<arr<<endl;
    cout<<"address of arr : "<<&arr<<endl;
    cout<<"address of arr : "<<&arr[0]<<endl;

    cout<<"addres of 2nd element of array : "<<&arr[1]<<endl;

    cout<<"delimiter at arr : "<<*arr<<endl;
    cout<<"(delimiter at arr) + 1 : "<<*(arr)+1<<endl;
    cout<<"delimiter at (arr+1) : "<<*(arr+1)<<endl;

    cout<<"using size of on arr : "<<sizeof(arr)<<endl;
    cout<<"using size of on &arr : "<<sizeof(&arr)<<endl;
    cout<<"using size of on &arr[0] : "<<sizeof(&arr[0])<<endl;

    // arr = arr + 1;

    int *p = arr;

    cout<<"before incrementing : "<<*p<<endl;
    p = p + 1;
    cout<<"after incrementing : "<<*p<<endl;

}