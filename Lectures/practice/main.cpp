#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPivot(int arr[], int n ){

    int start = 0;
    int end = n - 1;

    int mid = start + (end-start)/2;

    while (start<end)
    {
        if (arr[mid] > arr[end]){
            // cout<<"condition1"<<endl;
            start = mid + 1;
        }
        else{
            // cout<<"condition2"<<endl;
            end = mid;
        }

        mid = start + (end-start)/2;
    }

    return mid;
 
}


int binarySearch(int arr[],int start, int end, int k){
    int mid = start + (end-start)/2;

    while (start < end)
    {
        if(arr[mid] == k){
            return mid;
        }
        else if (arr[mid]<k){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
    
        mid = start + (end- start)/2;
    }

    return mid;
    
}

int searchRotatedArray(int arr[], int n, int k){
    int pivot = findPivot(arr, n);

    cout<<pivot<<endl;

    int index;

    if (arr[n-1] < k){
        // cout<<"condition1"<<endl;
        index = binarySearch(arr, 0, pivot - 1,k);
    }
    else if (arr[n-1]>k)
    {
        // cout<<"condition2"<<endl;
        index = binarySearch(arr,pivot,n-1,k);
    } else {
        return n-1;
    }

    if (arr[index] == k ){
        return index;
    }
    return -1 ;
    

}

int main(){

// [7,8,9,10,11,1]
// [0,1,2, 3, 4,5]

    int arr[4] = {2,3,5,8};


    int answer = searchRotatedArray(arr,4,8);

    cout<<answer;

}