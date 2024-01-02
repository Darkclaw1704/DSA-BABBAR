#include <iostream>
#include <vector>

using namespace std;


void moveZeroes(vector<int>& nums) {
    int i = 0;

    for (int j = 0; j < nums.size(); j++){
        if (nums[j] !=0 ){
            swap(nums[i],nums[j]);
            i++;
        }
    }
}

int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);

    moveZeroes(v);

    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;

}