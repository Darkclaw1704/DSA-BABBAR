#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *&head) {
    if(head==NULL){
        return true;
    }

    ListNode* currentNode = head->next;
    
    while(currentNode!=head && currentNode!=NULL){
        currentNode = currentNode->next;
    }

    if(currentNode== NULL){
        return false;
    }

    return true;
}

int main(){
    ListNode* node_5 = new ListNode(5);
    ListNode* node_4 = new ListNode(4, node_5);
    ListNode* node_3 = new ListNode(3, node_4);
    ListNode* node_2 = new ListNode(2, node_3);
    ListNode* node_1 = new ListNode(1, node_2);
    node_1->next = node_1;

    ListNode* head = node_1;

    bool answer = hasCycle(head);
    cout<<"is circular : "<<answer<<endl;
    return 0;
}