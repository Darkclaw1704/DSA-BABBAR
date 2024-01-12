#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }

    else{
        bool answer = isSorted(arr+1, size-1);
        return answer;
    }
}

int main(){
    int arr[5] = {1,1,1,1,1};
    bool answer = isSorted(arr,5);
    cout<<answer;
}
