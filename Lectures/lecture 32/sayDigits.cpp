#include <iostream>
using namespace std;

void sayDigit(int n){

    if(n==0){
        return;
    }

    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    int digit = n%10;
    n = n/10;

    sayDigit(n);

    cout<<arr[digit]<<" ";

}

int main(){
    int n = 0;

    sayDigit(n);

}