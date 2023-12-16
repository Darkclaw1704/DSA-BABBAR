#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int> &arr){
    for (int index=0; index<arr.size(); index++){
        cout<<arr[index]<<endl;
    }
}

void dynamicArray(vector<int> vectorArray){
    vectorArray.push_back(1);
    vectorArray.push_back(2);
    vectorArray.push_back(3);

    for (int iteration=0; iteration < vectorArray.size(); iteration++){
        cout<<vectorArray[iteration]<<endl;
    }
    cout<<"size of vector : "<<vectorArray.size()<<endl;
}

bool uniqueOccurrences(vector<int>& arr) {

    std::sort(arr.begin(), arr.end());

    int number = arr[0];
    vector<int> occurances;
    int count = 0;

    for (int iteration=0; iteration<arr.size(); iteration++){
        if (number == arr[iteration]) {
            count++;
        }else{
            occurances.push_back(count) ;
            number = arr[iteration];
            count = 1;
        }
    }
    occurances.push_back(count);

    std::sort(occurances.begin(), occurances.end());


    for(int index=0; index<occurances.size(); index++){
        count = std::count(occurances.begin(), occurances.end(),occurances[index]);
        if (count != 1){
            return 0;
        }
    }
    return 1;

}




int findOneDuplicate(vector<int> &arr){
    int n=arr.size() - 1;
    int sumOfNaturalNumbers = n * (n+1) / 2;

    int sumOfArray=0;

    for (int iteration=0; iteration<arr.size(); iteration++){
        sumOfArray += arr[iteration];
        cout<<arr[iteration]<<endl;
    }

    return (sumOfArray - sumOfNaturalNumbers);

}

vector<int> findManyDuplicates(vector<int>& nums) {
    vector<int> ans;

    for (int iteration = 0; iteration < nums.size(); iteration++){

        for(int matchingIteration = 0; matchingIteration<nums.size(); ){
            if ( (iteration!=matchingIteration) && (nums[iteration] == nums[matchingIteration])){
                ans.push_back(nums[iteration]);
                nums.erase(nums.begin()+iteration);

            } else{
                matchingIteration++;
            }
        }
    }

    return ans;
}


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> fromSortedArray;
    vector<int> toSortedArray;
    vector<int> ans;

    if (n<m) {
        fromSortedArray = arr1;
        toSortedArray = arr2;
    } else{
        fromSortedArray = arr2;
        toSortedArray = arr1;
    }

    int indexOfLastSearched = 0;

    for(int iteration=0; iteration < fromSortedArray.size(); iteration++){

        for (; indexOfLastSearched < toSortedArray.size() ; indexOfLastSearched++){

            if (fromSortedArray[iteration] < toSortedArray[indexOfLastSearched]){
                break;
            }

            if (fromSortedArray[iteration] == toSortedArray[indexOfLastSearched]){
                ans.push_back(toSortedArray[indexOfLastSearched]);
                toSortedArray.erase(toSortedArray.begin() + indexOfLastSearched);
                break;
            }
        }
    }

    return ans;
}

vector<vector<int>> pairSum(vector<int> &arr, int s){

    vector<vector<int>> pairs;
    vector<int> duplicateArr;

    sort(arr.begin(),arr.end());

    for (int iteration=0; iteration<arr.size(); iteration++){
        int find = s - arr[iteration];
        vector<int> pair;
        duplicateArr = arr;

        for (int finding=iteration+1; finding<duplicateArr.size(); finding++){
            if (duplicateArr[finding] == find){
                pair.push_back(duplicateArr[iteration]);
                pair.push_back(duplicateArr[finding]);
                pairs.push_back(pair);
                duplicateArr[finding] = INT_MAX;
//                break;
            }
        }

    }

    return pairs;

}


vector<int> findDuplicates(vector<int>& nums) {

    vector<int> answerArray;

    std::sort(nums.begin(), nums.end());

    for (int index=0; index<nums.size()-1; index++){
        if (nums[index] == nums[index+1]){
            answerArray.push_back(nums[index]);
        }
    }

    return answerArray;

}


int main() {

    vector<int> bigDaddyVector1;
    bigDaddyVector1.push_back(4);
    bigDaddyVector1.push_back(3);
    bigDaddyVector1.push_back(2);
    bigDaddyVector1.push_back(7);
    bigDaddyVector1.push_back(8);
    bigDaddyVector1.push_back(2);
    bigDaddyVector1.push_back(3);
    bigDaddyVector1.push_back(1);

    vector<int> answer = findDuplicates(bigDaddyVector1);

    printArray(answer);

    return 0;
}
