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

void insertAtHead(ListNode* &head, ListNode* &currentNode){
    currentNode->next = head;
    head = currentNode;
}

bool isPalindrome(ListNode* &head){
    if(head==NULL){
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* firstLinkedList = NULL;
    ListNode* currentNode = NULL;

    while(fast->next!=NULL && fast->next->next != NULL){
        ListNode* currentNode = slow;
        slow = slow->next;
        fast = fast->next->next;

        insertAtHead(firstLinkedList, currentNode);
    }

    ListNode* secondLinkedList = slow -> next;

    if(fast->next!=NULL && fast->next->next == NULL){
        insertAtHead(firstLinkedList, slow);
    }


    // print(firstLinkedList);
    // print(secondLinkedList);

    ListNode* firstCurrentNode = firstLinkedList;
    ListNode* secondCurrentNode = secondLinkedList;

    while((firstCurrentNode!=NULL) && (firstCurrentNode->val == secondCurrentNode->val)){
        firstCurrentNode = firstCurrentNode -> next;
        secondCurrentNode = secondCurrentNode -> next;
    }

    if(firstCurrentNode == NULL){
        return true;
    }
    return false;
}



int main(){
    ListNode* node_5 = new ListNode(3);

    ListNode* node_4 = new ListNode(3);
    ListNode* node_3 = new ListNode(3, node_4);
    ListNode* node_2 = new ListNode(4);
    ListNode* node_1 = new ListNode(3);
    ListNode* head = node_1;

    bool answer = isPalindrome(head);
    cout<<"is palindrome : "<<answer<<endl;
}