#include <iostream>
using namespace std;

void walk(int source, int destination){
    if(source == destination){
        cout<<"reached !"<<endl;
        return;
    }

    cout<<"source : "<<source<<", destination : "<<destination<<endl;

    walk(source+1,destination);

}

int main(){
    int source = 0;
    int destination = 0;

    walk(0,10);
    

}