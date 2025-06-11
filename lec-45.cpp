#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//                                  Reverse Linked List

//                                      Approach 1
/*
class ListNode{

    public:
        int data;
        ListNode* next;

        ListNode(int value){
        this->data = value;
        this->next = NULL;
    }
};
ListNode *reverseLinkedList(ListNode *head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedList(head); // Reverse the linked list

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
*/

//                                   Approach 2
/*
class ListNode{

    public:
        int data;
        ListNode* next;

        ListNode(int value){
        this->data = value;
        this->next = NULL;
    }
};
void reverse(ListNode* &head,ListNode* curr,ListNode* prev){

    if(curr == NULL){
        head = prev;
        return;
    }
    ListNode*forward = curr -> next;
    reverse(head,forward,curr);
    curr -> next = prev;
}
ListNode* reverseList(ListNode* head) {

    ListNode*prev = NULL;
    ListNode*curr = head;
    reverse(head,curr,prev);
    return head; 
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);  // Reverse the linked list

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
*/

//                                     Approach 3
/*
class ListNode{

    public:
        int data;
        ListNode* next;

        ListNode(int value){
        this->data = value;
        this->next = NULL;
    }
};
ListNode * reverse1(ListNode *head){

    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *chotaHead = reverse1(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
    return chotaHead; 
}
ListNode* reverseList(ListNode* head) {

    return reverse1(head);
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);  // Reverse the linked list

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
*/

//                      Reversing a Doubly Linked List
/*
class Node {

    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
void printHead(Node* head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    cout << "Doubly List by Head : ";
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printTail(Node* tail) {
    if(tail == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    cout << "Doubly List by Tail : ";
    while(tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}
void insertAtHead(Node* &head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void reverseDLL(Node* &head, Node* &tail) {
    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr = curr->next;
        if(curr == NULL) {
            tail->next = temp;
        } else {
            curr->prev->next = temp;
        }
    }

    curr = head;
    head = tail;
    tail = curr;
}
int main() {
    Node *head = new Node(1);
    Node *tail = head;

    for(int i=1; i<=5; i++) {
        insertAtTail(tail, pow(2,i));
    }

    printHead(head);
    printTail(tail);

    reverseDLL(head, tail);

    printHead(head);
    printTail(tail);

    return 0;
}
*/

//                           Middle of the Linked List

//                                  Approach 1
/*
class ListNode {

    public:
        int data;
        ListNode* next;

        ListNode(int value) {
            data = value;
            next = NULL;
        }
};
ListNode* middleNode(ListNode* head) {
        
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
void printList(ListNode* head) {

    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    ListNode* middle = middleNode(head);  // Find the middle node

    cout << "Middle Node: " << middle->data << endl;

    return 0;
}
*/

//                                  Approach 2
/*
class ListNode {

    public:
        int data;
        ListNode* next;

        ListNode(int value) {
            data = value;
            next = NULL;
        }
};
int getLength(ListNode* head){

    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
ListNode *middleNode(ListNode *head) {

    int len = getLength(head);
    int ans = (len/2);
    
    int cnt = 0;
    ListNode* temp = head;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
void printList(ListNode* head) {

    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original List: ";
    printList(head);

    ListNode* middle = middleNode(head);  // Find the middle node

    cout << "Middle Node: " << middle->data << endl;

    return 0;
}
*/