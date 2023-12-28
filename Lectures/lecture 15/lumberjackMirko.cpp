#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> arr, int m, int mid){
    int metres = 0;

    for ( int i = 0; i <  arr.size(); i++){
        if (arr[i] > mid){
            metres += (arr[i] - mid);
        }
    }

    if (metres >= m ){
        return true;
    }
    else{
        return false;
    }


}

int chopChop(vector<int> arr, int m){
    int start = 0;
    int end = 0;
    for ( int i=0; i<arr.size(); i++){
        end += arr[i];
    }

    int mid = start + (end-start)/2;

    int answer  = -1;

    while (start <= end)
    {
        if (isPossibleSolution(arr, m, mid)){
            answer = mid;
            start = mid + 1;
        }
        else{

            end = mid - 1;
        }

        mid = start + (end-start )/2;
    }
    
    return answer;

}

int main(){
    vector<int> testArray;
    testArray.push_back(4);
    testArray.push_back(42);
    testArray.push_back(40);
    testArray.push_back(26);
    testArray.push_back(46);

    int answer = chopChop(testArray,20);

    cout<<answer;
}