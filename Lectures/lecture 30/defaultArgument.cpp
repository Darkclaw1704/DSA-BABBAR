#include <iostream>
using namespace std;

void print(int arr[], int size, int start = 0){
    for(int i =start; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;

    print(arr,size);
    cout<<endl;
    print(arr,size,3);

}