#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void solve(vector<int>& changes, int binarySelection, vector<vector<int>> &possibilities, int totalCombinations){
    cout<<"binarySelection : "<<binarySelection<<", totalCombinations : "<<totalCombinations<<endl;
    vector<int> present;

    if(binarySelection >= totalCombinations){
        possibilities.push_back(present);
        return;
    }

    int currentBinarySelection = binarySelection;
    int changesIndex = changes.size()-1;

    while(changesIndex >= 0){
        if(1 & currentBinarySelection){
            present.push_back(changes[changesIndex]);
        }
        changesIndex--;
        currentBinarySelection = currentBinarySelection >>1;
    }

    possibilities.push_back(present);

    solve(changes, binarySelection+1, possibilities, totalCombinations);
}


vector<vector<int>> subsets(vector<int>& nums) {
    int binarySelection = 0;

    vector<vector<int>> possibilities;

    int totalCombinations = pow(2,nums.size());

    solve(nums, binarySelection , possibilities, totalCombinations);

    return possibilities;

}

int main(){
    vector<int> changes = {1,2,3};

    vector<vector<int>> answer = subsets(changes);

    for(vector<int> v : answer){
        for(int i : v){
            cout<<i<<" ";
        }cout<<endl;
    }

}