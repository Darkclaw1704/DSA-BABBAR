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


void copyLinkedList(Node* &head1, Node* &head2){
    Node* currentNode = head1;
    Node* tail2 = head2;

    if(head2 == NULL){
        head2 = new Node(currentNode->val);
        tail2 = head2;
        currentNode = currentNode->next;
    }

    while(currentNode!=NULL){
        tail2->next = new Node(currentNode->val);
        tail2 = tail2->next;
        currentNode = currentNode->next;
    }
}

void reverseLinkedList(Node* &head){
    if(head->next==NULL){
        return;
    }

    Node* previousNode = head;
    Node* currentNode = previousNode->next;
    Node* nextNode = currentNode->next;

    head->next = NULL;

    while (nextNode!=NULL)
    {
        currentNode -> next = previousNode;
        previousNode=currentNode;
        currentNode=nextNode;
        nextNode=nextNode->next;
    }
    currentNode->next = previousNode;
    head = currentNode;
}


void markRandom(Node* &head, Node* &deepCopy){
    Node* currentNodeOfOriginal = head;
    Node* currentNodeOfCopy = deepCopy;

    Node* randomNode = NULL;

    while(currentNodeOfOriginal!=NULL){ 
        randomNode = currentNodeOfOriginal->random;

        if(randomNode==NULL){
            currentNodeOfCopy->random = NULL;
            currentNodeOfOriginal = currentNodeOfOriginal->next;
            currentNodeOfCopy = currentNodeOfCopy->next;
            continue;
        }

        // cout<<currentNodeOfOriginal->val<<"\n";

        Node* traversingNodeOfOriginal = currentNodeOfOriginal;
        Node* traversingNodeOfCopy = currentNodeOfCopy;
        bool visitedRandomNode = false;

        while(traversingNodeOfOriginal!=NULL){
            if(traversingNodeOfOriginal==randomNode){
                visitedRandomNode = true;
                break;
            }
            traversingNodeOfOriginal = traversingNodeOfOriginal->next;
            traversingNodeOfCopy = traversingNodeOfCopy->next;
        }

        if(visitedRandomNode==true){
            currentNodeOfCopy->random = traversingNodeOfCopy;
        }
    
        currentNodeOfOriginal = currentNodeOfOriginal->next;
        currentNodeOfCopy = currentNodeOfCopy->next;
    }
}

Node* copyRandomList(Node* head) {
    if(head==NULL){
        return head;
    }

    Node* deepCopy = NULL;
    copyLinkedList(head, deepCopy);
    
    markRandom(head,deepCopy);

    reverseLinkedList(head);
    reverseLinkedList(deepCopy);

    markRandom(head,deepCopy);

    reverseLinkedList(head);    
    reverseLinkedList(deepCopy);

    return deepCopy;
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

    Node* copy = copyRandomList(head);

    print(head);
    printRandom(head);
    cout<<"\n\n";
    print(copy);
    printRandom(copy);
}