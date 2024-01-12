#include <iostream>
using namespace std;

bool binarySearch(int arr[],  int start, int end, int key){
    if(start > end){
        return false;
    }

    int mid = start + (end-start)/2;
    
    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] > key ){
        bool answer = binarySearch(arr,start,mid-1,key);
        return answer;
    }
    else{
        bool answer = binarySearch(arr,mid+1,end,key);
        return answer;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 5;

    bool answer = binarySearch(arr,0,size-1,key);
    cout<<answer;

}