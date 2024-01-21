#include <iostream>
#include <vector>

using namespace std;

void decimalToBinary(int n, int arr[], int capacity){
    int length = 0;
    int x = n;
    while(x!=0){
        length++;
        x = x>>1;
    }
    
    
    
    
    
    
    
    
}

int makeItEqual(int a, int b, int c) {
    int max = a;
    if(b>max){
        max = b;
    }   
    if(c>max){
        max = c;
    }

    int capacity = 0;
    
    if(max == 0){
        capacity = 1;
    }
    else{
        while(max!=0){
            // cout<<"max : "<<max<<endl;
            capacity++;
            max = max>>1;
        }
    }
    


    bool *A = new bool[capacity];
    bool *B = new bool[capacity];
    bool *C = new bool[capacity];
    
    // decimalToBinary(a,A,capacity);
    return capacity;
    
    
    
}

    
    
int main() {
    int answer = makeItEqual(0,0,0);
    cout<<answer;
}