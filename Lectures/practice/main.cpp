#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int findPivot(vector<int>& arr){
    int start = 0;
    int end = arr.size() -1 ;
    int mid = start + (end-start)/2;

    while (start <= end)
    {
        if (arr[mid] < arr[0]){
            end = mid - 1;
        }
        else{
            start = mid;
        }

        mid = start + (end-start)/2;
    }
    
    return mid;

}



int main(){

    vector<int> testArray;
    testArray.push_back(3);
    testArray.push_back(8);
    testArray.push_back(10);
    testArray.push_back(17);
    testArray.push_back(1);

    int answer = findPivot(testArray);

    cout<<answer;

    return 0;
}