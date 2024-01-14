#include <iostream>
using namespace std;

double power(double x, int n) {
    // cout<<" n : "<<n<<endl; 
    if(n==0){
        return 1;
    }

    if(n%2 == 0){
        // cout<<" even : "<<n<<endl;
        double answer = power(x,n/2);
        answer = answer * answer;
        return answer;
    }
    else{
        // cout<<" odd : "<<n<<endl;
        double answer = power(x,n/2);
        answer = x * answer * answer;
        return answer;
    }
}

double myPow(double x, int n) {

    double answer = power(x,n);
    if(n <0){
        return 1/answer;
    }

    return answer;

}

int main(){
    double a = 2;
    int b = -3;

    cout<<myPow(a,b);

}