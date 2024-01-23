#include <iostream>
#include <vector>

using namespace std;


    void dialNext(string &digits, int index, string present, vector<string> &possibilities){
        if(index >= digits.length()){
            possibilities.push_back(present);
            return;
        }

        if(digits[index] == '2'){
            string present1 = present + 'a';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'b';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'c';
            dialNext(digits,index+1, present3, possibilities);
        }
        else if(digits[index] == '3'){
            string present1 = present + 'd';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'e';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'f';
            dialNext(digits,index+1, present3, possibilities);
        }
        else if(digits[index] == '4'){
            string present1 = present + 'g';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'h';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'i';
            dialNext(digits,index+1, present3, possibilities);
        }
            else if(digits[index] == '5'){
            string present1 = present + 'j';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'k';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'l';
            dialNext(digits,index+1, present3, possibilities);
        }
        else if(digits[index] == '6'){
            string present1 = present + 'm';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'n';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'o';
            dialNext(digits,index+1, present3, possibilities);
        }
        else if(digits[index] == '7'){
            string present1 = present + 'p';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'q';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'r';
            dialNext(digits,index+1, present3, possibilities);

            string present4 = present + 's';
            dialNext(digits,index+1, present4, possibilities);
        }
        else if(digits[index] == '8'){
            string present1 = present + 't';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'u';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'v';
            dialNext(digits,index+1, present3, possibilities);
        }

        else if(digits[index] == '9'){
            string present1 = present + 'w';
            dialNext(digits,index+1, present1, possibilities);

            string present2 = present + 'x';
            dialNext(digits,index+1, present2, possibilities);

            string present3 = present + 'y';
            dialNext(digits,index+1, present3, possibilities);

            string present4 = present + 'z';
            dialNext(digits,index+1, present4, possibilities);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> possibilities;
        int index = 0;
        string present = "";

        if(digits==""){
            return possibilities;
        }

        dialNext(digits, index, present ,possibilities);
        return possibilities;
    }

