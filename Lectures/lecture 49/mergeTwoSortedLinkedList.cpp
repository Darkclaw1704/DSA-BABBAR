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
    ListNode* current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

void print(ListNode* &head, ListNode* &tail){
    ListNode* current = head;
    while(current != tail){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<current->val<<" ";
    cout<<endl;
}


void firstSection(ListNode* &firstHead, ListNode* &firstTail, ListNode* &secondHead, ListNode* &secondTail){
    while(firstHead->next!=NULL && (firstHead->next->val <= secondHead->val)){
        firstHead=firstHead->next;
        firstTail=firstHead;
    }
}

void secondSection(ListNode* &firstHead, ListNode* &firstTail, ListNode* &secondHead, ListNode* &secondTail){
    while(secondTail->next != NULL && (secondTail->next->val < firstTail->val)) {
        secondTail = secondTail->next;
    }
}

ListNode* mergeTwoSortedLinkedList(ListNode* &head1, ListNode* &head2){
    if(head1 == NULL && head2 == NULL){
        return head1;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    ListNode* firstLinkedList = NULL;
    ListNode* secondLinkedList = NULL;

    if(head1->val <= head2->val){
        firstLinkedList =head1;
        secondLinkedList = head2;
    }
    else{
        firstLinkedList = head2;
        secondLinkedList = head1;
    }

    ListNode* firstHead = firstLinkedList;
    ListNode* firstTail = firstLinkedList;
    ListNode* secondHead = secondLinkedList;
    ListNode* secondTail = secondLinkedList;


    while(firstTail->next!=NULL && secondTail!=NULL){


        firstSection(firstHead,firstTail,secondHead,secondTail);
        if(firstHead->next!=NULL){
            firstTail = firstHead->next;
        }
        else{
            break;
        }
        secondSection(firstHead,firstTail,secondHead,secondTail);

        secondLinkedList = secondTail->next;

        firstHead->next = secondHead;
        secondTail->next = firstTail;

        firstHead = firstTail;
        secondHead= secondLinkedList;
        secondTail = secondHead;

    }

        
    if(firstTail->next ==NULL){
        firstTail->next = secondLinkedList;
    }

    return firstLinkedList;

}



int main(){
    ListNode* node_5 = new ListNode(3);
    ListNode* node_4 = new ListNode(3, node_5);

    ListNode* node_3 = new ListNode(6);
    ListNode* node_2 = new ListNode(1, node_3);
    ListNode* node_1 = new ListNode(1, node_2);

    ListNode* head1 = node_5;
    ListNode* head2 = node_3;

    print(head1);
    print(head2);

    ListNode* head = mergeTwoSortedLinkedList(head1, head2);
    print(head);

    return 0;
}