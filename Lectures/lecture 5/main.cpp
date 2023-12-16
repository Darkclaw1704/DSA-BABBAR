#include <iostream>
using namespace std;


int bitwiseOperations(){
    int number1 = 5, number2;

    number2 = ~ number1;
    cout<<"~"<<number1<<" = "<<number2<<endl;

    number2 = 5 & 7;
    cout<<"5 & 7 = "<<number2<<endl;

    number2 = 5 ^ 7;
    cout<<"5 ^ 7 = "<<number2<<endl;

    return 0;
}

int fibonacci(){
    int number, present , next, nextNumber;
    cin>>number;

    present=0;
    next=1;

    for (int count = 1; count <= number; count++){
        cout<<present<< endl;

        nextNumber = present + next;
        present = next;
        next = nextNumber;
    }

    return 0;
}

int leetcode191(){
//    uint32_t n= 00000000000000000000000000001010;
//    int bits=0;
//
//
//
//    uint32_t allZeroBits = 00000000000000000000000000000000;
//    uint32_t lastBitOne = 00000000000000000000000000000001;
//
//    while(n != allZeroBits){
//        if (n & lastBitOne == lastBitOne){
//            bits+=1;
//        }
//        n = n>>1;
//    }
//
//    cout<< bits;

    return 0;
}

int leetcode1009(){
    int n =5;
    int length = 1;

    while (length < n){
        cout<<length << endl;
        length = length << 1;
        length += 1;

        cout<<length << endl<<endl;
    }

    cout<< n<<endl;
    cout<< length<< endl;
    cout<< "answer: "<<(length ^ n)<< endl;

    return 0;
}

int main() {

    leetcode1009();

    return 0;
}
