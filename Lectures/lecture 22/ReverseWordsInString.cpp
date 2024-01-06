#include <iostream>
using namespace std;

bool isSpace(char ch){
    if (ch==' '){
        return true;
    }
    return false;
}


string reverseWords(string s) {
    
    int i = s.length()-1;
    int j;
    bool wasThereAWwordBeforeThis = false;

    string answer;

    while (isSpace(s[i]))
    {
        i--;
    }
    // cout<<"starting letter at : "<<i<<endl;
    

    while (i >= 0)
    {


        if (!isSpace(s[i])){
            i--;
            continue;
        }
        else{

            if (wasThereAWwordBeforeThis){
                answer.push_back(' ');
            }

            j = i+1;

            while ((!isSpace(s[j])) && (j<s.length()))
            {
                answer.push_back(s[j]);
                j++;
            }
            
            wasThereAWwordBeforeThis = true;

            while ((isSpace(s[i])) && (i >= 0))
            {
                i--;
            }

        }

    }
    
    if (wasThereAWwordBeforeThis){
        answer.push_back(' ');
    }

    j = i+1;
    while (!isSpace(s[j]))
    {
        answer.push_back(s[j]);
        j++;
    }
    // answer.push_back(' ');

    return answer;
    

}

int main(){
    string s = "a good  example";

    string answer = reverseWords(s);

    // cout<<"-------------"<<endl;

    cout<<'"';
    for(char i : answer){
        cout<<i;
    }cout<<'"';
}