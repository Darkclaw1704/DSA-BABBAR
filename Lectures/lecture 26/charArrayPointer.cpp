#include <iostream>
using namespace std;

int main(){
    // int arr[6] = {2,5,6,8,9,69}; 
    // char ch[6] = "megha"; // null character takes 1 space so thats why 6

    // cout<<"cout for int array : "<<arr<<endl;
    // cout<<"cout for char array : "<<ch<<endl;

    // cout<<"cout for 0th element of char array : "<<&ch[0]<<endl;

    // char *ptr = &ch[0];
    // cout<<"printing the cout for pointer pointing to 0th address of char array : "<<ptr<<endl;



    char single = 'z';
    char *C = &single;

    cout<<"cout for single character : "<<C<<endl;

    return 0;
}