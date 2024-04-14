#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};


Node* deletionAtHead(Node* &head){
    Node* currentNode = head;
    head = head->next;
    currentNode->next  = NULL;
    return currentNode;
}

void insertionAtRespectiveHead(Node* &zeroHead,Node* &oneHead,Node* &twoHead,Node* &currentNode){
    Node** currentHead = NULL;

    if(currentNode->data == 0){
        currentHead = &zeroHead;
    }
    else if(currentNode->data == 1){
        currentHead = &oneHead;
    }

    else {
        currentHead = &twoHead;
    }

    currentNode->next = *currentHead;
    *currentHead = currentNode;
}


Node* segregate(Node *head) {
    
    Node* zeroHead = NULL;
    Node* oneHead = NULL;
    Node* twoHead = NULL;
    
    Node* currentNode = NULL;
    while(head!=NULL){
        currentNode = deletionAtHead(head);
        insertionAtRespectiveHead(zeroHead, oneHead, twoHead, currentNode);
    }
    
    Node* zeroTail = zeroHead;
    while(zeroTail!=NULL && zeroTail->next!=NULL){
        zeroTail = zeroTail->next;
    }

    Node* oneTail = oneHead;
    while(oneTail!=NULL && oneTail->next!=NULL){
        oneTail = oneTail->next;
    }

    Node* twoTail = twoHead;
    while(twoTail!=NULL && twoTail->next!=NULL){
        twoTail = twoTail->next;
    }
    
    Node* nextHead = twoHead;
    
    if(oneTail!=NULL){
        oneTail->next = nextHead;
        nextHead = oneHead;
    }
    if(zeroTail!=NULL){
        zeroTail->next = nextHead;
        nextHead = zeroHead;
    }
    
    return nextHead;
}

void print(Node* &head){
    Node* current = head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}


int main(){
    Node* node_5 = new Node(0);
    Node* node_4 = new Node(0, node_5);
    Node* node_3 = new Node(0, node_4);
    Node* node_2 = new Node(0, node_3);
    Node* node_1 = new Node(0, node_2);
    
    Node* head = node_1;

    print(head);

    head = segregate(head);
    print(head);

    return 0;
}