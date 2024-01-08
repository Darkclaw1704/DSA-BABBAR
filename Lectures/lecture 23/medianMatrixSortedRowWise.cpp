#include <iostream>
#include <vector>

using namespace std;

int isMedian(vector<vector<int>> &matrix, int R, int C, int number){
    int smaller = 0;
    int larger = 0;
    int equals = 0;
    
    for (int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            
            // cout<<"i:"<<i<<" j:"<<j<<endl;
            // cout<<matrix[i][j]<<" & "<<number<<endl;

            if (matrix[i][j] > number){
                // cout<<"condition 1 "<<endl;
                larger++;
            }
            else if (matrix[i][j] < number){
                
                // cout<<"condition 2 "<<endl;
                smaller++;
            }
            else if (matrix[i][j] == number){
                
                // cout<<"condition 3 "<<endl;
                equals++;
            }

            // cout<<"--------------------------------"<<endl;
        }
    }
    
    if (equals > 0){
        equals--;
    }

    // cout<<" n : "<<number<<", smaller : "<<smaller<<", equals : "<<equals<<", larger : "<<larger<<endl;

    if(smaller == larger){
                    // cout<<" returning 0 --------------------------------"<<endl;
        return 0;
    }
    else if(smaller > larger){
        if(smaller <= equals + larger){
            // cout<<" returning 0 --------------------------------"<<endl;
            return 0;
        }
        else{
            // cout<<" returning 1 --------------------------------"<<endl;
            return 1;
        }
    }
    else if(larger > smaller){
        if(larger <= equals + smaller ){
            // cout<<" returning 0 --------------------------------"<<endl;
            return 0;
        }
        else{
            // cout<<" returning -1 --------------------------------"<<endl;
            return -1;
        }
    }
    
}


int median(vector<vector<int>> &matrix, int R, int C){
    int rowIndex = 0 ;
    int colIndex = C - 1;
    
    while(rowIndex<R && colIndex>=0){

        if(isMedian(matrix, R, C, matrix[rowIndex][colIndex]) == 0){
            return matrix[rowIndex][colIndex];
        }
        else if(isMedian(matrix, R, C, matrix[rowIndex][colIndex]) == 1){
            colIndex--;
        }
        else if(isMedian(matrix, R, C, matrix[rowIndex][colIndex]) == -1){
            rowIndex++;
        }
    }
    
}


int main(){
    vector<vector<int>> matrix;

    vector<int> row1;
    row1.push_back(1);
    row1.push_back(3);
    row1.push_back(5);

    vector<int> row2;  // Corrected from row1 to row2
    row2.push_back(2);  // Corrected from row1 to row2
    row2.push_back(6);  // Corrected from row1 to row2
    row2.push_back(9);  // Corrected from row1 to row2

    vector<int> row3;  // Corrected from row1 to row3
    row3.push_back(3);  // Corrected from row1 to row3
    row3.push_back(6);  // Corrected from row1 to row3
    row3.push_back(9);  // Corrected from row1 to row3

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    // print(matrix, 3, 3);

    int answer = median(matrix,3,3);
    cout<<answer;
}
