#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivotOfSortedRotatedArray(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;

    int mid = start + (end-start)/2;

    while (start<end)
    {
        if (arr[mid] > arr[end]){
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        
        mid = start + (end-start)/2;
        
    }

    return mid;
    
}


int search(vector<int>& arr, int n, int k)
{
    int start; 
    int end;

    if (k <= arr[arr.size()-1]){
        start = pivotOfSortedRotatedArray(arr);
        end = arr.size() - 1;
    }
    else{
        start = 0;
        end = pivotOfSortedRotatedArray(arr) - 1;
    }

    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if (arr[mid]<k){
            start = mid + 1;
        }
        else if((arr[mid]>k)){
            end = mid - 1;
        }
        else{
            return mid;
        }

         mid = start + (end - start)/2;
    }

    return - 1;

}

int main(){
    
    vector<int> testArray;
    testArray.push_back(1);
    testArray.push_back(2);
    testArray.push_back(4);
    testArray.push_back(5);

    int answer = pivotOfSortedRotatedArray(testArray);

    cout<<answer;

    return 0;
}