#include <iostream>
#include <map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

void print(Node* &head){
    Node* current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

void floydCycleDetection(Node* &head){
    if(head==NULL){
        return ;
    }
    Node* slow = head;
    Node* fast = head;

    bool loopDetected = false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            loopDetected = true;
            break;
        }
    }

    if(loopDetected==false){
        return;
    }

    Node* fromHead = head;
    Node* fromRondevous = slow;

    int index=0;

    while(fromHead->next != fromRondevous->next){
        fromHead = fromHead->next;
        fromRondevous = fromRondevous->next;
        index++;
    }

    fromRondevous->next = NULL;

}

int main(){
    Node* node_5 = new Node(5);
    Node* node_4 = new Node(4, node_5);
    Node* node_3 = new Node(3, node_4);
    Node* node_2 = new Node(2, node_3);
    Node* node_1 = new Node(1, node_2);
    node_5->next = node_3;

    Node* head = node_1;

    floydCycleDetection(head);
    print(head);
    return 0;
}