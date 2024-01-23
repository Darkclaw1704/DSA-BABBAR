#include <iostream>
#include <vector>

using namespace std;


    bool inPossibilities(string &present,vector<string> &possibilities){
        for (string s : possibilities){
            if(s==present){
                return true;
            }
        }

        return false;
    }

    void solve(string &s, int index, string present, vector<string> &possibilities){
        if (index >= s.size()){

            if(!inPossibilities(present,possibilities)){
                possibilities.push_back(present);
            }
            return;
        }

        solve(s,index+1, present, possibilities);

        char include = s[index];
        present+=include;
        solve(s,index+1, present, possibilities);
    }
    
    int distinctSubseqII(string s) {
        vector<string> possibilities;
        string present;
        int index = 0;
        solve(s,index,present,possibilities);

        return possibilities.size()-1;
    }

int main(){
    string s = "pcrdhwdxmqdznbenhwjsenjhvulyve";

    int answer = distinctSubseqII(s);
    cout<<"TIME LIMIT EXCEEDED !"<<endl;
    cout<<answer<<endl;
}
