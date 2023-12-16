#include <iostream>
using namespace std;


int main(){
    int number, counter, originalNumber;
    cin>>number;
    counter = number;
    originalNumber = counter;

    while (number>=1)
    {
        counter = originalNumber;
        while (counter>=1)
        {
            cout<<number;
            counter -= 1;
        }
        cout<<endl;
        number-=1;
    }

    return 0;

}