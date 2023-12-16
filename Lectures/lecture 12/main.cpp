#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = (start) + (end - start)/2;

    while (start<=end)
    {
        if (arr[mid] == key){
            return mid;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        
        mid = (start + end) / 2;

    }

    return -1;

}

int main(){
    int arr[6] = {1,2,3,5,6};

    int index = binarySearch(arr,5,4);
    cout<<index;

    return 0;
}
