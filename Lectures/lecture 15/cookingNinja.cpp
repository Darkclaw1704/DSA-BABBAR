#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPossibleSolution(vector<int> rank, int m, int mid){
    int totalDishes = 0;

    for(int i =0; i<rank.size(); i++){
        int time = 0;
        int r = rank[i];

        for (int n = 1; ; n++){
            if (n*r + time <= mid){
                time += n*r;
                totalDishes++;
            }
            else{
                break;   
            }
        }
        
        if (totalDishes >= m){
            return true;
        }

    }
    return false;
}


int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(),rank.end());
    int start = rank[0];
    int end = ((m*(m+1))/2) * rank[rank.size()-1];


    int mid = start + (end-start)/2;

    int answer = -1;

    while (start <= end)
    {

        if(isPossibleSolution(rank, m, mid)){
                // cout<<"here1"<<endl;
            answer = mid;
            end = mid - 1;
        }
        else{
                // cout<<"here2"<<endl;
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }
    
    return answer;

}

int main(){
    vector<int> testArray;
    testArray.push_back(1);
    testArray.push_back(2);
    testArray.push_back(3);
    testArray.push_back(4);

    int answer = minCookTime(testArray,11);

    cout<<answer;

}