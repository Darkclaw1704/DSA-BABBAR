#include <iostream>
#include <map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

bool checkIfLoop(Node* &head){
    map<Node*, bool> visisted;

    Node* currentNode = head;
    bool loopDetected = false;
    int position = 1;

    while(currentNode!=NULL && loopDetected==false){
        currentNode = currentNode->next;
        if(visisted[currentNode] == true){
            loopDetected = true;
        }
        else{
            visisted[currentNode]=true;
        }
    } 

    if(currentNode == NULL){
        return false;
    }

    cout<<"cycle is present where data is : "<<currentNode->val<<endl;

    return true;
}



int main(){
    Node* node_5 = new Node(5);
    Node* node_4 = new Node(4, node_5);
    Node* node_3 = new Node(3, node_4);
    Node* node_2 = new Node(2, node_3);
    Node* node_1 = new Node(1, node_2);
    node_5->next = node_3;

    Node* head = node_1;

    bool answer = checkIfLoop(head);
    cout<<"is circular : "<<answer<<endl;
    return 0;
}