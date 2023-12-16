#include <iostream>
using namespace std;

int sumOfArray(int size, int array[]){
    int sum=0;

    for (int count = 0; count<size; count++){
        sum+=array[count];
    }

    return sum;
}

int mainArrayFunction(){
    int size;

    cout<<"enter size of array : ";
    cin>>size;

    int array[size];

    for (int count = 0; count<size; count++){
        cout<<"enter value : ";
        cin>>array[count];
    }

    int sum = sumOfArray(size, array);
    cout<<endl<<"sum of array : "<<sum;

    return 0;
}

int initializingArray(){
    int array[100] = {-24};

    cout<<array[0]<<endl;
    cout<<array[1]<<endl;
    cout<<array[2]<<endl;

    return 0;
}

int powerOfTwo(int number){

    while (number/2 != 1) {
        if ((number / 2) % 2 != 0) {
            return 0;
        }
        number /= 2;
    }
    return 1;

}

int reverseArray(){
    int size;
    cout<<"enter size of array : ";
    cin>>size;
    int array[size];
    for (int count = 0; count<size; count++){
        cout<<"enter value : ";
        cin>>array[count];
    }

    int head=0, tail = size-1;

    while (head <= tail){
        swap(array[head++], array[tail--]);
    }

    cout<<"revserd array : "<<endl;
    for (int index =0; index<=size-1; index++){
        cout<<array[index]<<endl;
    }

    return 0;
}

int swapAlternative(){

    int size;
    cout<<"enter size of array : ";
    cin>>size;
    int array[size];
    for (int count = 0; count<size; count++){
        cout<<"enter value : ";
        cin>>array[count];
    }


    int tail=0, head=tail+1;

    while(tail != size && head != size){
//        cout<<tail<<" "<<head<<endl;

        swap(array[tail],array[head]);
        tail+=2;
        head+=2;

//        cout<<tail<<" "<<head<<endl;
    }


    cout<<"reveserd array : "<<endl;
    for (int index =0; index<=size-1; index++){
        cout<<array[index]<<endl;
    }
    return 0;
}

void findDuplicate(){
    int size;
    cout<<"enter size of array : ";
    cin>>size;
    int array[size];
    for (int count = 0; count<size; count++){
        cout<<"enter value : ";
        cin>>array[count];
    }

    int countingDuplicates=0;
    for (int index=0; index<=size-1; index++ ){
        for (int comparingIndex=0; comparingIndex<=size-1; comparingIndex++){
            if (array[index] == array[comparingIndex]){
                countingDuplicates+=1;
            }
        }
        if (countingDuplicates > 1){
            cout<<array[index]<<" has "<<countingDuplicates-1<<" duplicates."<<endl;
        }
        countingDuplicates=0;
    }

}

void intersectionOfArrays(){

    int array1[4]={1,2,3,4};
    int array2[3]={4,3,5};
    int size1 = 4, size2 = 3;


//    for (int index1=0; index1<=size1-1; index1++){
//        for (int index2)
//    }

}

int ninjaAndTriangle(int n) {
    int sum = n, row=0;

    while(sum>0) {
        row++;
        sum -= row;
    }
    if (sum<0)
        return row - 1;
    return row;

}


int main() {

    int height = ninjaAndTriangle(6);
    cout<<height;

    return 0;
}
