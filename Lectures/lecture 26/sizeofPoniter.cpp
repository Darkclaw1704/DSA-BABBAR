#include <iostream>
using namespace std;

int sum(int arr[], int n){
    int answer = 0;
    for(int i = 0 ; i<n; i++){
        answer += i[arr];
    }

    return answer;
}

int main(){
    int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    int answer = sum(&arr[5],5);
    cout<<answer;
}