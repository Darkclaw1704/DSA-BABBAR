#include <iostream>
using namespace std;

void update1(int *p){
    p = p + 1;
    cout<<"inside : "<<p<<endl;
}

void update2(int *p){
    *p = *p + 1;
    cout<<"inside : "<<*p<<endl;
}

int main(){
    int value = 5;
    int *p = &value;

    cout<<"before : "<<p<<endl; 
    update1(p);
    cout<<"after : "<<p<<endl; 

cout<<"----------------------------"<<endl;

    cout<<"before : "<<*p<<endl; 
    update2(p);
    cout<<"after : "<<*p<<endl; 

    

}