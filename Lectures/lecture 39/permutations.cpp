#include <iostream>
#include <vector>

using namespace std;


void nextPosition(int index, vector<int> present, vector<vector<int>> &possibilities){
    if(index >= present.size()){
        possibilities.push_back(present);
        return;
    }

    int firstElement = present[index];

    for(int j = index; j<present.size(); j++){

        swap(present[index], present[j]);
        nextPosition(index+1,present, possibilities);
        swap(present[index], present[j]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> possibilities;
    vector<int> present;
    int index = 0;

    nextPosition(index, nums, possibilities);

    return possibilities;

}
