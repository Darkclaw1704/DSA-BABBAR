#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#include <bits/stdc++.h> 

bool isPossibleSolution(int n, int m , int k , vector <int> Checkpoints, int mid){
    int poles = 1;
    int distance = 0;
    int foundAt = -1;

    int i = 0;

    for (; i<=k; i++){
        if (binary_search(Checkpoints.begin(),Checkpoints.end(),i+1)){
            foundAt = i;
        }
    }

    if (foundAt != -1){
        poles++;
        i = foundAt + 1;
        foundAt = -1;
    }
    else{
        return false;
    }

    for(;i<n;i++){
                   
        cout<<"distance : "<<distance<<", i : "<<i<<endl;
        cout<<"foundAt : "<<foundAt<<endl;

        if(distance + 1 <= 2*k){
            if (binary_search(Checkpoints.begin(),Checkpoints.end(),i+1)){
                foundAt = i;
            }

            distance++;
            continue;
        }

        if (foundAt == -1){
            if (binary_search(Checkpoints.begin(),Checkpoints.end(),i+1)){
                foundAt = i;
            }
            else{
                return false;
            }
        }

        poles++;
        distance = 0;
        i = foundAt + 1;
        foundAt = -1;
    }

    cout<<"last distance : "<<distance<<endl;


    // cout<<"last distance : "<<distance<<endl;

    if(distance > k){
        if (foundAt != -1){
            // cout<<"foundat : "<<foundAt<<endl;
            poles++;
        }
        else{
            return false;
        }
    }

    if (poles-1 <= mid){
        cout<<"true"<<endl;
        cout<<"----------------------------------"<<endl;
        return true;
    }
    
    cout<<"false"<<endl;
    
        cout<<"----------------------------------"<<endl;
    return false;



}


int LightUptheStreet(int n, int m , int k , vector <int> Checkpoints){
    int start = 0;
    int end = m;

    int mid = start + (end-start)/2;

    int answer = -1;

    while(start <= end){
        cout<<"mid : "<<mid<<endl;
        if (isPossibleSolution(n, m ,  k ,  Checkpoints, mid)){
            answer = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }

    return answer;

}

int main(){
    int n = 32;
    int m = 10;
    int k = 4;
    vector<int> C;
    C.push_back(2);
    C.push_back(6);
    C.push_back(9);
    C.push_back(11);
    C.push_back(12);
    C.push_back(19);
    C.push_back(20);
    C.push_back(22);
    C.push_back(23);
    C.push_back(27);

    int answer = LightUptheStreet(n,m,k,C);

    cout<<answer;

}