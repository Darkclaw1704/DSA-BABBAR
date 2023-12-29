#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPossibleSolution(int n, vector<int> arr, int  mid){
    int s1 = 0;
    int i = 0;
    for(; i<arr.size(); i++){
        if (s1 + arr[i] <= mid){
            s1 += arr[i];
        }
        else{
            break;
        }
    }

    int s3 =0 ;
    int j = arr.size() - 1;

    for(; j >= 0; j--){
        if (s3 + arr[j] <= s1){
            s3 += arr[j];
        }
        else{
            break;
        }
    }

    if((i<j) && ( s1 == s3) ){
        return true;
    }
    else{
        return false;
    }

}

long long threeWaySplit(int n, vector<int> arr){
    int start = 0;
    int end = 0;
    for(int i =0; i<arr.size(); i++){
        end += arr[i];
    }

    int mid = start + (end - start)/2;

    int answer = -1;

    while (start <= end)
    {
        if (isPossibleSolution(n,arr,mid)){
            answer = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end - start)/2;

    }
    
    return answer;

}
