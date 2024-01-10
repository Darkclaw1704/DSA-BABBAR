#include <iostream>
using namespace std;

void update1(int n){
    n++;
}

void update2(int &n){
    n++;
}

int main(){
    int i = 5;

    cout<<"before update : "<<i<<endl;
    update1(i);
    cout<<"after update : "<<i<<endl;

    cout<<" --------------------------------------- "<<endl;


    cout<<"before update : "<<i<<endl;
    update2(i);
    cout<<"after update : "<<i<<endl;


}