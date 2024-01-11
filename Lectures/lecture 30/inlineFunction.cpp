#include <iostream>
using namespace std;

inline int getMax(int& a, int& b){
    return a>b ? a : b;
}

int main(){
    int a = 1;
    int b = 2;
    int ans;

    ans = getMax(a,b);
    cout<<ans<<endl;

    a+=3;
    b+=1;

    ans = getMax(a,b);
    cout<<ans<<endl;
}