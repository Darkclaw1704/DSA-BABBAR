#include <iostream>
using namespace std;

void print(int arr[26]){

    for(int i =0; i<26; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

bool checkEqual(int arr1[26], int arr2[26]){
    for(int i = 0; i<26; i++){
        if (arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int count[26] = {0};

    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count[index] ++;
    }

    int count2[26] = {0};
    int windowSize = s1.length();

    int i = 0;

    while(i<windowSize && i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
        print(count2);
    }

    if(checkEqual(count, count2))
        return 1;

    
    // cout<<windowSize<<endl;
    // cout<<"---------------------------------------"<<endl;
    // print(count2);

    while(i<s2.length()){
        int oldIndex = s2[i-windowSize] - 'a';
        int newIndex = s2[i] - 'a';

        count2[oldIndex]--;
        count2[newIndex]++;

        cout<<"--------------------------"<<endl;
        print(count);
        print(count2);
        cout<<"--------------------------"<<endl;

        if(checkEqual(count, count2))
            return 1;

        i++;
    }

    return 0;


}



int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    // cout<<"check:"<<endl;
    // int arr1[26] = {0};
    // arr1[6] = 4;
    // int arr2[26] = {0};
    // arr2[6] = 3;
    // cout<<checkEqual(arr1,arr2)<<endl;

    bool answer = checkInclusion(s1,s2);
    cout<<answer;

}