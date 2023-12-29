#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for ( int i =0; i < n-1 ; i++){

        int min = i;

        for (int j = i+1; j<n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        swap(arr[i],arr[min]);

    }
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(4);

    selectionSort(arr,arr.size());

    for ( int i =0; i<arr.size(); i++){
        cout<<arr[i]<<endl ;
    }

}