#include <iostream>
using namespace std;

void reverse(string &arr, int i , int j){
    if(i>=j){
        return ;
    }

    swap(arr[i],arr[j]);
    reverse(arr,i+1,j-1);
}

int main(){
    string name = "lakshay";
    int n = 7;

    reverse(name,0,n-1);

    cout<<name;


}