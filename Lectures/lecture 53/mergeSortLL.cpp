#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* &head){
    ListNode* currentNode = head;
    while(currentNode!=NULL){
        cout<<currentNode->val<<" ";
        currentNode = currentNode->next;
    }
    cout<<"\n";
}

void divideInHalves(ListNode* &head, ListNode* &firstHalf, ListNode* &secondHalf){
    ListNode* fastPointer = head;
    ListNode* slowPointer = head;

    while(fastPointer->next!=NULL && fastPointer->next->next!=NULL){
        slowPointer=slowPointer->next;
        fastPointer=fastPointer->next->next;
    }
    
    firstHalf = head;
    secondHalf = slowPointer->next;
    slowPointer->next = NULL;
}

void insertAtTail(ListNode* &head, ListNode* &tail, ListNode* &node){
    if(head==NULL){
        head = node;
        tail = node;
    }

    tail->next=node;
    tail=tail->next;
}

void mergeTwoLists(ListNode* &head, ListNode* &firstHalf, ListNode* &secondHalf){
    ListNode* currentFirst = firstHalf;
    ListNode* currentSecond = secondHalf;

    head = NULL;
    ListNode* tail = head;

    while(currentFirst!=NULL && currentSecond!=NULL){
        if(currentFirst->val < currentSecond->val){
            firstHalf = currentFirst->next;
            currentFirst->next = NULL;

            insertAtTail(head, tail,currentFirst);

            currentFirst=firstHalf;
        }
        else{
            secondHalf = currentSecond->next;
            currentSecond->next = NULL;

            insertAtTail(head ,tail,currentSecond);
            
            currentSecond=secondHalf;
        }
    }

    while(currentFirst!=NULL){
        firstHalf = currentFirst->next;
        currentFirst->next = NULL;

        insertAtTail(head ,tail,currentFirst);

        currentFirst=firstHalf;
    }

    while(currentSecond!=NULL){
        secondHalf = currentSecond->next;
        currentSecond->next = NULL;

        insertAtTail(head ,tail,currentSecond);

        currentSecond=secondHalf;
    }
}

ListNode* sortList(ListNode* head) {
    if(head==NULL|| head->next==NULL){
        return head;
    }

    ListNode* firstHalf = NULL;
    ListNode* secondHalf = NULL;
    divideInHalves(head, firstHalf,secondHalf);

    firstHalf = sortList(firstHalf);
    secondHalf = sortList(secondHalf);

    mergeTwoLists(head, firstHalf, secondHalf);

    return head;
}


int main(){
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);

    ListNode* head = node1;
    ListNode* tail = head;

    insertAtTail(head ,tail, node2);
    insertAtTail(head, tail, node3);
    insertAtTail(head, tail, node4);

    head = sortList(head);

    print(head);
}