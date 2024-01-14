#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int i){
    if(i == arr.size()){
        return ;
    }

    int temp = arr[i];

    int j = i-1;

    for(; j>=0; j--){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
        }
        else{
            break;
        }
    }

    arr[j+1] = temp;

    insertionSort(arr,i+1);
}
