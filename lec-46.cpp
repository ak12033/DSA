#include<iostream>
#include<map>
using namespace std;

//                          Reverse Nodes in k-Group
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
int getlength(ListNode*head,int k){

    int c = 0;
    while(head != NULL){
        head = head->next;
        c++;
    }
    return c;
}
ListNode* reverseKGroup(ListNode* head, int k) {

    if(head == NULL) {
        return NULL;
    }
    
    // Step1 : Reverse First K Nodes
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;

    int count = 0;
    while( curr != NULL && count < k ) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Step2 : Recursion dekhlega aage ka 
    if(next != NULL) {
        if(getlength(next,k)>=k){
            head->next = reverseKGroup(next, k);
        }
        else{
            head->next=next;
        }
    }
    // Step3 : Return Head of Reversed List
    return prev;
}
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    cout << "Original list: ";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}
*/

//                      Check whether Linked List is Circular or Not 
/*
class Node {

    public:
        int data;
        Node* next;

        // Constrcutor
        Node(int d) {
            this->data = d;
            this->next = NULL;
        }
        ~Node() {
            int value = this->data;
            if(this->next != NULL) {
                delete next;
                next = NULL;
            }
            cout << " memory is free for node with data " << value << endl;
        }
};
bool isCircularList(Node* head) {

    // Empty List
    if(head == NULL) {
        return true;
    }
    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }
    if(temp == head ) {
        return true;
    }
    return false;
}
int main() {

    // Example 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "Is the first list circular? " << (isCircularList(head1) ? "Yes" : "No") << endl;

    // Example 2
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(7);
    // Creating a Circular Link
    head2->next->next->next = head2; 

    cout << "Is the second list circular? " << (isCircularList(head2) ? "Yes" : "No") << endl;

    return 0;
}
*/
