#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int i){
    if(i == arr.size()){
        return;
    }

    int minimum = i;
    
    for(int j = i+1; j <arr.size(); j++){
        if(arr[minimum] > arr[j]){
            minimum = j;
        }
    }
    cout<<"min : "<<arr[minimum] <<endl;

    swap(arr[i],arr[minimum]);

        for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;

    selectionSort(arr,i+1);
}

void sortColors(vector<int>& nums) {
    selectionSort(nums,0);
}

int main(){
    vector<int> v;
    v.push_back (2);
    v.push_back (0);
    v.push_back (2);
    v.push_back (1);
    v.push_back (1);
    v.push_back (0);

    sortColors(v);

    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;
}