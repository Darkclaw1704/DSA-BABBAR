#include <iostream>
#include <vector>

using namespace std;

void solve(string &str, int currentChangeIndex, string present, vector<string> &possibilities){
	if(currentChangeIndex >= str.length()){
		possibilities.push_back(present);
		return;
	}

	solve(str, currentChangeIndex + 1, present, possibilities);

	char include = str[currentChangeIndex];
	present+=include;
	solve(str, currentChangeIndex + 1, present, possibilities);
}


vector<string> subsequences(string str){
	vector<string> possibilities;
	string present;

	int index = 0;

	solve(str, index, present, possibilities);

    possibilities.erase(possibilities.begin());

	return possibilities;	
	
}



int main(){
    string str = "abc";
    vector<string> answer = subsequences(str);


    for(string s : answer){
        cout<<"'"<<s<<"'";
    }cout<<endl;
}