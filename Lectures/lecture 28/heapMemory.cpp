#include <iostream>
using namespace std;

int main(){
    char *ptr = new char;
    *ptr = 65;
    cout <<"value at heap memory : "<<*ptr<<endl;

    while(true){
        int i = 5;
    }

    // while(true){
    //     int *p = new int;
    // }

    int *p = new int;
    delete p;

}


