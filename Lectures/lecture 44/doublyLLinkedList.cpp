#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* previous;
    Node* next;

    Node(int data){
        this -> data = data;
        this-> previous = NULL;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

void print(Node* &head){
    Node* currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->data<<" ";
        currentNode = currentNode->next;
    }
    cout<<endl;
}

void InsertAtTail(Node* &head, int data){
    Node* newLastNode = new Node(data);
    
    Node* currentNode = head;
    while(currentNode-> next != NULL){
        currentNode = currentNode ->next;
    }
    Node* originalLastNode = currentNode;

    originalLastNode->next = newLastNode;
    newLastNode -> previous = originalLastNode;
}

void InsertAtMiddle(Node* &head, int index ,int data){
    if(index == 0){
        InsertAtHead(head,data);
        return;
    }


    Node* newNode = new Node(data);

    int currentIndex = 0;
    Node* currentNode = head;
    while(currentIndex != index - 1){
        currentNode = currentNode ->next;
        currentIndex++;
    }
    Node* previousNode = currentNode;

    Node* nextNode = previousNode-> next;
    if(nextNode == NULL){
        InsertAtTail(head,data);
        return;
    }

    cout<<"previous node data : "<<previousNode->data<<endl;
    cout<<"new node data : "<<newNode->data<<endl;
    cout<<"next node data : "<<nextNode->data<<endl;

    previousNode->next = newNode;
    newNode->next = nextNode;

    nextNode->previous = newNode;
    newNode->previous = previousNode;
}

void deletionAtHead(Node* &head){
    if(head == NULL){
        return;
    }

    Node* firstNode = head;
    Node* secondNode = firstNode->next;

    firstNode -> next = NULL;
    
    if(secondNode != NULL){
        secondNode ->previous = NULL;
    }

    head = secondNode;
    delete firstNode;
}

void deletionAtTail(Node* &head){
    if(head == NULL){
        return;
    }

    Node* currentNode = head;

    if(currentNode->next == NULL){
        head = NULL;
        delete currentNode;
        return;
    }

    while(currentNode->next->next!= NULL){
        currentNode = currentNode->next;
    }
    Node* secondLastNode = currentNode;
    Node* lastNode = secondLastNode -> next;

    secondLastNode->next = NULL;
    lastNode -> previous = NULL;
    delete lastNode;
}

void deletionAtMiddle(Node* &head, int index){
    if(head == NULL){
        return;
    }

    if(index == 0){
        deletionAtHead(head);
        return;
    }

    int currentIndex = 0;
    Node* currentNode = head;
    while(currentIndex != index){
        currentIndex++;
        currentNode = currentNode->next;
    }

    Node* previousNode = currentNode->previous;
    Node* nextNode = currentNode -> next;

    if(nextNode == NULL){
        deletionAtTail(head);
        return;
    }

    previousNode->next = nextNode;
    nextNode->previous = previousNode;

    currentNode->previous = NULL;
    currentNode->next = NULL;
    delete currentNode;
}

int main(){
    Node* head = new Node(1);
    deletionAtHead(head);
    print(head);

}