#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNextNode(ListNode* &currentNode){
    ListNode* nextNode = currentNode->next;

    currentNode->next = nextNode->next;
    nextNode->next = NULL;

    delete nextNode;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next ==NULL){
        return head;
    }

    ListNode* currentNode = head;
    ListNode* nextNode = currentNode->next;

    while (nextNode!=NULL){
        if(currentNode->val == nextNode->val){
            deleteNextNode(currentNode);
        }
        else{
            currentNode = nextNode;
        }

        nextNode = currentNode->next;
    }

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
    ListNode* node_5 = new ListNode(3);
    ListNode* node_4 = new ListNode(3, node_5);
    ListNode* node_3 = new ListNode(2, node_4);
    ListNode* node_2 = new ListNode(2, node_3);
    ListNode* node_1 = new ListNode(1, node_2);

    ListNode* head = node_1;

    print(head);
    deleteDuplicates(head);
    print(head);

    return 0;
}