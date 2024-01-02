#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v){
    int start = 0;
    int end = v.size()-1;

    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }    

    return v;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> v_rev =  reverse(v);

    for(int i : v_rev){
        cout<<i<<" ";
    }cout<<endl;
}