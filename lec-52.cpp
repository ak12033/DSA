#include<iostream>
#include<unordered_map>
using namespace std;

//                          Clone List with Next and Random

//                                    Approach 1
/*
class Node {

    public:
        int data;
        Node* next;
        Node* random;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};
void insertAtTail(Node* &head, Node* &tail, int d) {

    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}
Node *copyList(Node *head){

    // Step 1 : Create a Clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    } 
    // Step 2 : Create a Map
    unordered_map<Node*, Node*> OldtoNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;    
    while(originalNode != NULL && cloneNode != NULL) {
        OldtoNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    // Step 3 : Copying Random Pointers
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL){
        cloneNode -> random = OldtoNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    return cloneHead;
}
void printList(Node* head) {

    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    while(head != NULL) {
        if (head->next != NULL){
            cout << "[" << head->data << "," << head->next->data << "] ";
        }
        if (head->random != NULL){
            cout << "[" << head->data << "," << head->random->data << "] ";
        }
        head = head -> next;
    }
    cout << endl;
}
int main() {

    Node *first = new Node(1);
    Node *head = first;
    Node *tail = first;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original List : ";
    printList(head);

    Node *clone = copyList(head);

    cout << "Clone List    : ";
    printList(clone);

    return 0;
}
*/

//                                    Approach 2
/*
class Node {

    public:
        int data;
        Node* next;
        Node* random;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};
void insertAtTail(Node* &head, Node* &tail, int d) {

    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}
Node *copyList(Node *head){

    // Step 1 : Create a Clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    } 
    // Step 2 : Add CloneNodes in between Original List
    Node* originalNode = head;
    Node* cloneNode = cloneHead;    
    while(originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }
    // Step 3 : Copying Random Pointers
    temp = head;
    while(temp != NULL){
        if (temp->next != NULL) {
            temp->next->random = temp->random
            ? temp->random->next : temp->random;
        }
        temp = temp -> next -> next;
    }
    // Step 4 : Revert changes done in step 2
    originalNode = head;
    cloneNode = cloneHead;    
    while(originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        if(originalNode->next != NULL){
            originalNode = originalNode->next;
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    // Step 5 : Return Ans
    return cloneHead;
}
void printList(Node* head) {

    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    while(head != NULL) {
        if (head->next != NULL){
            cout << "[" << head->data << "," << head->next->data << "] ";
        }
        if (head->random != NULL){
            cout << "[" << head->data << "," << head->random->data << "] ";
        }
        head = head -> next;
    }
    cout << endl;
}
int main() {

    Node *first = new Node(1);
    Node *head = first;
    Node *tail = first;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original List : ";
    printList(head);

    Node *clone = copyList(head);

    cout << "Clone List    : ";
    printList(clone);

    return 0;
}
*/
