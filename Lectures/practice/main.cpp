#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int myBase(int num){
    int start = 0;
    int end = num;
    int mid = start + (end-start)/2;

    int answer ;

    while (start<=end)
    {

        if (pow(mid,2) == num){
            return mid;
        }

        if (pow(mid,2) > num){
            end = mid - 1;
        }
        else if (pow(mid,2) < num){
            answer = mid;
            start = mid + 1;
        }
    
        mid = start + (end-start)/2;
    }

    return answer;

}


double precision(double base,int num, int place){
    int start = 0;
    int end = 9;
    double mid = start + (end-start)/2;

    double answer;
    int div=1;
    for (int i=0; i<place; i++){
        div*=10;
    }

    while (start <= end)
    {
    
        double square =  (base + (mid/div))*(base + (mid/div));        

        if (square == num){
            return base + mid/div; 
        }    
    
        if (square > num){
            end = mid - 1;
        }
        else if (square < num){
            answer = mid;
            start = mid + 1; 
        }

        mid = start + (end-start)/2;
    }


    return base + (answer/div);
    
}

double sqRoot(int num, int places){
    double base = myBase(num);

    for(int i = 1; i <=places ; i++){
        base = precision(base, num, i);
    }
    return base;
    
}

int main(){
    
    vector<int> testArray;
    testArray.push_back(1);
    testArray.push_back(2);
    testArray.push_back(4);
    testArray.push_back(5);

    double answer = sqRoot(101,3);

    cout<<answer;

    return 0;
}

