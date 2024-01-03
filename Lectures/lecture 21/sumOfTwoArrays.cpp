#include <iostream>
#include <vector>

using namespace std;

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    int i = -a.capacity() + n;
    int j = -b.capacity() + m;
    int k = i;
    
    vector<int> answer(n,0);

    while (j >= -m)
    {
        if (a[i] + b[j] > 9){
            answer[k] += (a[i] + b[j]) - 10;
            answer[k-1] += 1;
        }
        else{
            answer[k] += (a[i] + b[j]) ;
        }

        i--;
        j--;
        k--;

    }

    while (i >= -n)
    {
        if (answer[k] + a[i] > 9){
            answer[k] = 0;
        }
        else{
            answer[k] += a[i];
        }

        i--;
        k--;
    }

    return answer;

}


int main(){
    // vector<int> num1;
    // num1.push_back(4);
    // num1.push_back(5);
    // num1.push_back(1);


    // vector<int> num2;
    // num1.push_back(3);
    // num1.push_back(4);
    // num1.push_back(5);

    // vector<int> answer = findArraySum(num1,3,num2,3);

    // for(int i : answer){
    //     // cout<<i;
    // }


    cout<<18/10;
    

    
}