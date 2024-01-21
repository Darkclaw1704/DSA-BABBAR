#include <iostream>
#include <vector>

using namespace std;

void merge(long long arr[], long long N, int start, int end, long long int *count){
    // cout<<"hello"<<endl;
    int mid = start + (end-start)/2;
        
    int size1 = mid+1 - start;
    int size2 = end - mid;
    
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    
    for(int i =0; i<size1; i++){
        arr1[i] = arr[start+i];
    }
    for(int i =0; i<size2; i++){
        arr2[i] = arr[mid+1+i];
    }
    
    int firstIndex = 0;
    int secondIndex = 0;
    int mainIndex = start;
    
    while(firstIndex < size1 && secondIndex<size2){
        if(arr1[firstIndex] < arr2[secondIndex]){
            arr[mainIndex++] = arr1[firstIndex++]; 
        }
        else{
                cout<<arr1[firstIndex]<<" > "<< arr2[secondIndex]<<endl;
                cout<<*count;
                *count = *count + (size1-firstIndex);
                cout<<" -> "<<*count<<endl;

            arr[mainIndex++] = arr2[secondIndex++];
        }
    }

    while(firstIndex < size1){
        arr[mainIndex++] = arr1[firstIndex++];
    }
    while(secondIndex < size2){
        arr[mainIndex++] = arr2[secondIndex++];
    }
    
    delete [] arr1;
    delete [] arr2;
}

void mergeSort(long long arr[], long long N, int start, int end, long long int *count){
    if(start>= end){
        return;
    }
    
    int mid = start + (end-start)/2;
    
    mergeSort(arr,N,start, mid, count);
    mergeSort(arr, N, mid+1, end, count);
    
    merge(arr,N,start,end, count);
}

long long int inversionCount(long long arr[], long long N)
{
    long long int *count = new long long int;
    *count = 0;
    
    mergeSort(arr,N,0,N-1, count);
    return *count;
}

int main(){
    // long long int arr[42] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};

    int size = 4;
    long long int arr[size] = {5, 61, 8, 5};

    long long int answer = inversionCount(arr,size);
    cout<<"my answer : "<<answer<<endl;
    cout<<"correct ans : 3 "<<endl;
}