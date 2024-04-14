#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
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

void reverse(Node* &head){
    if(head==NULL ||head->next ==NULL){
        return;
    }

    Node* previousNode = head;
    Node* currentNode = previousNode->next;
    Node* nextNode = currentNode->next;

    previousNode->next = NULL;

    while(nextNode!=NULL){
        currentNode->next = previousNode;

        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode -> next;
    }

    currentNode->next = previousNode;
    head = currentNode;
}

void insertAtHead(Node* &head, int data){
    Node* currentNode = new Node(data);
    currentNode -> next = head;
    head = currentNode;
}




struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    reverse(first);
    reverse(second);


    Node* currentNodeOfFirst = first;
    Node* currentNodeOfSecond = second;

    Node* addedResult = NULL;

    int carryOver = 0;
    int addition = 0;

    while(currentNodeOfFirst!=NULL && currentNodeOfSecond!=NULL){
        addition = (currentNodeOfFirst->data) + (currentNodeOfSecond->data) + carryOver;

        if(addition>=10){
            carryOver = 1;
            addition = addition - 10;
        }
        else{
            carryOver = 0;
        }

        insertAtHead(addedResult, addition);

        currentNodeOfFirst = currentNodeOfFirst -> next;
        currentNodeOfSecond = currentNodeOfSecond->next;
    }

    Node* numberLeft = NULL;
    if(currentNodeOfFirst == NULL){
        numberLeft = currentNodeOfSecond;
    }
    else{
        numberLeft = currentNodeOfFirst;
    }

    while(numberLeft!=NULL){
        addition = (numberLeft->data) + carryOver;

        if(addition >=10){
            carryOver = 1;
            addition = addition - 10;
        }else{
            carryOver = 0;
        }

        insertAtHead(addedResult,addition);

        numberLeft = numberLeft->next;
    }

    if(carryOver == 1){
        insertAtHead(addedResult,1);
    }
    
    return addedResult;

}


int main(){
    Node* first = new Node(0);
    insertAtHead(first,0);
    insertAtHead(first,0);

    Node* second = new Node(0);
    insertAtHead(second,0);

    Node* result =  addTwoLists(first,second);

    print(first);
    print(second);
    print(result);
}