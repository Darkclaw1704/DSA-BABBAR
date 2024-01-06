#include <iostream>
using namespace std;

char lowerCase(char letter){
    if (letter >= 'a' && letter <= 'z')
        return letter;

    return letter - 'A' + 'a';
}

bool isValid(char ch){
    if ((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <='z') || (ch >='0' && ch <= '9')){
        return true;
    }

    return false;
    
}

bool checkPalindrome(string s)
{
    int i =0;
    int j = s.length()-1;

    while(i<j){
        if (!isValid(s[i])){
            cout<<"not alphabet (i) : "<<s[i]<<endl;
            i++;
            continue;
        }
        if (!isValid(s[j])){
            cout<<"not alphabet (j) : "<<s[i]<<endl;
            j--;
            continue;
        }

        if (lowerCase(s[i]) != lowerCase(s[j])){
            cout<<"not same : "<<lowerCase(s[i])<<" "<<lowerCase(s[j])<<endl;
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string s = "A1b22Ba";

    bool answer = checkPalindrome(s);
    cout<<answer;

    // cout<<isAlphabet('i');

}