#include <iostream>
#include <vector> 
#include <cstdlib>

using namespace std;

int sort(vector<int>& arr, int start, int end){
    int pivot = arr[start];
    int count = 0;

    for(int i = start; i<=end; i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    // cout<<count<<endl;

    int pivotIndex = start + count;

    swap(arr[start],arr[pivotIndex]);

    int i = start;
    int j = end;

    while(i<pivotIndex && j>pivotIndex){
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] >= pivot)
        {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
            // cout<<arr[i]<<" : "<<arr[j]<<endl;
            // exit(0);
        }        
    }

    // cout<<"pivot : "<<pivot<<" , pivotIndex : "<<pivotIndex<<endl; 

    return pivotIndex;

}

void quickSort(vector<int>& arr, int start, int end){
    if(start>=end){
        return ;
    }

    int pivotIndex = sort(arr,start,end);
    quickSort(arr,start,pivotIndex-1);
    quickSort(arr,pivotIndex+1,end);
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);

    quickSort(v,0,v.size()-1);

    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;

}