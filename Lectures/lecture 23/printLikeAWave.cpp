#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{   
    int row = 0;
    int col = 0;

    vector<int> sineArray;

    int inc_dec = 1;

    while(col<mCols){
        
        if(col%2 == 0){
            row = 0;
            while(row<nRows){
                sineArray.push_back(arr[row][col]);
                row++;
            }
        }
        else{
            row = nRows - 1;
            while(row>=0){
                sineArray.push_back(arr[row][col]);
                row--;
            }
        }

        col++;

    }

    return sineArray;
} 