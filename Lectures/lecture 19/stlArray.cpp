#include <iostream>
#include <array>

using namespace std;

int main(){
    int basicArray[ 3] = {1,2,3};

    array<int,4> arr = {1,2,3,4};

    int size = arr.size();

    for(int i =0; i <size; i++){
        cout<<arr[i]<<endl;
    }

    cout<<"element at 3rd index : "<<arr.at(3)<<endl;
    cout<<"empty or not : "<<arr.empty()<<endl;
    cout<<"firt element : "<<arr.front()<<endl;
    cout<<"last element : "<<arr.back()<<endl;

}