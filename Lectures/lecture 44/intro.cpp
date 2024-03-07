#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head){
    Node* traverse = head;
    while(traverse != NULL){
        cout<<traverse->data<<endl;
        traverse = traverse->next;
    }
}

int main(){

    Node* head = new Node(5);
    InsertAtHead(head, 4);
    print(head);
    return 0;
}

