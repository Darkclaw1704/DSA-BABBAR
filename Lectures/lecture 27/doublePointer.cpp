#include <iostream>
using namespace std;

int main(){
    int value = 5;
    int *p = &value;
    int **ptr = &p;

    (**ptr)++;

    cout<<**ptr;

}