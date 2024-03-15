#include <iostream>
using namespace std;


struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


void splitCircularLinkedList(Node* &head, Node* &head1, Node* &head2){

    if(head==NULL || head->next==head){
        head1 = head;
        head2 = NULL;
        return;
    }


    Node* slow = head;
    Node* fast = head;

    while(fast->next->next != head && fast->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }


    head1 = head;
    head2 = slow->next;



    Node* tail1 = slow;
    Node* tail2 = NULL;

    if(fast->next->next == head){
        tail2 = fast->next;
    }
    else{
        tail2 = fast;
    }
    
    // tail1->next= head1;
    // tail2->next = head2;
    tail1->next= NULL;
    tail2->next = NULL;

}

void print(Node* &head){
    Node* current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    Node* node_6 = new Node(6);
    Node* node_5 = new Node(5, node_6);
    Node* node_4 = new Node(4, node_5);
    Node* node_3 = new Node(3, node_4);
    Node* node_2 = new Node(2, node_3);
    // Node* node_1 = new Node(1, node_2);
    // Node* head = node_1;
    Node* head = node_2;

    print(head);

    // node_6->next = node_1;
    node_6->next = node_2;

    Node* head1 = NULL;
    Node* head2 = NULL;
    splitCircularLinkedList(head, head1, head2);

    print(head1);
    print(head2);

}

