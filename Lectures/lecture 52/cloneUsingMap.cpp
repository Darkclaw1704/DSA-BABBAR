#include <iostream>
#include <map>
#include <iterator>
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

void insertAtHead(Node* &deepCopyHead,Node* &deepCopyTail, Node* &currentCopy){
    if(deepCopyHead==NULL){
        deepCopyHead = currentCopy;
        deepCopyTail = currentCopy;
        return;
    }


    deepCopyTail->next = currentCopy;
    deepCopyTail = currentCopy;
}

void cloneAndMap(Node* &head, Node* &deepCopyHead, map <Node*, Node*> &nodeCopyMap){
    Node* currentCopyTail = deepCopyHead;

    Node* currentOriginal = head;
    while(currentOriginal!=NULL){
        Node* currentCopy = new Node(currentOriginal->val);

        insertAtHead(deepCopyHead, currentCopyTail, currentCopy);
        nodeCopyMap.insert(pair <Node*, Node*> (currentOriginal, currentCopy));

        currentOriginal = currentOriginal->next;
    }

}

void pointRandomPointers(Node* &head, map <Node*, Node*> &nodeCopyMap){
    Node* currentNode = head;
    while (currentNode!=NULL){
        Node* currentCopy = nodeCopyMap.at(currentNode);

        Node* randomCopy = NULL;
        if(currentNode->random != NULL){
            randomCopy = nodeCopyMap.at(currentNode->random);
        }

        currentCopy->random = randomCopy;

        currentNode = currentNode->next;
    }
}

Node* copyRandomList(Node* head) {
    Node* deepCopyHead = NULL;
    map <Node*, Node*> nodeCopyMap ;

    cloneAndMap(head,deepCopyHead,nodeCopyMap);
    pointRandomPointers(head,nodeCopyMap);

    return deepCopyHead;
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