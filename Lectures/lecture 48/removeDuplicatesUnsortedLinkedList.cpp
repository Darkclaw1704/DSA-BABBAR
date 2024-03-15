#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

void deleteNextNode(Node* &currentNode){
    Node* nextNode = currentNode->next;

    currentNode->next = nextNode->next;
    nextNode->next = NULL;

    delete nextNode;
}

Node * removeDuplicates( Node *head) {
    if(head==NULL || head->next ==NULL){
        return head;
    }
    Node* currentNode = head;
    Node* nextNode = currentNode->next;

    bool arr[10001] = {false};
    arr[currentNode->val] = true;

    while(nextNode != NULL){
        if(arr[nextNode->val] == true){
            deleteNextNode(currentNode);
        }
        else{
            arr[nextNode->val] = true;
            currentNode = nextNode;
        }
        nextNode = currentNode -> next;
    }

    return head;
}


void print(Node* &head){
    Node* current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    Node* node_6 = new Node(2);
    Node* node_5 = new Node(5, node_6);
    Node* node_4 = new Node(1, node_5);
    Node* node_3 = new Node(2, node_4);
    Node* node_2 = new Node(5, node_3);
    Node* node_1 = new Node(1, node_2);

    Node* head = node_1;

    print(head);
    removeDuplicates(head);
    print(head);

}