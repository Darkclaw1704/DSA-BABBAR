#include <iostream>
#include <vector>
using namespace std;

// string replaceSpaces(string &str){
// 	string answer;

// 	for(int i=0; i<str.length(); i++){
// 		if(str[i]==' '){
// 			// answer+="@40";
// 			str.erase(i, 1);
// 			str.insert(i,1,'@');
// 			i++;
// 			str.insert(i,1,'4');
// 			i++;
// 			str.insert(i,1,'0');
// 			i++;
// 		}
// 		// else{
// 		// 	answer.push_back(str[i]);
// 		// }
// 	}
// 	return str;
// }


string replaceSpaces(string &str){
	string answer;

	for(int i=0; i<str.length(); i++){
		if(str[i]==' '){
			// answer+="@40";
			answer.push_back('@');
		
			answer.push_back('4');
			
			answer.push_back('0');
		}
		else{
			answer.push_back(str[i]);
		}
	}
	return answer;
}


int main(){
    string s = "the sky is blue";
    string answer = replaceSpaces(s);
    for(int i = 0; i<answer.length(); i++){
        cout<<answer[i];
    }

}