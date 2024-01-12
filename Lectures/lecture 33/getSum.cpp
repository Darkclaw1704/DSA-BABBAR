#include <iostream>
using namespace std;

int getSum(int arr[], int size){
    if (size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    int answer = arr[0] + getSum(arr+1, size-1);
    return answer;
}

int main(){
    int arr[5] = {1,2,3,4,5};

    int answer = getSum(arr, 5);
    cout<<answer;
}
