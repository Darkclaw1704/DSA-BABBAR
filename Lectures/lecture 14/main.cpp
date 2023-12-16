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

int mySqrt(int x) {
    int start = 0;
    int end = x;
    long long int mid = start + (end-start)/2;
    long long int answer = 0;
    int squaredMid;

    while(start < end){

        long long int squaredMid = mid*mid;

        if (squaredMid > x){
            end = mid - 1;
        }
        else if(squaredMid < x){
            start = mid + 1;
        }
        
        else if (squaredMid == x){
            return mid;
        }

        mid = start + (end-start)/2;
        answer = mid;

    }

    long long int answeredSquare = answer*answer;

    if (answeredSquare > x){
        return answer - 1;
    }

    return answer;
}

double precision(int x,int answer, int places){

    double factor = 1;
    double ans = answer;

    for (int i=0; i<places; i++){
        factor = factor/10;

        for (double j=ans; j*j < x ; j = j + factor){
            ans = j;
        }
    }

    return ans;
    
}


int main(){

    vector<int> testArray;
    testArray.push_back(8);
    testArray.push_back(9);
    testArray.push_back(4);
    testArray.push_back(5);

    int x = 37;
    int places = 3;

    float answer = precision(x, mySqrt(x),places);

    cout<<answer;

    return 0;
}