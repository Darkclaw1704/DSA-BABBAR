#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


void insertionSort(int n, vector<int> &arr){
    for (int i = 1; i<arr.size(); i++){
        
        int temp = arr[i];

        int j = i-1;
        
        for (; j>=0; j--){
            
            if (temp < arr[j]){    
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }

        arr[j+1] = temp;
    }
}


int main(){
    vector<int> testArray;
    testArray.push_back(2);
    testArray.push_back(6);
    testArray.push_back(1);
    testArray.push_back(8);
    testArray.push_back(4);
    testArray.push_back(5);

    insertionSort(6,testArray);

    for (int i=0; i < testArray.size(); i++){
        cout<<testArray[i]<<endl;
    }
}