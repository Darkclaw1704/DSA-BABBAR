#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {

    vector<int> v(nums.size());

    for( int i = 0; i< nums.size(); i++){
        v[ (i+k) % nums.size() ] = nums[i];
    }

    for ( int i =0; i < v.size(); i++){
        nums[i] = v[i];
    }

}


int main(){

    vector<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(5);
    test.push_back(6);

    int k = 2;

    rotate(test, k);

    for(int i:test){
        cout<<i<<" ";
    }cout<<endl;
}