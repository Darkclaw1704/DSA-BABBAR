#include <iostream>
using namespace std;

int findPivot(int arr[], int start, int end){
    if (start >= end){
        return start;
    }

    int answer;
    int mid = start+(end-start)/2;

    if(arr[0] >= arr[mid]){
        answer = findPivot(arr,start,mid);
        return answer;
    }
    else{
        answer = findPivot(arr,mid+1,end);
        return answer;
    }

}

int main(){
    int arr[2] = {3,1};

    int answer = findPivot(arr,0,1);
    cout<<answer;
}

