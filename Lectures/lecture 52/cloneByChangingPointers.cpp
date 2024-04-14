#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


void print(Node* head){
    Node* currentNode = head;

    while(currentNode!=NULL){
        cout<<currentNode->val<<" ";
        currentNode = currentNode->next;
    }
    cout<<"\n";
}

void printRandom(Node* head){
    Node* currentNode = head;

    while(currentNode!=NULL){
        if(currentNode->random == NULL){
            cout<<"NULL"<<" ";
        }
        else{
            cout<<currentNode->random->val<<" ";
        }
        currentNode = currentNode->next;
    }
    cout<<"\n";
}


void pointNextOfOriginalToCopy(Node* &head, Node* &copyHead){
    copyHead = head;

    Node* currentOriginal = head;
    while(currentOriginal!=NULL){
        Node* currentCopy = new Node(currentOriginal->val);

        currentCopy->next = currentOriginal->next;
        currentOriginal->next = currentCopy;

        currentOriginal = currentCopy->next;
    }
}

void pointRandomOfCopy(Node* &head, Node* &copyHead){
    Node* currentOriginal = head;
    while(currentOriginal!=NULL){
        if(currentOriginal->random==NULL){
            currentOriginal->next->random = NULL;  
        }
        else{
            currentOriginal->next->random = currentOriginal->random->next;  
        }
        
        currentOriginal = currentOriginal->next->next;
    }
}

void pointNextOfOrignalAndCopy(Node* &head, Node* &copyHead){
    copyHead = head->next;

    Node* previousOriginal = head;
    Node* previousCopy = head->next;

    Node* currentOriginal = previousCopy->next;
    Node* currentCopy = currentOriginal->next;

    Node* nextOriginal = NULL;
    Node* nextCopy = NULL;
    if(currentCopy->next!=NULL){
        nextOriginal = currentCopy->next;
        nextCopy = nextOriginal->next;
    }
    
    while(currentOriginal!=NULL){
        previousOriginal->next = currentOriginal;
        previousCopy-> next = currentCopy;

        previousOriginal = currentOriginal;
        previousCopy = currentCopy;

        currentOriginal = nextOriginal;
        currentCopy = nextCopy;

        nextOriginal = NULL;
        nextCopy = NULL;
        if(currentCopy!=NULL && currentCopy->next!=NULL){
            nextOriginal = currentCopy->next;
            nextCopy = nextOriginal->next;
        }
    }

    previousOriginal->next = currentOriginal;
    previousOriginal->next = currentCopy;
}


Node* copyRandomList(Node* head) {
    Node* copyHead = NULL;

    if(head==NULL){
        return copyHead;
    }

    if(head->next == NULL){
        copyHead = new Node(head->val);
        
        if(head->random!=NULL){
            copyHead->random=copyHead;
        }
        
        return copyHead;
    }


    pointNextOfOriginalToCopy(head,copyHead);
    pointRandomOfCopy(head, copyHead);
    pointNextOfOrignalAndCopy(head,copyHead);

    return copyHead;
}

int main(){
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node1->random = NULL;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    Node* head = node1;

    print(head);
    printRandom(head);
    cout<<"\n\n";

    Node* copy = copyRandomList(head);

    print(head);
    printRandom(head);
    cout<<"\n\n";
    print(copy);
    printRandom(copy);

}