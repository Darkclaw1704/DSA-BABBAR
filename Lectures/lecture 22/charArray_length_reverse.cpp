#include <iostream>

using namespace std;

void reverse(char name[], int n){
    int i = 0;
    int j = n-1;

    while (i<j)
    {
        swap(name[i],name[j]);
        i++;
        j--;
    }
    
}

int getLength(char name[]){
    int i =0;
    for(; name[i]!= '\0'; i++){
    }
    return i;
}

int main(){

    char name[10];
    cout<<"Enter your name : "<<endl;
    cin>>name;

    // name[2] = '\0';

    cout<<"Your name is "<<name<<endl;
    cout<<"length of your name : "<<getLength(name);
    reverse(name, getLength(name));
    cout<<"reversed name : "<<name;
}