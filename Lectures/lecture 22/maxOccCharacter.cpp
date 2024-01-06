#include <iostream>
#include <vector>
using namespace std;

char lowerCase(char ch){
    if (ch>='a' || ch <= 'z'){
        return ch;
    }
    
    return ch - 'A' + 'a';
}

char getMaxOccCharacter(string s){
    vector<int> counts(26,0);
    // int arr[26] = {0};

    for(int i=0; i<s.length(); i++){
        // cout<<lowerCase(s[i])<<" ";
        counts[lowerCase(s[i])- 'a'] ++;
    }
    // cout<<endl;

    for(int i : counts){
        // cout<<i<<" ";
    }
    // cout<<endl;

    int max = 0;
    for (int i = 0; i<26; i++){
        if (counts[max] < counts[i]){
            max = i;
        }
    }

    return 'a' + max;
}

int main(){
    string s = "abb";

    char answer = getMaxOccCharacter(s);

    cout<<answer;
}