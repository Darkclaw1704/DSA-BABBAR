#include <iostream>
#include <vector>

using namespace std;

    void merge(vector<int>& arr, int start, int end){
        int mid = start + (end-start)/2;

        int size1 = mid - start + 1;
        int size2 = end - mid;

        int *arr1 = new int[size1];
        int *arr2 = new int[size2];

        for(int i = 0; i<size1; i++){
            arr1[i] = arr[start+i];
        }
        for(int j = 0; j<size2; j++){
            arr2[j] = arr[mid+1+j];
        }

        int arr1Index = 0;
        int arr2Index = 0;

        int mainIndex = start;

        while(arr1Index < size1  &&  arr2Index < size2){
            if(arr1[arr1Index] < arr2[arr2Index]){
                arr[mainIndex++] = arr1[arr1Index++];
            }
            else{
                arr[mainIndex++] = arr2[arr2Index++];
            }
        }

        while(arr1Index<size1){
            arr[mainIndex++] = arr1[arr1Index++];
        }
        while(arr2Index<size2){
            arr[mainIndex++] = arr2[arr2Index++];
        }

        delete [] arr1;
        delete [] arr2;

    }

    void mergeSort(vector<int>& arr, int start, int end){
        if(start >= end){
            return ;
        }

        int mid = start + (end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,end);

    }
