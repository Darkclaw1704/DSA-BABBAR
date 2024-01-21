#include <iostream>
#include <vector>
using namespace std;

bool isSolution(int n, int k, vector<bool> fish, int mid){
    cout<<mid<<" :   ";
    int sum = 0;
    int mainIndex =0;

    for(; mainIndex<mid; mainIndex++){
        sum += 1*fish[mainIndex];
    }


    if(sum >= k){
            cout<<"sum : "<<sum;
        cout<<" : true : mainIndex : "<<mainIndex<<endl;
        return true;
    }

    while(mainIndex<n){
        sum-= fish[mainIndex-mid];
        sum+= fish[mainIndex];

        if(sum >= k){
            cout<<"sum : "<<sum;
            cout<<" : true : mainIndex : "<<mainIndex<<endl;
            return true;
        }
        mainIndex++;
    }
                // cout<<"sum : "<<sum;
    cout<<" : false : mainIndex : "<<mainIndex<<endl;
    return false;

}

int minimumNet(int n, int k, vector<bool> fish)
{
    int start = 0;
    int end = n;

    int mid = start + (end-start)/2;
    int answer = -1;

    while(start<=end){
        if(isSolution(n,  k, fish,  mid)){
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

int main() {
    vector<bool> v = {1,0,0,0,1};
    int target = 3;

    int answer = minimumNet(v.size(),target,v);
    cout<<answer<<endl;
    cout<<"36 mins all passed";
}