#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstOccurance(vector<int>& arr, int n, int k)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int answer = -1;

    while(start<=end){

        if (arr[mid] == k){
            answer = mid;
            end = mid - 1;
        }
        else if (arr[mid] > k){
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        
        mid = start + (end - start)/2 ;
    }

    return answer;

}

int lastOccurance(vector<int>& arr, int n, int k)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int answer = -1;

    while(start<=end){

        if (arr[mid] == k){
            answer = mid;
            start = mid + 1;
        }
        else if (arr[mid] > k){
            end = mid - 1;
        }
        else if (arr[mid] < k){
            start = mid + 1;
        }
        
        mid = start + (end - start)/2 ;
    }

    return answer;

}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOccurance(arr,n,k);
    int second = lastOccurance(arr, n, k);
    
    pair<int,int> pair;
    pair.first = first;
    pair.second = second;

    return pair;
}

// int peakIndexInMountainArray(vector<int> &arr){
//     int start = 0;
//     int end = arr.size() - 1;
//     int mid = start  + (end-start)/2;

//     while (start<=end)
//     {
//         if (arr[mid+1] > arr[mid]){
//             start = mid + 1;
//         }
//         else if (arr[mid-1] > arr[mid])
//         {
//             end = mid - 1;
//         }
//         else if (((arr[mid+1] < arr[mid]) && (arr[mid-1] < arr[mid])) || start == end)
//         {
//             return mid;
//         } 

//         mid = start + (end - start)/2;
//     }
// }

int peakIndexInMountainArray(vector<int> &arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start  + (end-start)/2;

    while (start < end)
    {
        if (arr[mid+1] > arr[mid]){
            start = mid + 1;
        }
        else {
            end = mid;
        }
        mid =  start  + (end-start)/2;
    }
    
    return start;
}

int sum(vector<int>& nums, int from, int to ){
    int sum = 0;

    if((to == -1) || (from == nums.size())){
        return 0;
    }

    for (int index = from; index<=to; index++){
        sum += nums[index];
    }

    return sum;
}

int pivotIndex(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end-start)/2;

    int leftSum;
    int rightSum;

    while (start <= end){
        leftSum = sum(nums, 0, mid-1);
        rightSum = sum(nums, mid+1, nums.size()-1);

        if ( ((leftSum<=0) && (rightSum<=0)) && (-leftSum > -rightSum)){
            end = mid - 1;
        }
        else if ( ((leftSum<=0) && (rightSum<=0)) && (-leftSum < -rightSum)){
            start = mid+1;
        }
        else if ((leftSum>rightSum) ){
            end = mid-1;
        }
        else if ((leftSum<rightSum) || (-leftSum < -rightSum))
        {
            start = mid+1;
        }
        else if (leftSum == rightSum)
        {
            return mid;
        }
        
        mid = start + (end-start)/2;
    }
    return -1;

}

int main(){

    vector<int> testArray;
    testArray.push_back(-1);
    testArray.push_back(-1);
    testArray.push_back(-1);
    testArray.push_back(0);
    testArray.push_back(1);
    testArray.push_back(1);

    int answer = pivotIndex(testArray);

    cout<<answer;

    return 0;
}