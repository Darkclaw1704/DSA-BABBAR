#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row*col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    vector<int> ans;

    while(count<total){

        for(int i = startingCol; count<total && i<=endingCol; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i = startingRow; count<total && i<=endingRow; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i = endingCol; count<total && i>=startingCol; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i = endingRow; count<total && i>=startingRow; i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;

    }

    return ans;

}


