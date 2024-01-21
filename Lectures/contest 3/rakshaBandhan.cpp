#include <iostream>
#include <vector>

using namespace std;

void merge(vector < int > &arr, int start, int end){
    int mid = start + (end-start)/2;

    int size1 = mid+1 - start;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for(int i = 0; i<size1; i++){
        arr1[i] = arr[start+i];
    }

    for(int i = 0; i<size2; i++){
        arr2[i] = arr[mid+1+i];
    }

    int mainIndex = start;
    int firstIndex = 0;
    int secondIndex = 0;

    while(firstIndex < size1 && secondIndex<size2){
        if(arr1[firstIndex] < arr2[secondIndex]){
            arr[mainIndex++] = arr1[firstIndex++];
        }
        else{
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

void mergeSort(vector < int > &arr, int start, int end){
    if (start>= end){
        return ;
    }

    int mid = start + (end-start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr,start,end);
}

int rakshaBandhan(vector < int > arr, int n) {
    mergeSort(arr,0,arr.size()-1);

    int sum = 0;
    int count = 0;

    for(int i = n-1; i>=0; i--){
        if(sum+arr[i] > 0){
            sum+=arr[i];
            count++;
        }
        else{
            break;
        }
    }

    return count;

}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(-2);
    v.push_back(2);
    
    int answer = rakshaBandhan(v,3);
    cout<<answer<<endl;
    cout<<"35 mins, 10/11 cases passed";
    
    
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
