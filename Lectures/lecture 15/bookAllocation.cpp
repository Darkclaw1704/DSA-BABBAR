#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> array, int mid, int n ,int m){

    int sum = 0;

    int student = 1;

    for (int book = 0; book <n ; book++ ){
        if (sum + array[book] <= mid ){
            sum += array[book];
        }
        else{
            student++;
            
            if ((student > m) || (array[book] > mid)){
                return false;
            }

            sum = array[book];
        }

    }

    return true;
}

int findPages(vector<int> array, int n ,int m){
    int start = 0;

    int end = 0;
    int index = 0;
    while (index < array.size())
    {
        end += array[index];
        index++;
    }

    int mid = start + (end-start)/2;
    int answer = -1;

    if (n<m){
        return -1;
    }

    while (start <= end)
    {
        if ( isPossibleSolution(array, mid, n ,m)){            
            answer = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }


    return answer;
    
}


int main(){
    vector<int> testArray;
    testArray.push_back(25);
    testArray.push_back(46);
    testArray.push_back(28);
    testArray.push_back(49);
    testArray.push_back(24);

    int answer = findPages(testArray, testArray.size(),4);

    cout<<answer;
}