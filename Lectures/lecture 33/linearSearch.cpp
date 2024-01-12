#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key){
    if (size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        bool answer = linearSearch(arr+1, size-1, key);
        return answer;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 5;

    bool answer = linearSearch(arr, size, key);
    cout<<answer;
}