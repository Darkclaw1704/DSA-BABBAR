#include <iostream>
#include <vector>
using namespace std;

bool isSolution(vector<int>& arr, int mid, int k){
    int sum = 0;
    int i = 0;

    int students = 1;

    while(i<arr.size()){
        if(sum + arr[i] <= mid){
            sum+=arr[i];
        }
        else{
            students++;
            sum=arr[i];
        }

        i++;
    }

    if(students >= k){
        return true;
    }
    return false;

}


int largestSum(vector<int>& arr, int start, int end, int k){
    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(isSolution(arr,mid,k)){
        int answer1= mid;
        int answer2 = largestSum(arr,mid+1, end, k);

        if(answer2 == -1){
            return answer1;
        }
        else{
            return answer2;
        }
    }
    else{
        int answer1 = largestSum(arr,start, mid-1, k);
        return answer1;
    }

}

int giveSolution(vector<int>& arr, int mid, int k){
    int sum = 0;
    int i = 0;
    int largest = 0;

    int students = 1;

    while(i<arr.size()){
        if(sum + arr[i] <= mid){
            sum+=arr[i];
        }
        else{
            students++;
            sum=arr[i];
        }

        if(largest < sum){
            largest = sum;
        }

        i++;
    }

    return largest;
}


int splitArray(vector<int>& nums, int k) {
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum+=nums[i];
    }

    int mid = largestSum(nums,0,sum,k);
    cout<<mid<<endl;
    int answer =     giveSolution(nums, mid, k);

    return answer;
}

int main(){
    vector<int> testVector;
    testVector.push_back(7);
    testVector.push_back(2);
    testVector.push_back(5);
    testVector.push_back(10);
    testVector.push_back(5);

    int k = 2;

    int answer = splitArray(testVector,k);
    
    // bool answer = isSolution(testVector,18,2);
    
    cout<<answer;

}