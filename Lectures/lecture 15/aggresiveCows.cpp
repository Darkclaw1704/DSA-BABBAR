#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> arr, int k, int mid){
    int lastPosition = 0 ;
    int cow = 1;

    int n = arr.size();

    // sort(arr.begin(), arr.end());

    for (int i = 1; i<n; i++){
        if (arr[i] - arr[lastPosition]  >= mid ){
            cow ++;
            lastPosition = i;
        }
        if (cow == k){
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    
    sort(stalls.begin(), stalls.end());
    
    int start = 0;
    auto max = max_element( stalls.begin(), stalls.end());
    auto min = min_element(stalls.begin(), stalls.end());
    int end = *max - *min;

    int mid = start + (end-start)/2;

    int answer = -1;

    while (start <= end)
    {
        if (isPossibleSolution(stalls, k, mid)){
            answer = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }


    return answer;
}


int main(){
    vector<int> testArray;
    testArray.push_back(3);
    testArray.push_back(1);
    testArray.push_back(2);
    testArray.push_back(6);
    testArray.push_back(4);

    int answer = aggressiveCows(testArray,2);

    cout<<answer;

}
