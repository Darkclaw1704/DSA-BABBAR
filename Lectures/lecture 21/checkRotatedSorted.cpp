#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int>& nums){
    int start = 0;
    int end = nums.size() - 1;

    if ( nums[start] < nums[end]){
        return start;
    }

    int mid = start + (end-start)/2;

    while (start < end)
    {
        if (nums[0] > nums[mid]){
            end = mid;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }

    return mid;
}

bool check(vector<int>& nums) {
    int p = pivot(nums);

    // cout<<p<<endl;

    for(int i = p ; ; i++ ){
        
        i = i % nums.size();

        if ( i == p - 1 ){
            break;
        }

        if (nums[i] > nums[(i+1) % nums.size()]){
            return false;
        }

    }

    return true;
}

int main(){

    vector<int> testArray;
    testArray.push_back(1);
    testArray.push_back(2);
    testArray.push_back(3);
    // testArray.push_back(2);
    // testArray.push_back(3);
    // testArray.push_back(4);

    bool answer = check(testArray);


    cout<<answer;
}