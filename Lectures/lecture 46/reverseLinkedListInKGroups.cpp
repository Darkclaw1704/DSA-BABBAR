#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    void reverseLinkedList(ListNode* &head, ListNode* &tail){
        if(head==NULL || head->next==NULL){
            return;
        }

        ListNode* firstNode = head;
        ListNode* secondNode = firstNode->next;

        reverseLinkedList(secondNode, tail);
        tail->next = firstNode;
        firstNode->next = NULL;

        head = secondNode;
        tail=firstNode;

        return ;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* currentNode = head;
        int length = 0;
        ListNode* previousNode = NULL;
        while(currentNode!=NULL && length<k){
            length++;
            previousNode=currentNode;
            currentNode=currentNode->next;
        }
        
        if(length<k){
            return head;
        }
        
        currentNode = previousNode;
        ListNode* nextNode = currentNode->next;
        currentNode->next=NULL;

        ListNode* tail = currentNode;
        tail->next = NULL;

        reverseLinkedList(head, tail);
        nextNode = reverseKGroup(nextNode,k);
        tail->next = nextNode;

        return head;
    }

void print(ListNode* &head){
    ListNode* current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    // ListNode* node_10 = new ListNode(10);
    // ListNode* node_9 = new ListNode(9, node_10);
    // ListNode* node_8 = new ListNode(8, node_9);
    // ListNode* node_7 = new ListNode(7, node_8);
    // ListNode* node_6 = new ListNode(6, node_7);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_4 = new ListNode(4, node_5);
    ListNode* node_3 = new ListNode(3, node_4);
    ListNode* node_2 = new ListNode(2, node_3);
    ListNode* node_1 = new ListNode(1, node_2);

    ListNode* head = node_1;
    int k = 2;

    ListNode* newHead = reverseKGroup(head,k);
    print(newHead);


}