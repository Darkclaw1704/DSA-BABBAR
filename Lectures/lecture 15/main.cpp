#include <stdio.h>
#include <vector>
using namespace std;

bool possiblePages(vector<int>& arr, int n, int m, int mid){
    int student = 1;
    int sumOfPages = 0;

    for (int book = 0; book<n; book++ ){

        if (sumOfPages + arr[book] <= mid){

            sumOfPages += arr[book];
        }
        else {
            student++;

            if((student > m) || (arr[book]>mid)){
                return false;
            }

            sumOfPages = arr[book];

        }
    }

    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    int start = 0;
    int end = 0;
    for (int index=0; index<n; index++){
        end += arr[index];
    }

    int mid = start + (end-start)/2;

    int answer = -1;

    if (n<m){
        return -1;
    }

    while (start<=end)
    {
        if (possiblePages(arr, n, m ,mid)){
            answer = mid;
            end = mid - 1;
            
        }
        else{
            start = mid + 1;
        }

        mid = start + (end-start)/2;

    }

    return answer;

}

bool isPossible(vector<int> &boards, int k, int mid){

    int painter = 1;
    int sumOfArea = 0; 

    for (int index = 0; index < boards.size(); index++){
        if (sumOfArea + boards[index] <= mid){
            sumOfArea = sumOfArea + boards[index];
        }
        else{
            painter++;

            if((painter > k) || boards[index] > mid){
                return false;
            }

            sumOfArea = boards[index];
        }
    }

    return true;

}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int start = 0;

    int sum = 0;
    for (int index=0; index<boards.size(); index++){
        sum += boards[index];
    }

    int end = sum;
    int mid = start + (end - start)/2;

    int answer = -1;

    while(start<=end){
        if (isPossiblePages(boards, k, mid)){
            answer = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end - start)/2;

    }

    return answer;
}

bool isPossibleDistance(vector<int> &stalls, int k, int mid){
    int cow = 1;
    int distance = 0;

    for (int index = 0; index<stalls.size(); index++){
        if (distance + stalls[index] <= mid){
            distance += stalls[index];
        }
        else{
            cow ++ ; 

            if ((cow > k) || ( stalls[index] > mid ) ){
                return false;
            }

            distance = stalls[index];
        }
    }

    return true;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int start = 0;
    int sum = 0;
    for (int index=0; index<stalls.size(); index++){
        sum += stalls[index];
    }
    int end = sum;

    int mid = start + (end - start)/2;
    int answer = -1;

    while(start <= end){
        if (isPossibleDistance(stalls,k,mid)){
            answer = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1 ;
        }

        mid = start + (end - start)/2;
    }

    return answer;
}

int main(){

    // 12 34 67 90
    // m = 2

    return 0;
}