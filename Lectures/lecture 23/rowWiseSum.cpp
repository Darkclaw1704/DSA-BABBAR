#include <iostream>
using namespace std;

void rowSum(int arr[][3], int row, int col){
    int sums[row];

    for(int i =0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }
        sums[i] = sum;
    }

    for(int i = 0; i < row; i++){
        cout<<sums[i]<<endl;
    }
}

int main(){
    int arr[3][3] = {3, 4, 11, 2, 12, 1, 7, 8, 7};

    rowSum(arr, 3, 3);

}


