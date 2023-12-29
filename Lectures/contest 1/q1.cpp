#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long appleAndCoupon(int n, int m, vector<int> arr){
    sort(arr.begin(),arr.end());
    long long coins = 0;

    for ( int i = n-m; i<n; i++){
        coins += arr[i];
    }

    return coins;
}

int main(){
    vector<int> testArray;
    testArray.push_back(3);
    testArray.push_back(2);


    long long answer = appleAndCoupon(2,2,testArray);

    cout<<answer;

}