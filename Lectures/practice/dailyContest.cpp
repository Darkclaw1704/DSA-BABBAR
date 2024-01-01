#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

string intToString(int n){
    stringstream ss;
    ss << n;
    string s;
    ss>>s;
    return s;
}


string recurssive(string currentString , int iteration ,int n){
    iteration ++ ;
    string nextString = "";

    int count = 1;
    char singleCharacter = currentString[0];

    for(int i = 1; i < currentString.length(); i ++){
        if ( singleCharacter == currentString [ i ]){
            count++;
        }
        else{
            nextString +=  intToString(count) + singleCharacter;
            
            count = 1;
            singleCharacter = currentString[i];
        }
    }

    nextString +=  intToString(count) + singleCharacter;

    // cout<<nextString<<endl;

    if ( iteration == n){
        return nextString;
    }

    return recurssive(nextString, iteration, n);
}

string lookAndSaySequence(int n) 
{
    if (n == 1){
        return "1";
    }
    else{
        string answer = recurssive("1",1,n);
        return answer;
    }

}



int main(){
    string answer = lookAndSaySequence(6);
    cout<<answer;
}

