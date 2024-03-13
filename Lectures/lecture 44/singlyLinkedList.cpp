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

void print(Node* &head){
    Node* current = head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head, int data){
    Node* temp = new Node(data);
    Node* current = head;
    while (current->next != NULL){
        current=current->next;
    }
    current->next = temp;
}

void InsertAtMiddle(Node* &head, int index, int data){
    if(index == 0){
        InsertAtHead(head,data);
        return;
    }

    Node* temp = new Node(data);
    Node* current = head;
    int traversingIndex = 0;
    while (traversingIndex != index - 1){
        current = current->next;
        traversingIndex++;
    }
    Node* originalAtIndex = current->next;
    current->next = temp;
    temp->next = originalAtIndex;
}

void deletionAtHead(Node* &head){
    if(head == NULL){
        return;
    }

    Node* newFirstNode = head->next;
    delete head;
    head = newFirstNode;
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

    while((currentNode->next)->next != NULL){
        currentNode = currentNode->next;
    }
    Node* secondLastNode = currentNode;

    Node* lastNode = secondLastNode->next;
    secondLastNode-> next = NULL;
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
    Node* currentNode=head;

    while(currentIndex != index-1){
        currentNode = currentNode->next;
        currentIndex++;
    }

    Node* previousNode = currentNode;
    currentNode = currentNode->next;
    Node* nextNode = currentNode->next;

    previousNode->next = nextNode;
    currentNode->next = NULL;
    delete currentNode;
}

int main(){
    Node* head = NULL;
    deletionAtTail(head);
    print(head);
    return 0;
}
