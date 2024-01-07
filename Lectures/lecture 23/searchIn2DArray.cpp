#include <iostream>
using namespace std;


bool isPresent(int arr[][3], int k, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j =0; j < col; j++){
            if (k == arr[i][j]){
                return true;
            }
        }
    }

    return false;
}

int main(){

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    bool answer = isPresent(arr, 6, 3, 3);
    cout<<answer;

}